// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void* PDH_HCOUNTER;
typedef struct _PDH_FMT_COUNTERVALUE {
    unsigned long CStatus;
    union {
        long longValue;
        double doubleValue;
        __int64 largeValue;
        const char* AnsiStringValue;
        const wchar_t* WideStringValue;
    };
} PDH_FMT_COUNTERVALUE;
extern "C" long __stdcall PdhGetFormattedCounterValue(PDH_HCOUNTER, unsigned long, unsigned long*, PDH_FMT_COUNTERVALUE*);
#define PDH_FMT_DOUBLE 0x00000200
static inline void getCounterValue(PDH_HCOUNTER counter, double* value)
{
    PDH_FMT_COUNTERVALUE v = { 0 };
    PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, 0, &v);
    *value = v.doubleValue;
}
class CProcessPerfCounter {
public:
    void* vptr_;
    unsigned int numCores;
    char pad[0x28];
    PDH_HCOUNTER counterA;
    PDH_HCOUNTER counterB;
    double GetProcessCores();
};
double CProcessPerfCounter::GetProcessCores()
{
    double a;
    getCounterValue(counterA, &a);
    double b;
    getCounterValue(counterB, &b);
    return numCores * b * a * 0.0001;
}
