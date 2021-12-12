//
// Created by galex on 12/11/2021.
//

#pragma once

namespace gtl {
  class Dice {
  public:
    [[nodiscard]] static bool flip() {
      return rollInt(0, 1);
    }

    [[nodiscard]] static i32 rollInt(i32 lowerIncl, i32 upperIncl) {
      std::uniform_int_distribution<i32> dist{lowerIncl, upperIncl};
      return dist(randomDevice());
    }

    [[nodiscard]] static float rollNormal(float mean, float stddev) {
      std::normal_distribution<float> dist{mean, stddev};
      return dist(randomDevice());
    }

    [[nodiscard]] static i32 rollNormalInt(float mean, float stddev) {
      std::normal_distribution<float> dist{mean, stddev};
      return static_cast<i32>(std::floor(dist(randomDevice())));
    }

    [[nodiscard]] static float rollNormalBetween(float mean, float stddev, float lowerIncl, float upperIncl) {
      return std::clamp(rollNormal(mean, stddev), lowerIncl, upperIncl);
    }

    [[nodiscard]] static i32 rollNormalIntBetween(float mean, float stddev, i32 lowerIncl, i32 upperIncl) {
      return std::clamp(rollNormalInt(mean, stddev), lowerIncl, upperIncl);
    }

  private:
    static std::random_device& randomDevice() {
      static std::random_device device;
      return device;
    }
  };
}