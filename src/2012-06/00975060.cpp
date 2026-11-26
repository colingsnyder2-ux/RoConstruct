// from server: 100% by Xemicl
// roc 2012-06 00975060  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00975060
//
// 00975060  6aff                 push -1
// 00975062  6818b0ad00           push 0xadb018
// 00975067  64a100000000         mov eax, dword ptr fs:[0]
// 0097506d  50                   push eax
// 0097506e  64892500000000       mov dword ptr fs:[0], esp
// 00975075  51                   push ecx
// 00975076  56                   push esi
// 00975077  8bf1                 mov esi, ecx
// 00975079  56                   push esi
// 0097507a  6a00                 push 0
// 0097507c  6a00                 push 0
// 0097507e  89742410             mov dword ptr [esp + 0x10], esi
// 00975082  c70600000000         mov dword ptr [esi], 0
// 00975088  e847011200           call 0xa951d4
// 0097508d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00975095  ff15d021b200         call dword ptr [0xb221d0]
// 0097509b  50                   push eax
// 0097509c  8bce                 mov ecx, esi
// 0097509e  e8fdf6ffff           call 0x9747a0
// 009750a3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009750a7  8bc6                 mov eax, esi
// 009750a9  5e                   pop esi
// 009750aa  64890d00000000       mov dword ptr fs:[0], ecx
// 009750b1  83c410               add esp, 0x10
// 009750b4  c3                   ret 
// copied from an identical function in another client (function ??0ProcessCounters@@QAE@XZ)

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