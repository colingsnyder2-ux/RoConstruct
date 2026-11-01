// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 0041dcd0  unit: VDHTMLWindow::?$SignalDesc  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041dcd0
//
// 0041dcd0  6aff                 push -1
// 0041dcd2  68c9107c00           push 0x7c10c9
// 0041dcd7  64a100000000         mov eax, dword ptr fs:[0]
// 0041dcdd  50                   push eax
// 0041dcde  64892500000000       mov dword ptr fs:[0], esp
// 0041dce5  51                   push ecx
// 0041dce6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0041dcea  56                   push esi
// 0041dceb  50                   push eax
// 0041dcec  8d4c2408             lea ecx, [esp + 8]
// 0041dcf0  ff15d83e8000         call dword ptr [0x803ed8]
// 0041dcf6  8bc8                 mov ecx, eax
// 0041dcf8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041dd00  ff15e03e8000         call dword ptr [0x803ee0]
// 0041dd06  50                   push eax
// 0041dd07  e8d4c51400           call 0x56a2e0
// 0041dd0c  0fb6f0               movzx esi, al
// 0041dd0f  83c404               add esp, 4
// 0041dd12  f7de                 neg esi
// 0041dd14  1bf6                 sbb esi, esi
// 0041dd16  81e6fbbfff7f         and esi, 0x7fffbffb
// 0041dd1c  8d4c2404             lea ecx, [esp + 4]
// 0041dd20  81c605400080         add esi, 0x80004005
// 0041dd26  ff15143f8000         call dword ptr [0x803f14]
// 0041dd2c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0041dd30  8bc6                 mov eax, esi
// 0041dd32  5e                   pop esi
// 0041dd33  64890d00000000       mov dword ptr fs:[0], ecx
// 0041dd3a  83c410               add esp, 0x10
// 0041dd3d  c3                   ret 

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

long __cdecl func_0041dcd0(const wchar_t* text)
{
    S* result;
    S value(text, result);
    return process_string(result->get()) ? 0 : (long)0x80004005;
}
