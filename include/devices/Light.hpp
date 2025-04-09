#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"
#include <string>

class Light : public Device {
    private:
        std::string m_id;
        bool m_isOn = false;
        int m_brightness = 0; // 0-100
    public:
        Light(const std::string& id);
        void update() override;
        std::string getId() const override;
        std::string getStatus() const override;
};

#endif