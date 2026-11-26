// from server: 100% by Xemicl
// roc 2012-06 009481e0  unit: RBX::ArrowToolBase  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009481e0
//
// 009481e0  64a100000000         mov eax, dword ptr fs:[0]
// 009481e6  6aff                 push -1
// 009481e8  680869ab00           push 0xab6908
// 009481ed  50                   push eax
// 009481ee  64892500000000       mov dword ptr fs:[0], esp
// 009481f5  56                   push esi
// 009481f6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009481fa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009481fe  50                   push eax
// 009481ff  51                   push ecx
// 00948200  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00948208  e84377eeff           call 0x82f950
// 0094820d  8b742420             mov esi, dword ptr [esp + 0x20]
// 00948211  83c408               add esp, 8
// 00948214  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0094821c  85f6                 test esi, esi
// 0094821e  742a                 je 0x94824a
// 00948220  8d5604               lea edx, [esi + 4]
// 00948223  83c8ff               or eax, 0xffffffff
// 00948226  f00fc102             lock xadd dword ptr [edx], eax
// 0094822a  751e                 jne 0x94824a
// 0094822c  8b16                 mov edx, dword ptr [esi]
// 0094822e  8b4204               mov eax, dword ptr [edx + 4]
// 00948231  8bce                 mov ecx, esi
// 00948233  ffd0                 call eax
// 00948235  8d4e08               lea ecx, [esi + 8]
// 00948238  83caff               or edx, 0xffffffff
// 0094823b  f00fc111             lock xadd dword ptr [ecx], edx
// 0094823f  7509                 jne 0x94824a
// 00948241  8b06                 mov eax, dword ptr [esi]
// 00948243  8b5008               mov edx, dword ptr [eax + 8]
// 00948246  8bce                 mov ecx, esi
// 00948248  ffd2                 call edx
// 0094824a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0094824e  64890d00000000       mov dword ptr fs:[0], ecx
// 00948255  5e                   pop esi
// 00948256  83c40c               add esp, 0xc
// 00948259  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000d_006404c0@ns_ROCX00000d@@YAXUShared@1@PAX@Z)

namespace ns_ROCX00000d {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

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

extern void __cdecl helper(void*, void*);

void __cdecl fn_ROCX00000d_006404c0(Shared value, void* argument)
{
    helper(value.object, argument);
}
}