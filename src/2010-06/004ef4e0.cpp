// from server: 100% by Yeetserama
// roc 2010-06 004ef4e0  unit: RBX::Network::Replicator::EventInvocationItem  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ef4e0
//
// 004ef4e0  6aff                 push -1
// 004ef4e2  6898c19800           push 0x98c198
// 004ef4e7  64a100000000         mov eax, dword ptr fs:[0]
// 004ef4ed  50                   push eax
// 004ef4ee  64892500000000       mov dword ptr fs:[0], esp
// 004ef4f5  83ec08               sub esp, 8
// 004ef4f8  56                   push esi
// 004ef4f9  8bf1                 mov esi, ecx
// 004ef4fb  8d442407             lea eax, [esp + 7]
// 004ef4ff  50                   push eax
// 004ef500  8d4c240b             lea ecx, [esp + 0xb]
// 004ef504  51                   push ecx
// 004ef505  8bce                 mov ecx, esi
// 004ef507  89742410             mov dword ptr [esp + 0x10], esi
// 004ef50b  e800943d00           call 0x8c8910
// 004ef510  8b1500a49e00         mov edx, dword ptr [0x9ea400]
// 004ef516  a104a49e00           mov eax, dword ptr [0x9ea404]
// 004ef51b  52                   push edx
// 004ef51c  50                   push eax
// 004ef51d  6880000000           push 0x80
// 004ef522  6a1c                 push 0x1c
// 004ef524  8d4e20               lea ecx, [esi + 0x20]
// 004ef527  51                   push ecx
// 004ef528  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004ef530  e8bb962b00           call 0x7a8bf0
// 004ef535  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004ef539  c786200e000001000000 mov dword ptr [esi + 0xe20], 1
// 004ef543  8bc6                 mov eax, esi
// 004ef545  5e                   pop esi
// 004ef546  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef54d  83c414               add esp, 0x14
// 004ef550  c3                   ret 
// copied from an identical function in another client (function ??0S@@QAE@XZ)

// from server: 100% by colin
#include <set>
struct E { int v[8]; };
bool operator<(const E&, const E&);
typedef void (__thiscall *ElementRoutine)(void*);
extern ElementRoutine elementConstructor;
extern ElementRoutine elementDestructor;
void __stdcall constructArray(void*, unsigned int, unsigned int, ElementRoutine, ElementRoutine);
struct S : std::set<E> {
 char elements[0xE00];
 int flag;
 S();
};
S::S() {
 constructArray(elements,0x1C,0x80,elementConstructor,elementDestructor);
 flag=1;
}