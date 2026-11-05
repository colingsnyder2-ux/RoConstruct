// from server: 100% by EspClaude
// roc 2009-06 004ed360  unit: RBX::Network::Replicator  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ed360
//
// 004ed360  6aff                 push -1
// 004ed362  6831c48500           push 0x85c431
// 004ed367  64a100000000         mov eax, dword ptr fs:[0]
// 004ed36d  50                   push eax
// 004ed36e  64892500000000       mov dword ptr fs:[0], esp
// 004ed375  83ec2c               sub esp, 0x2c
// 004ed378  8b442440             mov eax, dword ptr [esp + 0x40]
// 004ed37c  53                   push ebx
// 004ed37d  55                   push ebp
// 004ed37e  56                   push esi
// 004ed37f  57                   push edi
// 004ed380  8bd9                 mov ebx, ecx
// 004ed382  50                   push eax
// 004ed383  8d4c241c             lea ecx, [esp + 0x1c]
// 004ed387  51                   push ecx
// 004ed388  e8d3f7ffff           call 0x4ecb60
// 004ed38d  8b7004               mov esi, dword ptr [eax + 4]
// 004ed390  8b38                 mov edi, dword ptr [eax]
// 004ed392  83c408               add esp, 8
// 004ed395  897c2410             mov dword ptr [esp + 0x10], edi
// 004ed399  89742414             mov dword ptr [esp + 0x14], esi
// 004ed39d  85f6                 test esi, esi
// 004ed39f  740c                 je 0x4ed3ad
// 004ed3a1  8d5604               lea edx, [esi + 4]
// 004ed3a4  b801000000           mov eax, 1
// 004ed3a9  f00fc102             lock xadd dword ptr [edx], eax
// 004ed3ad  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004ed3b1  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004ed3b9  85ed                 test ebp, ebp
// 004ed3bb  742c                 je 0x4ed3e9
// 004ed3bd  8d4d04               lea ecx, [ebp + 4]
// 004ed3c0  83caff               or edx, 0xffffffff
// 004ed3c3  f00fc111             lock xadd dword ptr [ecx], edx
// 004ed3c7  7520                 jne 0x4ed3e9
// 004ed3c9  8b4500               mov eax, dword ptr [ebp]
// 004ed3cc  8b5004               mov edx, dword ptr [eax + 4]
// 004ed3cf  8bcd                 mov ecx, ebp
// 004ed3d1  ffd2                 call edx
// 004ed3d3  8d4508               lea eax, [ebp + 8]
// 004ed3d6  83c9ff               or ecx, 0xffffffff
// 004ed3d9  f00fc108             lock xadd dword ptr [eax], ecx
// 004ed3dd  750a                 jne 0x4ed3e9
// 004ed3df  8b5500               mov edx, dword ptr [ebp]
// 004ed3e2  8b4208               mov eax, dword ptr [edx + 8]
// 004ed3e5  8bcd                 mov ecx, ebp
// 004ed3e7  ffd0                 call eax
// 004ed3e9  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004ed3ed  51                   push ecx
// 004ed3ee  8d4c2424             lea ecx, [esp + 0x24]
// 004ed3f2  ff15b4e48900         call dword ptr [0x89e4b4]
// 004ed3f8  8b17                 mov edx, dword ptr [edi]
// 004ed3fa  8b5204               mov edx, dword ptr [edx + 4]
// 004ed3fd  8d442420             lea eax, [esp + 0x20]
// 004ed401  50                   push eax
// 004ed402  8bcf                 mov ecx, edi
// 004ed404  c644244801           mov byte ptr [esp + 0x48], 1
// 004ed409  ffd2                 call edx
// 004ed40b  8d4c2420             lea ecx, [esp + 0x20]
// 004ed40f  c644244400           mov byte ptr [esp + 0x44], 0
// 004ed414  ff15c4e48900         call dword ptr [0x89e4c4]
// 004ed41a  53                   push ebx
// 004ed41b  8bcf                 mov ecx, edi
// 004ed41d  e82e4a0e00           call 0x5d1e50
// 004ed422  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 004ed42a  85f6                 test esi, esi
// 004ed42c  742a                 je 0x4ed458
// 004ed42e  8d4604               lea eax, [esi + 4]
// 004ed431  83c9ff               or ecx, 0xffffffff
// 004ed434  f00fc108             lock xadd dword ptr [eax], ecx
// 004ed438  751e                 jne 0x4ed458
// 004ed43a  8b16                 mov edx, dword ptr [esi]
// 004ed43c  8b4204               mov eax, dword ptr [edx + 4]
// 004ed43f  8bce                 mov ecx, esi
// 004ed441  ffd0                 call eax
// 004ed443  8d4e08               lea ecx, [esi + 8]
// 004ed446  83caff               or edx, 0xffffffff
// 004ed449  f00fc111             lock xadd dword ptr [ecx], edx
// 004ed44d  7509                 jne 0x4ed458
// 004ed44f  8b06                 mov eax, dword ptr [esi]
// 004ed451  8b5008               mov edx, dword ptr [eax + 8]
// 004ed454  8bce                 mov ecx, esi
// 004ed456  ffd2                 call edx
// 004ed458  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004ed45c  8bc7                 mov eax, edi
// 004ed45e  5f                   pop edi
// 004ed45f  5e                   pop esi
// 004ed460  5d                   pop ebp
// 004ed461  5b                   pop ebx
// 004ed462  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed469  83c438               add esp, 0x38
// 004ed46c  c20800               ret 8
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
