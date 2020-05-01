#include "../h/Scheme.h"

namespace mathkeklib {

    void Scheme::SetStepsCount(int length_steps, int time_steps) {
        assert(length_steps > 0 && time_steps > 0 && "Number of steps should be positive");
        time_steps_count_ = time_steps;
        time_step_ = time_limit_ / time_steps;
        length_steps_count_ = length_steps;
        length_step_ = length_limit_ / length_steps;
    }

    void Scheme::SetLimits(double length_limit, double time_limit) {
        assert(length_limit > 0 && time_limit > 0 && "Limits should be positive");
        time_limit_ = time_limit;
        length_limit_ = length_limit;
        SetStepsCount(length_steps_count_, time_steps_count_);
    }

    void Scheme::SetSpeed(double speed) {
        assert(speed >= 0 && "Usually speed is not negative, so...");
        speed_ = speed;
    }

}