// ------------------------------------------------------------------------------------------------
// time/rtc.h
// ------------------------------------------------------------------------------------------------

#pragma once

#include "time/time.h"

// ------------------------------------------------------------------------------------------------
void RtcGetTime(DateTime *dt);
void RtcSetTime(const DateTime *dt);