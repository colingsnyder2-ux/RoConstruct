// from server: 100% by EspClaude
// roc 2009-06 006584f0  unit: VProfilingItem::?$BoundFuncDesc  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006584f0
//
// 006584f0  6aff                 push -1
// 006584f2  6831c48500           push 0x85c431
// 006584f7  64a100000000         mov eax, dword ptr fs:[0]
// 006584fd  50                   push eax
// 006584fe  64892500000000       mov dword ptr fs:[0], esp
// 00658505  83ec2c               sub esp, 0x2c
// 00658508  8b442440             mov eax, dword ptr [esp + 0x40]
// 0065850c  53                   push ebx
// 0065850d  55                   push ebp
// 0065850e  56                   push esi
// 0065850f  57                   push edi
// 00658510  8bd9                 mov ebx, ecx
// 00658512  50                   push eax
// 00658513  8d4c241c             lea ecx, [esp + 0x1c]
// 00658517  51                   push ecx
// 00658518  e893feffff           call 0x6583b0
// 0065851d  8b7004               mov esi, dword ptr [eax + 4]
// 00658520  8b38                 mov edi, dword ptr [eax]
// 00658522  83c408               add esp, 8
// 00658525  897c2410             mov dword ptr [esp + 0x10], edi
// 00658529  89742414             mov dword ptr [esp + 0x14], esi
// 0065852d  85f6                 test esi, esi
// 0065852f  740c                 je 0x65853d
// 00658531  8d5604               lea edx, [esi + 4]
// 00658534  b801000000           mov eax, 1
// 00658539  f00fc102             lock xadd dword ptr [edx], eax
// 0065853d  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00658541  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00658549  85ed                 test ebp, ebp
// 0065854b  742c                 je 0x658579
// 0065854d  8d4d04               lea ecx, [ebp + 4]
// 00658550  83caff               or edx, 0xffffffff
// 00658553  f00fc111             lock xadd dword ptr [ecx], edx
// 00658557  7520                 jne 0x658579
// 00658559  8b4500               mov eax, dword ptr [ebp]
// 0065855c  8b5004               mov edx, dword ptr [eax + 4]
// 0065855f  8bcd                 mov ecx, ebp
// 00658561  ffd2                 call edx
// 00658563  8d4508               lea eax, [ebp + 8]
// 00658566  83c9ff               or ecx, 0xffffffff
// 00658569  f00fc108             lock xadd dword ptr [eax], ecx
// 0065856d  750a                 jne 0x658579
// 0065856f  8b5500               mov edx, dword ptr [ebp]
// 00658572  8b4208               mov eax, dword ptr [edx + 8]
// 00658575  8bcd                 mov ecx, ebp
// 00658577  ffd0                 call eax
// 00658579  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0065857d  51                   push ecx
// 0065857e  8d4c2424             lea ecx, [esp + 0x24]
// 00658582  ff15b4e48900         call dword ptr [0x89e4b4]
// 00658588  8b17                 mov edx, dword ptr [edi]
// 0065858a  8b5204               mov edx, dword ptr [edx + 4]
// 0065858d  8d442420             lea eax, [esp + 0x20]
// 00658591  50                   push eax
// 00658592  8bcf                 mov ecx, edi
// 00658594  c644244801           mov byte ptr [esp + 0x48], 1
// 00658599  ffd2                 call edx
// 0065859b  8d4c2420             lea ecx, [esp + 0x20]
// 0065859f  c644244400           mov byte ptr [esp + 0x44], 0
// 006585a4  ff15c4e48900         call dword ptr [0x89e4c4]
// 006585aa  53                   push ebx
// 006585ab  8bcf                 mov ecx, edi
// 006585ad  e89e98f7ff           call 0x5d1e50
// 006585b2  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 006585ba  85f6                 test esi, esi
// 006585bc  742a                 je 0x6585e8
// 006585be  8d4604               lea eax, [esi + 4]
// 006585c1  83c9ff               or ecx, 0xffffffff
// 006585c4  f00fc108             lock xadd dword ptr [eax], ecx
// 006585c8  751e                 jne 0x6585e8
// 006585ca  8b16                 mov edx, dword ptr [esi]
// 006585cc  8b4204               mov eax, dword ptr [edx + 4]
// 006585cf  8bce                 mov ecx, esi
// 006585d1  ffd0                 call eax
// 006585d3  8d4e08               lea ecx, [esi + 8]
// 006585d6  83caff               or edx, 0xffffffff
// 006585d9  f00fc111             lock xadd dword ptr [ecx], edx
// 006585dd  7509                 jne 0x6585e8
// 006585df  8b06                 mov eax, dword ptr [esi]
// 006585e1  8b5008               mov edx, dword ptr [eax + 8]
// 006585e4  8bce                 mov ecx, esi
// 006585e6  ffd2                 call edx
// 006585e8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006585ec  8bc7                 mov eax, edi
// 006585ee  5f                   pop edi
// 006585ef  5e                   pop esi
// 006585f0  5d                   pop ebp
// 006585f1  5b                   pop ebx
// 006585f2  64890d00000000       mov dword ptr fs:[0], ecx
// 006585f9  83c438               add esp, 0x38
// 006585fc  c20800               ret 8
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
