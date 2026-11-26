// from server: 100% by Xemicl
// roc 2012-06 00435090  unit: CMainFrame  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00435090
//
// 00435090  56                   push esi
// 00435091  6a00                 push 0
// 00435093  8bf1                 mov esi, ecx
// 00435095  e886a45500           call 0x98f520
// 0043509a  c706dcf8b400         mov dword ptr [esi], 0xb4f8dc
// 004350a0  c746207cf8b400       mov dword ptr [esi + 0x20], 0xb4f87c
// 004350a7  8bc6                 mov eax, esi
// 004350a9  5e                   pop esi
// 004350aa  c3                   ret 
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