#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

#include "Device.hpp"
#include <string>

class Thermostat : public Device {
    private:
        std::string m_id;
        float m_temperature = 20.0f; // Celsius
    public:
        Thermostat(const std::string& id);
        void update() override;
        std::string getId() const override;
        std::string getStatus() const override;
};

#endif