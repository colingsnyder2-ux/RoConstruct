// from server: 100% by EspClaude
// roc 2009-06 0045e7c0  unit: RBX::Stats::N::?$TypedStatsItem  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045e7c0
//
// 0045e7c0  6aff                 push -1
// 0045e7c2  6831c48500           push 0x85c431
// 0045e7c7  64a100000000         mov eax, dword ptr fs:[0]
// 0045e7cd  50                   push eax
// 0045e7ce  64892500000000       mov dword ptr fs:[0], esp
// 0045e7d5  83ec2c               sub esp, 0x2c
// 0045e7d8  8b442440             mov eax, dword ptr [esp + 0x40]
// 0045e7dc  53                   push ebx
// 0045e7dd  55                   push ebp
// 0045e7de  56                   push esi
// 0045e7df  57                   push edi
// 0045e7e0  8bd9                 mov ebx, ecx
// 0045e7e2  50                   push eax
// 0045e7e3  8d4c241c             lea ecx, [esp + 0x1c]
// 0045e7e7  51                   push ecx
// 0045e7e8  e853feffff           call 0x45e640
// 0045e7ed  8b7004               mov esi, dword ptr [eax + 4]
// 0045e7f0  8b38                 mov edi, dword ptr [eax]
// 0045e7f2  83c408               add esp, 8
// 0045e7f5  897c2410             mov dword ptr [esp + 0x10], edi
// 0045e7f9  89742414             mov dword ptr [esp + 0x14], esi
// 0045e7fd  85f6                 test esi, esi
// 0045e7ff  740c                 je 0x45e80d
// 0045e801  8d5604               lea edx, [esi + 4]
// 0045e804  b801000000           mov eax, 1
// 0045e809  f00fc102             lock xadd dword ptr [edx], eax
// 0045e80d  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0045e811  c744244400000000     mov dword ptr [esp + 0x44], 0
// 0045e819  85ed                 test ebp, ebp
// 0045e81b  742c                 je 0x45e849
// 0045e81d  8d4d04               lea ecx, [ebp + 4]
// 0045e820  83caff               or edx, 0xffffffff
// 0045e823  f00fc111             lock xadd dword ptr [ecx], edx
// 0045e827  7520                 jne 0x45e849
// 0045e829  8b4500               mov eax, dword ptr [ebp]
// 0045e82c  8b5004               mov edx, dword ptr [eax + 4]
// 0045e82f  8bcd                 mov ecx, ebp
// 0045e831  ffd2                 call edx
// 0045e833  8d4508               lea eax, [ebp + 8]
// 0045e836  83c9ff               or ecx, 0xffffffff
// 0045e839  f00fc108             lock xadd dword ptr [eax], ecx
// 0045e83d  750a                 jne 0x45e849
// 0045e83f  8b5500               mov edx, dword ptr [ebp]
// 0045e842  8b4208               mov eax, dword ptr [edx + 8]
// 0045e845  8bcd                 mov ecx, ebp
// 0045e847  ffd0                 call eax
// 0045e849  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0045e84d  51                   push ecx
// 0045e84e  8d4c2424             lea ecx, [esp + 0x24]
// 0045e852  ff15b4e48900         call dword ptr [0x89e4b4]
// 0045e858  8b17                 mov edx, dword ptr [edi]
// 0045e85a  8b5204               mov edx, dword ptr [edx + 4]
// 0045e85d  8d442420             lea eax, [esp + 0x20]
// 0045e861  50                   push eax
// 0045e862  8bcf                 mov ecx, edi
// 0045e864  c644244801           mov byte ptr [esp + 0x48], 1
// 0045e869  ffd2                 call edx
// 0045e86b  8d4c2420             lea ecx, [esp + 0x20]
// 0045e86f  c644244400           mov byte ptr [esp + 0x44], 0
// 0045e874  ff15c4e48900         call dword ptr [0x89e4c4]
// 0045e87a  53                   push ebx
// 0045e87b  8bcf                 mov ecx, edi
// 0045e87d  e8ce351700           call 0x5d1e50
// 0045e882  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 0045e88a  85f6                 test esi, esi
// 0045e88c  742a                 je 0x45e8b8
// 0045e88e  8d4604               lea eax, [esi + 4]
// 0045e891  83c9ff               or ecx, 0xffffffff
// 0045e894  f00fc108             lock xadd dword ptr [eax], ecx
// 0045e898  751e                 jne 0x45e8b8
// 0045e89a  8b16                 mov edx, dword ptr [esi]
// 0045e89c  8b4204               mov eax, dword ptr [edx + 4]
// 0045e89f  8bce                 mov ecx, esi
// 0045e8a1  ffd0                 call eax
// 0045e8a3  8d4e08               lea ecx, [esi + 8]
// 0045e8a6  83caff               or edx, 0xffffffff
// 0045e8a9  f00fc111             lock xadd dword ptr [ecx], edx
// 0045e8ad  7509                 jne 0x45e8b8
// 0045e8af  8b06                 mov eax, dword ptr [esi]
// 0045e8b1  8b5008               mov edx, dword ptr [eax + 8]
// 0045e8b4  8bce                 mov ecx, esi
// 0045e8b6  ffd2                 call edx
// 0045e8b8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0045e8bc  8bc7                 mov eax, edi
// 0045e8be  5f                   pop edi
// 0045e8bf  5e                   pop esi
// 0045e8c0  5d                   pop ebp
// 0045e8c1  5b                   pop ebx
// 0045e8c2  64890d00000000       mov dword ptr fs:[0], ecx
// 0045e8c9  83c438               add esp, 0x38
// 0045e8cc  c20800               ret 8
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
