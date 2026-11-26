// from server: 100% by Xemicl
// roc 2012-06 009746a0  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009746a0
//
// 009746a0  83ec10               sub esp, 0x10
// 009746a3  8b542414             mov edx, dword ptr [esp + 0x14]
// 009746a7  33c0                 xor eax, eax
// 009746a9  8d0c24               lea ecx, [esp]
// 009746ac  51                   push ecx
// 009746ad  50                   push eax
// 009746ae  6800010000           push 0x100
// 009746b3  52                   push edx
// 009746b4  89442410             mov dword ptr [esp + 0x10], eax
// 009746b8  89442418             mov dword ptr [esp + 0x18], eax
// 009746bc  8944241c             mov dword ptr [esp + 0x1c], eax
// 009746c0  e81b0b1200           call 0xa951e0
// 009746c5  8b442418             mov eax, dword ptr [esp + 0x18]
// 009746c9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009746cd  8908                 mov dword ptr [eax], ecx
// 009746cf  83c410               add esp, 0x10
// 009746d2  c3                   ret 
// copied from an identical function in another client (function ?getCounterValue@@YAXPAXPAJ@Z)

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
#define PDH_FMT_LONG 0x00000100
#define PDH_FMT_DOUBLE 0x00000200
void getCounterValue(PDH_HCOUNTER counter, long* value)
{
    PDH_FMT_COUNTERVALUE v = { 0 };
    PdhGetFormattedCounterValue(counter, PDH_FMT_LONG, 0, &v);
    *value = v.longValue;
}