// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
struct int_adapter {
    __int64 value_;
    int_adapter(__int64 v) : value_(v) {}
    __int64 as_number() const { return value_; }
};
struct time_duration {
    int_adapter ticks_;
    time_duration(const time_duration& o) : ticks_(o.ticks_) {}
    __int64 ticks() const { return ticks_.as_number(); }
    __int64 total_milliseconds() const { return ticks() / 1000; }
};
class Lighting {
    char pad[0x1c8];
    time_duration timeOfDay;
public:
    time_duration getTimeOfDay() const { return timeOfDay; }
    double getMinutesAfterMidnight();
};
double Lighting::getMinutesAfterMidnight()
{
    return getTimeOfDay().total_milliseconds() / 60000.0;
}
}
