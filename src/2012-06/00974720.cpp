// from server: 100% by Xemicl
// roc 2012-06 00974720  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00974720
//
// 00974720  83ec24               sub esp, 0x24
// 00974723  33c0                 xor eax, eax
// 00974725  56                   push esi
// 00974726  89442420             mov dword ptr [esp + 0x20], eax
// 0097472a  89442424             mov dword ptr [esp + 0x24], eax
// 0097472e  8d442418             lea eax, [esp + 0x18]
// 00974732  50                   push eax
// 00974733  6a00                 push 0
// 00974735  8bf1                 mov esi, ecx
// 00974737  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 0097473a  6800020000           push 0x200
// 0097473f  51                   push ecx
// 00974740  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00974748  e8930a1200           call 0xa951e0
// 0097474d  33c0                 xor eax, eax
// 0097474f  8d542408             lea edx, [esp + 8]
// 00974753  52                   push edx
// 00974754  50                   push eax
// 00974755  89442418             mov dword ptr [esp + 0x18], eax
// 00974759  8944241c             mov dword ptr [esp + 0x1c], eax
// 0097475d  8b4634               mov eax, dword ptr [esi + 0x34]
// 00974760  6800020000           push 0x200
// 00974765  50                   push eax
// 00974766  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0097476e  e86d0a1200           call 0xa951e0
// 00974773  db4604               fild dword ptr [esi + 4]
// 00974776  8b4e04               mov ecx, dword ptr [esi + 4]
// 00974779  85c9                 test ecx, ecx
// 0097477b  7d06                 jge 0x974783
// 0097477d  dc0578fdb400         fadd qword ptr [0xb4fd78]
// 00974783  dc4c2410             fmul qword ptr [esp + 0x10]
// 00974787  5e                   pop esi
// 00974788  dc4c241c             fmul qword ptr [esp + 0x1c]
// 0097478c  dc0d283bb500         fmul qword ptr [0xb53b28]
// 00974792  83c424               add esp, 0x24
// 00974795  c3                   ret 
// copied from an identical function in another client (function ?GetProcessCores@CProcessPerfCounter@@QAENXZ)

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