#pragma once
#include "esphome/core/component.h"
#include "esphome/core/hal.h"
#include "esphome/core/defines.h"
#include "esphome/core/preferences.h"
#include "esphome/components/climate/climate.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/switch/switch.h"
#include "FujiHeatPump.h"

namespace esphome {
namespace fujitsu {

static const char* TAG = "FujitsuClimate";

class FujitsuClimate : public climate::Climate, public Component {
   public:
    void setup() override;
    void loop() override;
    void control(const climate::ClimateCall &call) override;
    void dump_config() override;
    climate::ClimateTraits traits() override;
    FujiHeatPump heatPump;
    FujiFrame sharedState;

    void set_master(bool is_master) { this->is_master_ = is_master; }
    void set_tx_pin(InternalGPIOPin *tx_pin) { this->tx_pin_ = tx_pin; }
    void set_rx_pin(InternalGPIOPin *rx_pin) { this->rx_pin_ = rx_pin; }
    void set_remote_temperature(sensor::Sensor *sensor) { this->remote_temperature_ = sensor; }
    void set_comms_enable_switch(switch_::Switch *sw) { this->comms_enable_switch_ = sw; }


   protected:
    bool is_master_;
    InternalGPIOPin *tx_pin_;
    InternalGPIOPin *rx_pin_;
    sensor::Sensor *remote_temperature_{nullptr};
    switch_::Switch *comms_enable_switch_{nullptr};


    void updateState();
    optional<climate::ClimateMode> fujiToEspMode(FujiMode fujiMode);
    optional<FujiMode> espToFujiMode(climate::ClimateMode espMode);
    
    optional<climate::ClimateFanMode> fujiToEspFanMode(FujiFanMode fujiFanMode);
    optional<FujiFanMode> espToFujiFanMode(climate::ClimateFanMode espFanMode);
};

}  // namespace fujitsu
}  // namespace esphome
