// from server: 100% by EspClaude
// roc 2009-06 00428db0  unit: MyXTPCommandBars  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428db0
//
// 00428db0  6aff                 push -1
// 00428db2  687aef8400           push 0x84ef7a
// 00428db7  64a100000000         mov eax, dword ptr fs:[0]
// 00428dbd  50                   push eax
// 00428dbe  64892500000000       mov dword ptr fs:[0], esp
// 00428dc5  51                   push ecx
// 00428dc6  56                   push esi
// 00428dc7  68e0010000           push 0x1e0
// 00428dcc  e867fc2e00           call 0x718a38
// 00428dd1  8bf0                 mov esi, eax
// 00428dd3  83c404               add esp, 4
// 00428dd6  89742404             mov dword ptr [esp + 4], esi
// 00428dda  33c0                 xor eax, eax
// 00428ddc  89442410             mov dword ptr [esp + 0x10], eax
// 00428de0  3bf0                 cmp esi, eax
// 00428de2  7417                 je 0x428dfb
// 00428de4  50                   push eax
// 00428de5  8bce                 mov ecx, esi
// 00428de7  e8c4312f00           call 0x71bfb0
// 00428dec  c706a40e8b00         mov dword ptr [esi], 0x8b0ea4
// 00428df2  c74620440e8b00       mov dword ptr [esi + 0x20], 0x8b0e44
// 00428df9  8bc6                 mov eax, esi
// 00428dfb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00428dff  5e                   pop esi
// 00428e00  64890d00000000       mov dword ptr fs:[0], ecx
// 00428e07  83c410               add esp, 0x10
// 00428e0a  c3                   ret 
// copied from an identical function in another client (function ?Create@@YAPAUDerived@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Primary
{
    virtual void vf();
    char data[28];
};

struct Secondary
{
    virtual void vf();
    char data[444];
};

struct Base : Primary, Secondary
{
    Base(int value = 0);
};

struct Derived : Base
{
    virtual void vf();
};

Derived* __cdecl Create()
{
    return new Derived;
}