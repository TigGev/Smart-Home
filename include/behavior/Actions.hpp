#ifndef ACTION_HPP
#define ACTION_HPP
#include <memory>

class Device;

class Action {
public:
    virtual ~Action() = default;
    virtual void execute(std::shared_ptr<Device> device) = 0;
};

class InstantAction : public Action {
    private:
        bool m_turnOn;
    public:
        InstantAction(bool turnOn);
        void execute(std::shared_ptr<Device> device) override;
    
};

class GradualAction : public Action {
    private:
        int m_targetValue;
    public:
        GradualAction(int targetValue);
        void execute(std::shared_ptr<Device> device) override;
    
};

#endif