// from server: 100% by EspClaude
// roc 2009-06 00427420  unit: CMainFrame  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427420
//
// 00427420  56                   push esi
// 00427421  6a00                 push 0
// 00427423  8bf1                 mov esi, ecx
// 00427425  e8864b2f00           call 0x71bfb0
// 0042742a  c706a40e8b00         mov dword ptr [esi], 0x8b0ea4
// 00427430  c74620440e8b00       mov dword ptr [esi + 0x20], 0x8b0e44
// 00427437  8bc6                 mov eax, esi
// 00427439  5e                   pop esi
// 0042743a  c3                   ret 
// copied from an identical function in another client (function ??0Derived@@QAE@XZ)

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