// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00925f50  unit: RBX::StepJointsStage  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00925f50
//
// 00925f50  6aff                 push -1
// 00925f52  68eb29ad00           push 0xad29eb
// 00925f57  64a100000000         mov eax, dword ptr fs:[0]
// 00925f5d  50                   push eax
// 00925f5e  64892500000000       mov dword ptr fs:[0], esp
// 00925f65  51                   push ecx
// 00925f66  56                   push esi
// 00925f67  57                   push edi
// 00925f68  6a10                 push 0x10
// 00925f6a  8bf1                 mov esi, ecx
// 00925f6c  e8a9c10500           call 0x98211a
// 00925f71  83c404               add esp, 4
// 00925f74  89442408             mov dword ptr [esp + 8], eax
// 00925f78  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00925f7c  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00925f84  85c0                 test eax, eax
// 00925f86  740b                 je 0x925f93
// 00925f88  57                   push edi
// 00925f89  56                   push esi
// 00925f8a  8bc8                 mov ecx, eax
// 00925f8c  e8afd50300           call 0x963540
// 00925f91  eb02                 jmp 0x925f95
// 00925f93  33c0                 xor eax, eax
// 00925f95  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00925f99  894e04               mov dword ptr [esi + 4], ecx
// 00925f9c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00925fa0  897e0c               mov dword ptr [esi + 0xc], edi
// 00925fa3  894608               mov dword ptr [esi + 8], eax
// 00925fa6  c70670aebf00         mov dword ptr [esi], 0xbfae70
// 00925fac  5f                   pop edi
// 00925fad  8bc6                 mov eax, esi
// 00925faf  5e                   pop esi
// 00925fb0  64890d00000000       mov dword ptr fs:[0], ecx
// 00925fb7  83c410               add esp, 0x10
// 00925fba  c20800               ret 8

// copied from an identical function in another client (function ??0C@@QAE@PAUA@@PAUB@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A; struct B; class C;
struct T {
    char d[0x1c];
    T(C* owner, B* b);
};
struct Base {
    A* a;
    T* obj;
    B* b;
    Base(A* a, T* obj, B* b) : a(a), obj(obj), b(b) {}
};
class C : public Base {
public:
    C(A* a, B* b);
    virtual ~C();
};
C::C(A* a, B* b) : Base(a, new T(this, b), b) {}
