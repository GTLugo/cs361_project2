#pragma once

#include "util/dice.hpp"

#include "vehicle.hpp"

namespace gtl {
  class Simulation {
  public:
    Simulation() = default;
    ~Simulation() = default;
    
    void run();
  private:
    bool shouldStop_{false};
    fge::Time time_{1.};
    u32 timeStep_{1};
    u32 maxTimeStep_{5};

    // Sim specific
    float avgVehicles_{3};
    float stdDevVehicles_{1};

    std::priority_queue<Vehicle> vehicleQueue_{};

    void generateVehicles(i32 count);

    void fixedUpdateLoop(const std::function<void()>& action);
  };
}