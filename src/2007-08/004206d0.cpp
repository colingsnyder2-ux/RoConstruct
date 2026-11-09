// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 004206d0  unit: CRobloxTreeCtrl  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004206d0
//
// 004206d0  6aff                 push -1
// 004206d2  6858be7300           push 0x73be58
// 004206d7  64a100000000         mov eax, dword ptr fs:[0]
// 004206dd  50                   push eax
// 004206de  83ec08               sub esp, 8
// 004206e1  56                   push esi
// 004206e2  57                   push edi
// 004206e3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004206e8  33c4                 xor eax, esp
// 004206ea  50                   push eax
// 004206eb  8d442414             lea eax, [esp + 0x14]
// 004206ef  64a300000000         mov dword ptr fs:[0], eax
// 004206f5  8d44240c             lea eax, [esp + 0xc]
// 004206f9  50                   push eax
// 004206fa  e871440200           call 0x444b70
// 004206ff  83c404               add esp, 4
// 00420702  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00420706  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00420709  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042070d  6a01                 push 1
// 0042070f  50                   push eax
// 00420710  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00420718  e843250200           call 0x442c60
// 0042071d  85c0                 test eax, eax
// 0042071f  740b                 je 0x42072c
// 00420721  8bc8                 mov ecx, eax
// 00420723  e8c8efffff           call 0x41f6f0
// 00420728  8bf8                 mov edi, eax
// 0042072a  eb02                 jmp 0x42072e
// 0042072c  33ff                 xor edi, edi
// 0042072e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00420732  85f6                 test esi, esi
// 00420734  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0042073c  742a                 je 0x420768
// 0042073e  8d5604               lea edx, [esi + 4]
// 00420741  83c8ff               or eax, 0xffffffff
// 00420744  f00fc102             lock xadd dword ptr [edx], eax
// 00420748  751e                 jne 0x420768
// 0042074a  8b16                 mov edx, dword ptr [esi]
// 0042074c  8b4204               mov eax, dword ptr [edx + 4]
// 0042074f  8bce                 mov ecx, esi
// 00420751  ffd0                 call eax
// 00420753  8d4e08               lea ecx, [esi + 8]
// 00420756  83caff               or edx, 0xffffffff
// 00420759  f00fc111             lock xadd dword ptr [ecx], edx
// 0042075d  7509                 jne 0x420768
// 0042075f  8b06                 mov eax, dword ptr [esi]
// 00420761  8b5008               mov edx, dword ptr [eax + 8]
// 00420764  8bce                 mov ecx, esi
// 00420766  ffd2                 call edx
// 00420768  8bc7                 mov eax, edi
// 0042076a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042076e  64890d00000000       mov dword ptr fs:[0], ecx
// 00420775  59                   pop ecx
// 00420776  5f                   pop edi
// 00420777  5e                   pop esi
// 00420778  83c414               add esp, 0x14
// 0042077b  c3                   ret 

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
    char padding[0xc];
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
