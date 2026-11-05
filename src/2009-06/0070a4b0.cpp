// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void* PDH_HQUERY;
extern "C" long __stdcall PdhOpenQueryA(const char* src, unsigned long user, PDH_HQUERY* q);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();
struct Query {
    PDH_HQUERY h;
    Query() : h(0) { PdhOpenQueryA(0, 0, &h); }
    ~Query();
};
class ProcessCounters {
public:
    ProcessCounters();
private:
    void init(unsigned long pid);
    Query query;
};
ProcessCounters::ProcessCounters()
{
    init(GetCurrentProcessId());
}
