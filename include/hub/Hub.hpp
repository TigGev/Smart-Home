#ifndef HUB_HPP
#define HUB_HPP

#include "Device.hpp"
#include "../logger/Logger.hpp"
#include <memory>
#include <vector>
#include <string>

class Hub {
    private:
        std::vector<std::shared_ptr<Device>> devices_;
        std::shared_ptr<Logger> logger_;
    public:
        Hub(std::shared_ptr<Logger> logger);
        void registerDevice(std::shared_ptr<Device> device);
        void sendCommand(const std::string& command);
        void notify(const std::string& event);
};

#endif