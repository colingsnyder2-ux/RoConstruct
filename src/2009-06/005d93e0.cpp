// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
namespace RBX {
class Time {
public:
    double sec;
    static Time now();
};
class Timer {
    int state;
    double deadline;
public:
    Timer();
};
Timer::Timer() : state(0), deadline(Time::now().sec + 4.0) {}
}
