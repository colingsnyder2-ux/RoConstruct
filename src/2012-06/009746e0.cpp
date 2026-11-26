// from server: 100% by Xemicl
// roc 2012-06 009746e0  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009746e0
//
// 009746e0  83ec10               sub esp, 0x10
// 009746e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 009746e7  33c0                 xor eax, eax
// 009746e9  8d0c24               lea ecx, [esp]
// 009746ec  51                   push ecx
// 009746ed  50                   push eax
// 009746ee  6800020000           push 0x200
// 009746f3  52                   push edx
// 009746f4  89442410             mov dword ptr [esp + 0x10], eax
// 009746f8  89442418             mov dword ptr [esp + 0x18], eax
// 009746fc  8944241c             mov dword ptr [esp + 0x1c], eax
// 00974700  e8db0a1200           call 0xa951e0
// 00974705  dd442408             fld qword ptr [esp + 8]
// 00974709  8b442418             mov eax, dword ptr [esp + 0x18]
// 0097470d  dd18                 fstp qword ptr [eax]
// 0097470f  83c410               add esp, 0x10
// 00974712  c3                   ret 
// copied from an identical function in another client (function ?getCounterValue@@YAXPAXPAN@Z)

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
void getCounterValue(PDH_HCOUNTER counter, double* value)
{
    PDH_FMT_COUNTERVALUE v = { 0 };
    PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, 0, &v);
    *value = v.doubleValue;
}