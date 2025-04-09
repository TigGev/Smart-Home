#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <memory>
#include <string>

class Hub;
class Scheduler;
class Action;

class Device {
    protected:
        std::shared_ptr<Hub> m_hub;
        std::shared_ptr<Scheduler> m_scheduler;
        std::shared_ptr<Action> m_action;
    public:
        virtual ~Device() = default;
        virtual void update() = 0;
        virtual std::string getId() const = 0;
        virtual std::string getStatus() const = 0;
    
        void setScheduler(std::shared_ptr<Scheduler> scheduler);
        void setAction(std::shared_ptr<Action> action);
        void setHub(std::shared_ptr<Hub> hub);
};

#endif 