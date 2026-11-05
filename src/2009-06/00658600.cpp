// from server: 100% by EspClaude
// roc 2009-06 00658600  unit: VProfilingItem::?$BoundFuncDesc  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00658600
//
// 00658600  6aff                 push -1
// 00658602  6831c48500           push 0x85c431
// 00658607  64a100000000         mov eax, dword ptr fs:[0]
// 0065860d  50                   push eax
// 0065860e  64892500000000       mov dword ptr fs:[0], esp
// 00658615  83ec2c               sub esp, 0x2c
// 00658618  8b442440             mov eax, dword ptr [esp + 0x40]
// 0065861c  53                   push ebx
// 0065861d  55                   push ebp
// 0065861e  56                   push esi
// 0065861f  57                   push edi
// 00658620  8bd9                 mov ebx, ecx
// 00658622  50                   push eax
// 00658623  8d4c241c             lea ecx, [esp + 0x1c]
// 00658627  51                   push ecx
// 00658628  e823feffff           call 0x658450
// 0065862d  8b7004               mov esi, dword ptr [eax + 4]
// 00658630  8b38                 mov edi, dword ptr [eax]
// 00658632  83c408               add esp, 8
// 00658635  897c2410             mov dword ptr [esp + 0x10], edi
// 00658639  89742414             mov dword ptr [esp + 0x14], esi
// 0065863d  85f6                 test esi, esi
// 0065863f  740c                 je 0x65864d
// 00658641  8d5604               lea edx, [esi + 4]
// 00658644  b801000000           mov eax, 1
// 00658649  f00fc102             lock xadd dword ptr [edx], eax
// 0065864d  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00658651  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00658659  85ed                 test ebp, ebp
// 0065865b  742c                 je 0x658689
// 0065865d  8d4d04               lea ecx, [ebp + 4]
// 00658660  83caff               or edx, 0xffffffff
// 00658663  f00fc111             lock xadd dword ptr [ecx], edx
// 00658667  7520                 jne 0x658689
// 00658669  8b4500               mov eax, dword ptr [ebp]
// 0065866c  8b5004               mov edx, dword ptr [eax + 4]
// 0065866f  8bcd                 mov ecx, ebp
// 00658671  ffd2                 call edx
// 00658673  8d4508               lea eax, [ebp + 8]
// 00658676  83c9ff               or ecx, 0xffffffff
// 00658679  f00fc108             lock xadd dword ptr [eax], ecx
// 0065867d  750a                 jne 0x658689
// 0065867f  8b5500               mov edx, dword ptr [ebp]
// 00658682  8b4208               mov eax, dword ptr [edx + 8]
// 00658685  8bcd                 mov ecx, ebp
// 00658687  ffd0                 call eax
// 00658689  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0065868d  51                   push ecx
// 0065868e  8d4c2424             lea ecx, [esp + 0x24]
// 00658692  ff15b4e48900         call dword ptr [0x89e4b4]
// 00658698  8b17                 mov edx, dword ptr [edi]
// 0065869a  8b5204               mov edx, dword ptr [edx + 4]
// 0065869d  8d442420             lea eax, [esp + 0x20]
// 006586a1  50                   push eax
// 006586a2  8bcf                 mov ecx, edi
// 006586a4  c644244801           mov byte ptr [esp + 0x48], 1
// 006586a9  ffd2                 call edx
// 006586ab  8d4c2420             lea ecx, [esp + 0x20]
// 006586af  c644244400           mov byte ptr [esp + 0x44], 0
// 006586b4  ff15c4e48900         call dword ptr [0x89e4c4]
// 006586ba  53                   push ebx
// 006586bb  8bcf                 mov ecx, edi
// 006586bd  e88e97f7ff           call 0x5d1e50
// 006586c2  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 006586ca  85f6                 test esi, esi
// 006586cc  742a                 je 0x6586f8
// 006586ce  8d4604               lea eax, [esi + 4]
// 006586d1  83c9ff               or ecx, 0xffffffff
// 006586d4  f00fc108             lock xadd dword ptr [eax], ecx
// 006586d8  751e                 jne 0x6586f8
// 006586da  8b16                 mov edx, dword ptr [esi]
// 006586dc  8b4204               mov eax, dword ptr [edx + 4]
// 006586df  8bce                 mov ecx, esi
// 006586e1  ffd0                 call eax
// 006586e3  8d4e08               lea ecx, [esi + 8]
// 006586e6  83caff               or edx, 0xffffffff
// 006586e9  f00fc111             lock xadd dword ptr [ecx], edx
// 006586ed  7509                 jne 0x6586f8
// 006586ef  8b06                 mov eax, dword ptr [esi]
// 006586f1  8b5008               mov edx, dword ptr [eax + 8]
// 006586f4  8bce                 mov ecx, esi
// 006586f6  ffd2                 call edx
// 006586f8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006586fc  8bc7                 mov eax, edi
// 006586fe  5f                   pop edi
// 006586ff  5e                   pop esi
// 00658700  5d                   pop ebp
// 00658701  5b                   pop ebx
// 00658702  64890d00000000       mov dword ptr fs:[0], ecx
// 00658709  83c438               add esp, 0x38
// 0065870c  c20800               ret 8
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
