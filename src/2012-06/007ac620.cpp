// from server: 89% by tajop
struct PropDesc {
    int dummy;
};

extern PropDesc desc_TimeOfDay;

struct TimeDuration {
    __int64 ticks;
};

struct LightingParameters {
    void setTime(double t);
};

struct LightingSignal {
    void operator()(bool skyboxChanged);
};

struct Lighting {
    char pad0[0x88];
    LightingParameters skyParameters;
    char pad1[0x1c0 - 0x89];
    __int64 timeOfDay;
    char pad2[0x1f0 - 0x1c8];
    LightingSignal lightingChangedSignal;

    void raisePropertyChanged(const PropDesc& desc);
    void setTimeOfDay(const TimeDuration& value);
};

void Lighting::setTimeOfDay(const TimeDuration& value)
{
    int s = (int)(value.ticks / 1000000);
    s = s % 86400;
    if ((int)(timeOfDay / 1000000) != s)
    {
        __int64 t;
        if (s >= 0)
            t = (__int64)s * 1000000;
        else
            t = (__int64)(-s) * -1000000;
        timeOfDay = t;
        skyParameters.setTime((double)(int)(t / 1000000));
        raisePropertyChanged(desc_TimeOfDay);
        lightingChangedSignal(false);
    }
}
