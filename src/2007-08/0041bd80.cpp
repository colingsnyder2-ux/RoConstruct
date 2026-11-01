// from server: 100% by Yeetserama
// roc 2007-08 0041bd80  unit: VDHTMLWindow::?$SignalDesc  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041bd80
//
// 0041bd80  6aff                 push -1
// 0041bd82  6809477600           push 0x764709
// 0041bd87  64a100000000         mov eax, dword ptr fs:[0]
// 0041bd8d  50                   push eax
// 0041bd8e  51                   push ecx
// 0041bd8f  56                   push esi
// 0041bd90  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041bd95  33c4                 xor eax, esp
// 0041bd97  50                   push eax
// 0041bd98  8d44240c             lea eax, [esp + 0xc]
// 0041bd9c  64a300000000         mov dword ptr fs:[0], eax
// 0041bda2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041bda6  50                   push eax
// 0041bda7  8d4c240c             lea ecx, [esp + 0xc]
// 0041bdab  ff1590dd7700         call dword ptr [0x77dd90]
// 0041bdb1  8bc8                 mov ecx, eax
// 0041bdb3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0041bdbb  ff1598dd7700         call dword ptr [0x77dd98]
// 0041bdc1  50                   push eax
// 0041bdc2  e809501300           call 0x550dd0
// 0041bdc7  83c404               add esp, 4
// 0041bdca  f6d8                 neg al
// 0041bdcc  8d4c2408             lea ecx, [esp + 8]
// 0041bdd0  1bc0                 sbb eax, eax
// 0041bdd2  25fbbfff7f           and eax, 0x7fffbffb
// 0041bdd7  0505400080           add eax, 0x80004005
// 0041bddc  8bf0                 mov esi, eax
// 0041bdde  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0041bde4  8bc6                 mov eax, esi
// 0041bde6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041bdea  64890d00000000       mov dword ptr fs:[0], ecx
// 0041bdf1  59                   pop ecx
// 0041bdf2  5e                   pop esi
// 0041bdf3  83c410               add esp, 0x10
// 0041bdf6  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000c_0041dcd0@ns_ROCX00000c@@YAJPB_W@Z)

namespace ns_ROCX00000c {
struct S;

extern S* (__thiscall *construct_string)(S*, const wchar_t*);
extern const char* (__thiscall *get_string)(S*);
extern void (__thiscall *destroy_string)(S*);
extern bool __cdecl process_string(const char*);

struct S
{
    void* data;
    S(const wchar_t*, S*&);
    __declspec(dllimport) ~S() throw();
    const char* get();
};

S::S(const wchar_t* text, S*& result)
{
    result = construct_string(this, text);
}

const char* S::get()
{
    return get_string(this);
}

long __cdecl fn_ROCX00000c_0041dcd0(const wchar_t* text)
{
    S* result;
    S value(text, result);
    return process_string(result->get()) ? 0 : (long)0x80004005;
}
}
