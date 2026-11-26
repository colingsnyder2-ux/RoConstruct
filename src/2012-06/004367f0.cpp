// from server: 100% by Xemicl
// roc 2012-06 004367f0  unit: CPatchedControlComboBox  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004367f0
//
// 004367f0  6aff                 push -1
// 004367f2  686a21aa00           push 0xaa216a
// 004367f7  64a100000000         mov eax, dword ptr fs:[0]
// 004367fd  50                   push eax
// 004367fe  64892500000000       mov dword ptr fs:[0], esp
// 00436805  51                   push ecx
// 00436806  56                   push esi
// 00436807  68e0010000           push 0x1e0
// 0043680c  e809b95400           call 0x98211a
// 00436811  8bf0                 mov esi, eax
// 00436813  83c404               add esp, 4
// 00436816  89742404             mov dword ptr [esp + 4], esi
// 0043681a  33c0                 xor eax, eax
// 0043681c  89442410             mov dword ptr [esp + 0x10], eax
// 00436820  3bf0                 cmp esi, eax
// 00436822  7417                 je 0x43683b
// 00436824  50                   push eax
// 00436825  8bce                 mov ecx, esi
// 00436827  e8f48c5500           call 0x98f520
// 0043682c  c706dcf8b400         mov dword ptr [esi], 0xb4f8dc
// 00436832  c746207cf8b400       mov dword ptr [esi + 0x20], 0xb4f87c
// 00436839  8bc6                 mov eax, esi
// 0043683b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043683f  5e                   pop esi
// 00436840  64890d00000000       mov dword ptr fs:[0], ecx
// 00436847  83c410               add esp, 0x10
// 0043684a  c3                   ret 
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