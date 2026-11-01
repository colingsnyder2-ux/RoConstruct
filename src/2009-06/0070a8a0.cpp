// from server: 100% by EspClaude
// roc 2009-06 0070a8a0  size: 71 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile*, long);

class Time {
public:
    double sec;
    Time() : sec(0) {}
    explicit Time(double s) : sec(s) {}
    static Time now();
    static Time nowPrecise();
};

extern int timerMode;
static long timerInitialized;
static double lastTime;
void initTimer();

Time Time::now()
{
    if (timerMode <= 0)
        return nowPrecise();
    if (timerInitialized == 0 && InterlockedExchange(&timerInitialized, 1) == 0)
        initTimer();
    return Time(lastTime);
}
