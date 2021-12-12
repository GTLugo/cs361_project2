#include "simulation.hpp"

namespace gtl {

  void Simulation::run() {
    std::cout << "Simulation started... max timesteps: " << maxTimeStep_ << '\n';

    fixedUpdateLoop([&]{
      std::cout << "-----------------------------\n";
      std::cout << "Day " << timeStep_ << ":\n";

      i32 vehicleCount{Dice::rollNormalIntBetween(avgVehicles_, stdDevVehicles_, 0, 8)};
      generateVehicles(vehicleCount);

      std::cout << "Q size: " << vehicleQueue_.size() << "\n";
    });

    std::cout << "-----------------------------\n";
    std::cout << "Simulation complete!\n";
  }

  void Simulation::generateVehicles(i32 count) {
    for (i32 i = 0; i < count; ++i) {
      vehicleQueue_.emplace();
    }
  }
  
  void Simulation::fixedUpdateLoop(const std::function<void()>& action) {
    while (!shouldStop_) {
      while (time_.shouldDoTick()) {
        if (timeStep_ <= maxTimeStep_) {
          action();

          ++timeStep_;
        } else {
          shouldStop_ = true;
        }
        time_.tick();
      }
      time_.update();
    }
  }
}