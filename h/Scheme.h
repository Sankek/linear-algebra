#ifndef SCHEME_H
#define SCHEME_H

#include <cassert>
#include <vector>

namespace mathkeklib {

    class Scheme {
    private:
        double time_step_{0.01};
        int time_steps_count_{100};
        int current_time_step_{};
        double time_limit_{1};

        double length_step_{0.01};
        int length_steps_count_{100};
        double length_limit_{1};

        double speed_{1};
    public:
        Scheme(int length_steps, int time_steps) {
            SetStepsCount(length_steps, time_steps);
        }
        Scheme() = default;

        void SetStepsCount(int length_steps, int time_steps);
        void SetLimits(double length_limit, double time_limit);

        int GetLengthStepsCount() { return length_steps_count_; }
        double GetLengthStep() { return length_step_; }
        double GetLengthLimit() { return length_limit_; }

        int GetTimeStepsCount() { return time_steps_count_; }
        int& CurrentTimeStep() { return current_time_step_; }
        double GetTimeStep() {return time_step_;}
        double GetTimeLimit() {return time_limit_;}

        void SetSpeed(double speed);
        double GetSpeed() {return speed_;}

        bool CourantCondition() {return speed_ * time_step_ / length_step_ < 1;}
    };

}

#endif
