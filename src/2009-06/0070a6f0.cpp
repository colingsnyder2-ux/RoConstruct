// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
union LARGE_INTEGER_ { struct { unsigned long LowPart; long HighPart; }; __int64 QuadPart; };
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(LARGE_INTEGER_*);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(LARGE_INTEGER_*);

class Time {
public:
    double sec;
    Time() : sec(0) {}
    explicit Time(double s) : sec(s) {}
    static Time nowPrecise();
};

static __int64 startCount;

Time Time::nowPrecise()
{
    Time result;
    LARGE_INTEGER_ t;
    QueryPerformanceCounter(&t);
    __int64 elapsed = t.QuadPart - startCount;
    LARGE_INTEGER_ f;
    QueryPerformanceFrequency(&f);
    result.sec = (double)elapsed / (double)f.QuadPart;
    return result;
}
