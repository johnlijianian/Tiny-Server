#include "Timer.h"

void Timer::restart(Timestamp now)
{
  if (repeat_)
  {
    // 重新计算下一个超时时刻
    expiration_ = addTime(now, interval_);
  }
  else
  {
    expiration_ = Timestamp::invalid();
  }
}