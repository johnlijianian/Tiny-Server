#pragma once
#include <string>
// struct timespec {
//     time_t tv_sec;                /* Seconds */
//     long   tv_nsec;               /* Nanoseconds */
// };

// struct itimerspec {
//     struct timespec it_interval;  /* Interval for periodic timer */
//     struct timespec it_value;     /* Initial expiration */
// };

class Timestamp{
    public:
        Timestamp(): microSecondsSinceEpoch_(0){}

        explicit Timestamp(int microSecondsSinceEpoch); // explicit的可以理解为：不接受隐式转换
                                                            // 只需要带参数的构造函数
        int microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }

        bool valid() const { return microSecondsSinceEpoch_ > 0; }

        static Timestamp now();
        static Timestamp invalid();

        time_t secondsSinceEpoch() const       //对时间进行一个动态转换
            { return static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond); }

        static const int kMicroSecondsPerSecond = 1000 * 1000;

        std::string toString();

        std::string toFormattedString();

    private:
        int microSecondsSinceEpoch_;
};

inline bool operator<(Timestamp lhs, Timestamp rhs)
{  return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();}

inline bool operator==(Timestamp lhs, Timestamp rhs)
{  return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();}

inline double timeDifference(Timestamp high, Timestamp low)
{
  int diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
  return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
}

inline Timestamp addTime(Timestamp timestamp, double seconds)
{
  int delta = static_cast<int>(seconds * Timestamp::kMicroSecondsPerSecond);
  return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}