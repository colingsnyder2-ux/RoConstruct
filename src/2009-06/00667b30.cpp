// from server: 100% by EspClaude
// roc 2009-06 00667b30  unit: RBX::Humanoid  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00667b30
//
// 00667b30  6aff                 push -1
// 00667b32  6831c48600           push 0x86c431
// 00667b37  64a100000000         mov eax, dword ptr fs:[0]
// 00667b3d  50                   push eax
// 00667b3e  64892500000000       mov dword ptr fs:[0], esp
// 00667b45  83ec14               sub esp, 0x14
// 00667b48  807c242800           cmp byte ptr [esp + 0x28], 0
// 00667b4d  56                   push esi
// 00667b4e  57                   push edi
// 00667b4f  c744240800000000     mov dword ptr [esp + 8], 0
// 00667b57  744e                 je 0x667ba7
// 00667b59  8d44240c             lea eax, [esp + 0xc]
// 00667b5d  50                   push eax
// 00667b5e  e85d27e8ff           call 0x4ea2c0
// 00667b63  d905c4758b00         fld dword ptr [0x8b75c4]
// 00667b69  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00667b6d  d91c24               fstp dword ptr [esp]
// 00667b70  be01000000           mov esi, 1
// 00667b75  89742428             mov dword ptr [esp + 0x28], esi
// 00667b79  e8b24a0100           call 0x67c630
// 00667b7e  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00667b82  8b442410             mov eax, dword ptr [esp + 0x10]
// 00667b86  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00667b8a  890f                 mov dword ptr [edi], ecx
// 00667b8c  894704               mov dword ptr [edi + 4], eax
// 00667b8f  85c0                 test eax, eax
// 00667b91  740d                 je 0x667ba0
// 00667b93  83c004               add eax, 4
// 00667b96  8bd6                 mov edx, esi
// 00667b98  f00fc110             lock xadd dword ptr [eax], edx
// 00667b9c  8b442410             mov eax, dword ptr [esp + 0x10]
// 00667ba0  c644242400           mov byte ptr [esp + 0x24], 0
// 00667ba5  eb3c                 jmp 0x667be3
// 00667ba7  8d442414             lea eax, [esp + 0x14]
// 00667bab  50                   push eax
// 00667bac  e86f18e8ff           call 0x4e9420
// 00667bb1  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00667bb5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00667bb9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00667bbd  83c404               add esp, 4
// 00667bc0  890f                 mov dword ptr [edi], ecx
// 00667bc2  894704               mov dword ptr [edi + 4], eax
// 00667bc5  be01000000           mov esi, 1
// 00667bca  85c0                 test eax, eax
// 00667bcc  740d                 je 0x667bdb
// 00667bce  83c004               add eax, 4
// 00667bd1  8bd6                 mov edx, esi
// 00667bd3  f00fc110             lock xadd dword ptr [eax], edx
// 00667bd7  8b442418             mov eax, dword ptr [esp + 0x18]
// 00667bdb  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00667be3  89742408             mov dword ptr [esp + 8], esi
// 00667be7  85c0                 test eax, eax
// 00667be9  742c                 je 0x667c17
// 00667beb  8bf0                 mov esi, eax
// 00667bed  83c9ff               or ecx, 0xffffffff
// 00667bf0  83c004               add eax, 4
// 00667bf3  f00fc108             lock xadd dword ptr [eax], ecx
// 00667bf7  751e                 jne 0x667c17
// 00667bf9  8b16                 mov edx, dword ptr [esi]
// 00667bfb  8b4204               mov eax, dword ptr [edx + 4]
// 00667bfe  8bce                 mov ecx, esi
// 00667c00  ffd0                 call eax
// 00667c02  83caff               or edx, 0xffffffff
// 00667c05  8d4e08               lea ecx, [esi + 8]
// 00667c08  f00fc111             lock xadd dword ptr [ecx], edx
// 00667c0c  7509                 jne 0x667c17
// 00667c0e  8b06                 mov eax, dword ptr [esi]
// 00667c10  8b5008               mov edx, dword ptr [eax + 8]
// 00667c13  8bce                 mov ecx, esi
// 00667c15  ffd2                 call edx
// 00667c17  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00667c1b  8bc7                 mov eax, edi
// 00667c1d  5f                   pop edi
// 00667c1e  5e                   pop esi
// 00667c1f  64890d00000000       mov dword ptr fs:[0], ecx
// 00667c26  83c420               add esp, 0x20
// 00667c29  c3                   ret 
// copied from an identical function in another client (function ?makeState@ns_ROCX00001f@@YA?AUShared@1@_N@Z)

namespace ns_ROCX00001f {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Object {
    void setValue(float);
};

struct Count {
    Control* control;

    Count(const Count&);
    ~Count();
};

inline Count::Count(const Count& other)
    : control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Count::~Count()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Shared {
    Object* object;
    Count count;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), count(other.count)
{
}

inline Shared::~Shared()
{
}

extern Shared __cdecl createRotate();
extern Shared __cdecl createLighting();
extern const float initialValue;

Shared __cdecl makeState(bool rotate)
{
    if (rotate) {
        Shared result = createRotate();
        result.object->setValue(initialValue);
        return result;
    } else {
        Shared result = createLighting();
        return result;
    }
}
}
