// from server: 100% by EspClaude
// 2009 RBX::Lighting::setTime (self-contained)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost { namespace posix_time {
class time_duration {
public:
    struct int_adapter { __int64 value_; int_adapter(__int64 v) : value_(v) {} __int64 as_number() const { return value_; } };
    int_adapter ticks_;
    time_duration(__int64 t) : ticks_(t) {}
    static __int64 res_adjust() { return 1000000; }
    static __int64 ticks_per_second() { return res_adjust(); }
    int_adapter ticks() const { return ticks_; }
    int total_seconds() const { return static_cast<int>(ticks().as_number() / ticks_per_second()); }
    static __int64 to_tick_count(int s)
    {
        int h = 0, m = 0, fs = 0;
        if (h < 0 || m < 0 || s < 0 || fs < 0) {
            h = h < 0 ? -h : h; m = m < 0 ? -m : m; s = s < 0 ? -s : s; fs = fs < 0 ? -fs : fs;
            return (((((__int64)h * 3600) + ((__int64)m * 60) + s) * res_adjust()) + fs) * -1;
        }
        return ((((__int64)h * 3600) + ((__int64)m * 60) + s) * res_adjust()) + fs;
    }
};
class seconds : public time_duration { public: explicit seconds(int s) : time_duration(to_tick_count(s)) {} };
} }
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
struct SkyParameters { void setTime(double t); };
void lightingChangedHelper();
struct FireArg { void (*f)(); bool b; };
struct ChangedSignal { void operator()(FireArg a); };
class Lighting {
public:
    char pad0[0x90];
    SkyParameters skyParameters;
    char pad1[0x1c8 - 0x91];
    boost::posix_time::time_duration timeOfDay;
    char pad2[0x234 - 0x1d0];
    ChangedSignal* lightingChanged;
    static Reflection::PropertyDescriptor prop_Time;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    void fireLightingChanged(bool b)
    {
        FireArg a = { &lightingChangedHelper, b };
        if (lightingChanged)
            (*lightingChanged)(a);
    }
    void setTime(const boost::posix_time::time_duration& value);
};
void Lighting::setTime(const boost::posix_time::time_duration& value)
{
    int totalSeconds = value.total_seconds();
    totalSeconds -= (totalSeconds / 86400) * 86400;
    if (timeOfDay.total_seconds() != totalSeconds)
    {
        timeOfDay = boost::posix_time::seconds(totalSeconds);
        skyParameters.setTime(timeOfDay.total_seconds());
        raisePropertyChanged(prop_Time);
        fireLightingChanged(false);
    }
}
}
