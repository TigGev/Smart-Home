#ifndef DOORLOCK_HPP
#define DOORLOCK_HPP

#include "Device.hpp"
#include <string>

class DoorLock : public Device {
    private:
        std::string m_id;
        bool m_isLocked = false;
    public:
        DoorLock(const std::string& id);
        void update() override;
        std::string getId() const override;
        std::string getStatus() const override;
};

#endif