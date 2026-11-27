// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

struct int_adapter { __int64 value_; __int64 as_number() const { return value_; } };
struct traits { static __int64 as_number(int_adapter i) { return i.as_number(); } static __int64 res_adjust() { return 1000000; } };
struct time_duration {
    int_adapter ticks_;
    __int64 ticks() const { return traits::as_number(ticks_); }
    static __int64 ticks_per_second() { return traits::res_adjust(); }
    __int64 total_milliseconds() const {
        if (ticks_per_second() < 1000) return ticks() * (static_cast<__int64>(1000) / ticks_per_second());
        return ticks() / (ticks_per_second() / static_cast<__int64>(1000));
    }
};
struct Lighting
{
    char pad[0x1c0];
    time_duration timeOfDay;
    double getMinutesAfterMidnight();
};
double Lighting::getMinutesAfterMidnight()
{
    return timeOfDay.total_milliseconds() / 60000.0;
}
