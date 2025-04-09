#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include <string>
#include <memory>

class Device;

class Scheduler {
public:
    virtual ~Scheduler() = default;
    virtual bool shouldAct(std::shared_ptr<Device> device) const = 0;
};


class TimeScheduler : public Scheduler {
    private:
        std::string m_scheduledTime;
    public:
        TimeScheduler(const std::string& time); // "07:00" 
        bool shouldAct(std::shared_ptr<Device> device) const override;

};

class MotionScheduler : public Scheduler {
    public:
        MotionScheduler();
        bool shouldAct(std::shared_ptr<Device> device) const override;
};

#endif