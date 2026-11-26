// from server: 100% by Xemicl
// roc 2012-06 00521380  unit: rbx::signals::$$A6AXXZ::?$signal::Vslot::?$callable  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00521380
//
// 00521380  6aff                 push -1
// 00521382  681895ae00           push 0xae9518
// 00521387  64a100000000         mov eax, dword ptr fs:[0]
// 0052138d  50                   push eax
// 0052138e  64892500000000       mov dword ptr fs:[0], esp
// 00521395  83ec0c               sub esp, 0xc
// 00521398  56                   push esi
// 00521399  6a00                 push 0
// 0052139b  8d442428             lea eax, [esp + 0x28]
// 0052139f  8d54240c             lea edx, [esp + 0xc]
// 005213a3  8944240c             mov dword ptr [esp + 0xc], eax
// 005213a7  8b442424             mov eax, dword ptr [esp + 0x24]
// 005213ab  8d4c242c             lea ecx, [esp + 0x2c]
// 005213af  52                   push edx
// 005213b0  894c2414             mov dword ptr [esp + 0x14], ecx
// 005213b4  c644240c00           mov byte ptr [esp + 0xc], 0
// 005213b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005213bd  50                   push eax
// 005213be  51                   push ecx
// 005213bf  8d4804               lea ecx, [eax + 4]
// 005213c2  c744242800000000     mov dword ptr [esp + 0x28], 0
// 005213ca  e891daffff           call 0x51ee60
// 005213cf  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 005213d3  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005213db  85f6                 test esi, esi
// 005213dd  742a                 je 0x521409
// 005213df  8d5604               lea edx, [esi + 4]
// 005213e2  83c8ff               or eax, 0xffffffff
// 005213e5  f00fc102             lock xadd dword ptr [edx], eax
// 005213e9  751e                 jne 0x521409
// 005213eb  8b16                 mov edx, dword ptr [esi]
// 005213ed  8b4204               mov eax, dword ptr [edx + 4]
// 005213f0  8bce                 mov ecx, esi
// 005213f2  ffd0                 call eax
// 005213f4  8d4e08               lea ecx, [esi + 8]
// 005213f7  83caff               or edx, 0xffffffff
// 005213fa  f00fc111             lock xadd dword ptr [ecx], edx
// 005213fe  7509                 jne 0x521409
// 00521400  8b06                 mov eax, dword ptr [esi]
// 00521402  8b5008               mov edx, dword ptr [eax + 8]
// 00521405  8bce                 mov ecx, esi
// 00521407  ffd2                 call edx
// 00521409  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0052140d  5e                   pop esi
// 0052140e  64890d00000000       mov dword ptr fs:[0], ecx
// 00521415  83c418               add esp, 0x18
// 00521418  c3                   ret 
// copied from an identical function in another client (function ?function@ns_ROCX000005@@YAXPAXHUShared@1@@Z)

namespace ns_ROCX000005 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared
{
    void* pointer;
    Control* control;

    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Tag
{
    char value;
};

struct Arguments
{
    int* key;
    Shared* value;
};

struct Tree
{
    void __thiscall insert(Tag, void*, Arguments*, int);
};

void __cdecl function(void* object, int key, Shared value)
{
    Tag tag = { 0 };
    Arguments arguments;
    arguments.key = &key;
    arguments.value = &value;
    reinterpret_cast<Tree*>(static_cast<char*>(object) + 4)
        ->insert(tag, object, &arguments, 0);
}
}
