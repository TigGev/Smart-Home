#ifndef MOTIONSENSOR_HPP
#define MOTIONSENSOR_HPP

#include "Device.hpp"
#include <string>

class MotionSensor : public Device {
    private:
        std::string m_id;
        bool m_motionDetected = false;
    public:
        MotionSensor(const std::string& id);
        void update() override;
        std::string getId() const override;
        std::string getStatus() const override;
};

#endif