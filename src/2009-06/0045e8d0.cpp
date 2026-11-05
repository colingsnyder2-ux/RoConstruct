// from server: 100% by EspClaude
// roc 2009-06 0045e8d0  unit: RBX::Stats::N::?$TypedStatsItem  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045e8d0
//
// 0045e8d0  6aff                 push -1
// 0045e8d2  6831c48500           push 0x85c431
// 0045e8d7  64a100000000         mov eax, dword ptr fs:[0]
// 0045e8dd  50                   push eax
// 0045e8de  64892500000000       mov dword ptr fs:[0], esp
// 0045e8e5  83ec2c               sub esp, 0x2c
// 0045e8e8  8b442440             mov eax, dword ptr [esp + 0x40]
// 0045e8ec  53                   push ebx
// 0045e8ed  55                   push ebp
// 0045e8ee  56                   push esi
// 0045e8ef  57                   push edi
// 0045e8f0  8bd9                 mov ebx, ecx
// 0045e8f2  50                   push eax
// 0045e8f3  8d4c241c             lea ecx, [esp + 0x1c]
// 0045e8f7  51                   push ecx
// 0045e8f8  e803feffff           call 0x45e700
// 0045e8fd  8b7004               mov esi, dword ptr [eax + 4]
// 0045e900  8b38                 mov edi, dword ptr [eax]
// 0045e902  83c408               add esp, 8
// 0045e905  897c2410             mov dword ptr [esp + 0x10], edi
// 0045e909  89742414             mov dword ptr [esp + 0x14], esi
// 0045e90d  85f6                 test esi, esi
// 0045e90f  740c                 je 0x45e91d
// 0045e911  8d5604               lea edx, [esi + 4]
// 0045e914  b801000000           mov eax, 1
// 0045e919  f00fc102             lock xadd dword ptr [edx], eax
// 0045e91d  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0045e921  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0045e929  85ed                 test ebp, ebp
// 0045e92b  742c                 je 0x45e959
// 0045e92d  8d4d04               lea ecx, [ebp + 4]
// 0045e930  83caff               or edx, 0xffffffff
// 0045e933  f00fc111             lock xadd dword ptr [ecx], edx
// 0045e937  7520                 jne 0x45e959
// 0045e939  8b4500               mov eax, dword ptr [ebp]
// 0045e93c  8b5004               mov edx, dword ptr [eax + 4]
// 0045e93f  8bcd                 mov ecx, ebp
// 0045e941  ffd2                 call edx
// 0045e943  8d4508               lea eax, [ebp + 8]
// 0045e946  83c9ff               or ecx, 0xffffffff
// 0045e949  f00fc108             lock xadd dword ptr [eax], ecx
// 0045e94d  750a                 jne 0x45e959
// 0045e94f  8b5500               mov edx, dword ptr [ebp]
// 0045e952  8b4208               mov eax, dword ptr [edx + 8]
// 0045e955  8bcd                 mov ecx, ebp
// 0045e957  ffd0                 call eax
// 0045e959  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0045e95d  51                   push ecx
// 0045e95e  8d4c2424             lea ecx, [esp + 0x24]
// 0045e962  ff15b4e48900         call dword ptr [0x89e4b4]
// 0045e968  8b17                 mov edx, dword ptr [edi]
// 0045e96a  8b5204               mov edx, dword ptr [edx + 4]
// 0045e96d  8d442420             lea eax, [esp + 0x20]
// 0045e971  50                   push eax
// 0045e972  8bcf                 mov ecx, edi
// 0045e974  c644244801           mov byte ptr [esp + 0x48], 1
// 0045e979  ffd2                 call edx
// 0045e97b  8d4c2420             lea ecx, [esp + 0x20]
// 0045e97f  c644244400           mov byte ptr [esp + 0x44], 0
// 0045e984  ff15c4e48900         call dword ptr [0x89e4c4]
// 0045e98a  53                   push ebx
// 0045e98b  8bcf                 mov ecx, edi
// 0045e98d  e8be341700           call 0x5d1e50
// 0045e992  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 0045e99a  85f6                 test esi, esi
// 0045e99c  742a                 je 0x45e9c8
// 0045e99e  8d4604               lea eax, [esi + 4]
// 0045e9a1  83c9ff               or ecx, 0xffffffff
// 0045e9a4  f00fc108             lock xadd dword ptr [eax], ecx
// 0045e9a8  751e                 jne 0x45e9c8
// 0045e9aa  8b16                 mov edx, dword ptr [esi]
// 0045e9ac  8b4204               mov eax, dword ptr [edx + 4]
// 0045e9af  8bce                 mov ecx, esi
// 0045e9b1  ffd0                 call eax
// 0045e9b3  8d4e08               lea ecx, [esi + 8]
// 0045e9b6  83caff               or edx, 0xffffffff
// 0045e9b9  f00fc111             lock xadd dword ptr [ecx], edx
// 0045e9bd  7509                 jne 0x45e9c8
// 0045e9bf  8b06                 mov eax, dword ptr [esi]
// 0045e9c1  8b5008               mov edx, dword ptr [eax + 8]
// 0045e9c4  8bce                 mov ecx, esi
// 0045e9c6  ffd2                 call edx
// 0045e9c8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0045e9cc  8bc7                 mov eax, edi
// 0045e9ce  5f                   pop edi
// 0045e9cf  5e                   pop esi
// 0045e9d0  5d                   pop ebp
// 0045e9d1  5b                   pop ebx
// 0045e9d2  64890d00000000       mov dword ptr fs:[0], ecx
// 0045e9d9  83c438               add esp, 0x38
// 0045e9dc  c20800               ret 8
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
