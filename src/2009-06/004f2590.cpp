// from server: 78% by EspClaude
// from server: 100% by colin
// roc 2008-06 004b94a0  unit: RBX::Network::Replicator  size: 177 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b94a0
//
// 004b94a0  6aff                 push -1
// 004b94a2  68968d7c00           push 0x7c8d96
// 004b94a7  64a100000000         mov eax, dword ptr fs:[0]
// 004b94ad  50                   push eax
// 004b94ae  64892500000000       mov dword ptr fs:[0], esp
// 004b94b5  83ec08               sub esp, 8
// 004b94b8  56                   push esi
// 004b94b9  8bf1                 mov esi, ecx
// 004b94bb  89742408             mov dword ptr [esp + 8], esi
// 004b94bf  e81c230a00           call 0x55b7e0
// 004b94c4  8d8e30010000         lea ecx, [esi + 0x130]
// 004b94ca  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004b94d2  c7064c538200         mov dword ptr [esi], 0x82534c
// 004b94d8  c746103c538200       mov dword ptr [esi + 0x10], 0x82533c
// 004b94df  c7461434538200       mov dword ptr [esi + 0x14], 0x825334
// 004b94e6  c746202c538200       mov dword ptr [esi + 0x20], 0x82532c
// 004b94ed  c746241c538200       mov dword ptr [esi + 0x24], 0x82531c
// 004b94f4  c746440c538200       mov dword ptr [esi + 0x44], 0x82530c
// 004b94fb  c74664fc528200       mov dword ptr [esi + 0x64], 0x8252fc
// 004b9502  c78684000000ec528200 mov dword ptr [esi + 0x84], 0x8252ec
// 004b950c  c786a4000000dc528200 mov dword ptr [esi + 0xa4], 0x8252dc
// 004b9516  c786c4000000cc528200 mov dword ptr [esi + 0xc4], 0x8252cc
// 004b9520  e8eba7ffff           call 0x4b3d10
// 004b9525  8d442407             lea eax, [esp + 7]
// 004b9529  50                   push eax
// 004b952a  8d4c240b             lea ecx, [esp + 0xb]
// 004b952e  51                   push ecx
// 004b952f  8d8e542b0000         lea ecx, [esi + 0x2b54]
// 004b9535  c644241c01           mov byte ptr [esp + 0x1c], 1
// 004b953a  e8f1051e00           call 0x699b30
// 004b953f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b9543  8bc6                 mov eax, esi
// 004b9545  5e                   pop esi
// 004b9546  64890d00000000       mov dword ptr fs:[0], ecx
// 004b954d  83c414               add esp, 0x14
// 004b9550  c3                   ret 

#include <set>
struct E { int v[8]; };
bool operator<(const E&, const E&);
typedef std::set<E> Tail;

struct I0 { virtual void f(); char padding[12]; };
struct I1 { virtual void f(); };
struct I2 { virtual void f(); char padding[8]; };
struct I3 { virtual void f(); };
struct I4 { virtual void f(); char padding[28]; };
struct I5 { virtual void f(); char padding[28]; };
struct I6 { virtual void f(); char padding[28]; };
struct I7 { virtual void f(); char padding[28]; };
struct I8 { virtual void f(); char padding[28]; };
struct I9 { virtual void f(); char padding[104]; };

struct Base : I0, I1, I2, I3, I4, I5, I6, I7, I8, I9 {
    Base();
    ~Base();
};

struct Member {
    char storage[0x2A24];
    Member();
    ~Member();
};

struct S : Base {
    Member member;
    Tail tail;
    virtual void f();
    S();
};

S::S() : Base(), member(), tail()
{
}
