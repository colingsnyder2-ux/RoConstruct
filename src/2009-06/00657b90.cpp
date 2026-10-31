// from server: 100% by EspClaude
// roc 2009-06 00657b90  unit: N::V?$RunningAverageItem::?$NonFactoryProduct  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00657b90
//
// 00657b90  6aff                 push -1
// 00657b92  6831c48500           push 0x85c431
// 00657b97  64a100000000         mov eax, dword ptr fs:[0]
// 00657b9d  50                   push eax
// 00657b9e  64892500000000       mov dword ptr fs:[0], esp
// 00657ba5  83ec2c               sub esp, 0x2c
// 00657ba8  8b442440             mov eax, dword ptr [esp + 0x40]
// 00657bac  53                   push ebx
// 00657bad  55                   push ebp
// 00657bae  56                   push esi
// 00657baf  57                   push edi
// 00657bb0  8bd9                 mov ebx, ecx
// 00657bb2  50                   push eax
// 00657bb3  8d4c241c             lea ecx, [esp + 0x1c]
// 00657bb7  51                   push ecx
// 00657bb8  e8d3fdffff           call 0x657990
// 00657bbd  8b7004               mov esi, dword ptr [eax + 4]
// 00657bc0  8b38                 mov edi, dword ptr [eax]
// 00657bc2  83c408               add esp, 8
// 00657bc5  897c2410             mov dword ptr [esp + 0x10], edi
// 00657bc9  89742414             mov dword ptr [esp + 0x14], esi
// 00657bcd  85f6                 test esi, esi
// 00657bcf  740c                 je 0x657bdd
// 00657bd1  8d5604               lea edx, [esi + 4]
// 00657bd4  b801000000           mov eax, 1
// 00657bd9  f00fc102             lock xadd dword ptr [edx], eax
// 00657bdd  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00657be1  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00657be9  85ed                 test ebp, ebp
// 00657beb  742c                 je 0x657c19
// 00657bed  8d4d04               lea ecx, [ebp + 4]
// 00657bf0  83caff               or edx, 0xffffffff
// 00657bf3  f00fc111             lock xadd dword ptr [ecx], edx
// 00657bf7  7520                 jne 0x657c19
// 00657bf9  8b4500               mov eax, dword ptr [ebp]
// 00657bfc  8b5004               mov edx, dword ptr [eax + 4]
// 00657bff  8bcd                 mov ecx, ebp
// 00657c01  ffd2                 call edx
// 00657c03  8d4508               lea eax, [ebp + 8]
// 00657c06  83c9ff               or ecx, 0xffffffff
// 00657c09  f00fc108             lock xadd dword ptr [eax], ecx
// 00657c0d  750a                 jne 0x657c19
// 00657c0f  8b5500               mov edx, dword ptr [ebp]
// 00657c12  8b4208               mov eax, dword ptr [edx + 8]
// 00657c15  8bcd                 mov ecx, ebp
// 00657c17  ffd0                 call eax
// 00657c19  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00657c1d  51                   push ecx
// 00657c1e  8d4c2424             lea ecx, [esp + 0x24]
// 00657c22  ff15b4e48900         call dword ptr [0x89e4b4]
// 00657c28  8b17                 mov edx, dword ptr [edi]
// 00657c2a  8b5204               mov edx, dword ptr [edx + 4]
// 00657c2d  8d442420             lea eax, [esp + 0x20]
// 00657c31  50                   push eax
// 00657c32  8bcf                 mov ecx, edi
// 00657c34  c644244801           mov byte ptr [esp + 0x48], 1
// 00657c39  ffd2                 call edx
// 00657c3b  8d4c2420             lea ecx, [esp + 0x20]
// 00657c3f  c644244400           mov byte ptr [esp + 0x44], 0
// 00657c44  ff15c4e48900         call dword ptr [0x89e4c4]
// 00657c4a  53                   push ebx
// 00657c4b  8bcf                 mov ecx, edi
// 00657c4d  e8fea1f7ff           call 0x5d1e50
// 00657c52  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00657c5a  85f6                 test esi, esi
// 00657c5c  742a                 je 0x657c88
// 00657c5e  8d4604               lea eax, [esi + 4]
// 00657c61  83c9ff               or ecx, 0xffffffff
// 00657c64  f00fc108             lock xadd dword ptr [eax], ecx
// 00657c68  751e                 jne 0x657c88
// 00657c6a  8b16                 mov edx, dword ptr [esi]
// 00657c6c  8b4204               mov eax, dword ptr [edx + 4]
// 00657c6f  8bce                 mov ecx, esi
// 00657c71  ffd0                 call eax
// 00657c73  8d4e08               lea ecx, [esi + 8]
// 00657c76  83caff               or edx, 0xffffffff
// 00657c79  f00fc111             lock xadd dword ptr [ecx], edx
// 00657c7d  7509                 jne 0x657c88
// 00657c7f  8b06                 mov eax, dword ptr [esi]
// 00657c81  8b5008               mov edx, dword ptr [eax + 8]
// 00657c84  8bce                 mov ecx, esi
// 00657c86  ffd2                 call edx
// 00657c88  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00657c8c  8bc7                 mov eax, edi
// 00657c8e  5f                   pop edi
// 00657c8f  5e                   pop esi
// 00657c90  5d                   pop ebp
// 00657c91  5b                   pop ebx
// 00657c92  64890d00000000       mov dword ptr fs:[0], ecx
// 00657c99  83c438               add esp, 0x38
// 00657c9c  c20800               ret 8
// copied from an identical function in another client (function ?create@Stats@ns_ROCX000055@@QAEPAUItem@2@PBDPAX@Z)

namespace ns_ROCX000055 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
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

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct String
{
    unsigned char storage[28];

    String(const char*);
    ~String();
};

extern String* (__thiscall *constructString)(String*, const char*);
extern void (__thiscall *destroyString)(String*);

__forceinline String::String(const char* text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

struct Stats;

struct Item
{
    virtual void unused();
    virtual void setName(const String&);

    void attach(Stats*);
};

struct Temporary
{
    Item* object;
    Control* control;

    ~Temporary();
};

__forceinline Temporary::~Temporary()
{
    if (control)
        control->release();
}

struct Shared
{
    Item* object;
    Control* control;

    Shared(const Temporary&);
    ~Shared();
};

__forceinline Shared::Shared(const Temporary& source)
    : object(source.object), control(source.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

Temporary __cdecl createItem(void*);

struct Stats
{
    Item* create(const char*, void*);
};

Item* Stats::create(const char* name, void* argument)
{
    Shared item(createItem(argument));
    {
        String text(name);
        item.object->setName(text);
    }
    item.object->attach(this);
    return item.object;
}
}
