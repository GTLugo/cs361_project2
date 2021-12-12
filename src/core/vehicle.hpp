//
// Created by galex on 12/11/2021.
//

#pragma once

namespace gtl {
  class Vehicle {
  public:
    enum Type {
      AV1, AV2, AV3,
      APC,
      S1, S2, S3, S4,
    };

    explicit Vehicle(Type type, u32 priority, bool repairable = true)
        : type_{type}, priority_{priority}, repairable_{repairable} {}

    explicit Vehicle()
        : Vehicle{generateType(), 0, Dice::flip()} {}

    [[nodiscard]] u32 priority() const { return priority_; }

    auto operator<=>(const Vehicle&) const = default;
    bool operator<(const Vehicle& rhs) const { return priority() < rhs.priority(); }

  private:
    Type type_;
    bool repairable_;
    u32 priority_;

    static Type generateType() {
      switch (Dice::rollInt(0, 7)) {
        case 0: return AV1;
        case 1: return AV2;
        case 2: return AV3;
        case 3: return APC;
        case 4: return S1;
        case 5: return S2;
        case 6: return S3;
        case 7: return S4;
        default: throw std::range_error("Invalid vehicle type!");
      }
    }
  };
}