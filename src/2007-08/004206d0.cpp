// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00423050  unit: CRobloxTreeCtrl  size: 160 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00423050
//
// 00423050  6aff                 push -1
// 00423052  6868917d00           push 0x7d9168
// 00423057  64a100000000         mov eax, dword ptr fs:[0]
// 0042305d  50                   push eax
// 0042305e  64892500000000       mov dword ptr fs:[0], esp
// 00423065  83ec08               sub esp, 8
// 00423068  56                   push esi
// 00423069  8d442404             lea eax, [esp + 4]
// 0042306d  57                   push edi
// 0042306e  50                   push eax
// 0042306f  e8ac1f0200           call 0x445020
// 00423074  83c404               add esp, 4
// 00423077  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042307b  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 0042307e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00423082  6a01                 push 1
// 00423084  50                   push eax
// 00423085  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0042308d  e87e010200           call 0x443210
// 00423092  85c0                 test eax, eax
// 00423094  740b                 je 0x4230a1
// 00423096  8bc8                 mov ecx, eax
// 00423098  e813f5ffff           call 0x4225b0
// 0042309d  8bf8                 mov edi, eax
// 0042309f  eb02                 jmp 0x4230a3
// 004230a1  33ff                 xor edi, edi
// 004230a3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004230a7  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004230af  85f6                 test esi, esi
// 004230b1  742a                 je 0x4230dd
// 004230b3  8d5604               lea edx, [esi + 4]
// 004230b6  83c8ff               or eax, 0xffffffff
// 004230b9  f00fc102             lock xadd dword ptr [edx], eax
// 004230bd  751e                 jne 0x4230dd
// 004230bf  8b16                 mov edx, dword ptr [esi]
// 004230c1  8b4204               mov eax, dword ptr [edx + 4]
// 004230c4  8bce                 mov ecx, esi
// 004230c6  ffd0                 call eax
// 004230c8  8d4e08               lea ecx, [esi + 8]
// 004230cb  83caff               or edx, 0xffffffff
// 004230ce  f00fc111             lock xadd dword ptr [ecx], edx
// 004230d2  7509                 jne 0x4230dd
// 004230d4  8b06                 mov eax, dword ptr [esi]
// 004230d6  8b5008               mov edx, dword ptr [eax + 8]
// 004230d9  8bce                 mov ecx, esi
// 004230db  ffd2                 call edx
// 004230dd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004230e1  8bc7                 mov eax, edi
// 004230e3  5f                   pop edi
// 004230e4  5e                   pop esi
// 004230e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004230ec  83c414               add esp, 0x14
// 004230ef  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Target {
    int invoke(int, int);
};

struct Service {
    char padding[0x130];
    Target* target;
    int invoke(int, int);
};

struct Result {
    int get();
};

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;
};

struct Shared {
    Service* object;
    Control* control;

    ~Shared();
};

struct Input {
    char padding[0x1c];
    int value;
};

Shared __cdecl acquire();

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

int __cdecl function(Input* input)
{
    Shared shared = acquire();
    int value = input->value;
    Result* result = reinterpret_cast<Result*>(
        shared.object->invoke(value, 1));
    return result ? result->get() : 0;
}
