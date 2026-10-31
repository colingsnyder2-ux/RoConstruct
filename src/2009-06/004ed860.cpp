// from server: 100% by EspClaude
// roc 2009-06 004ed860  unit: RBX::Network::VSharedStringDictionary::?$sp_counted_impl_p  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ed860
//
// 004ed860  6aff                 push -1
// 004ed862  6831c48500           push 0x85c431
// 004ed867  64a100000000         mov eax, dword ptr fs:[0]
// 004ed86d  50                   push eax
// 004ed86e  64892500000000       mov dword ptr fs:[0], esp
// 004ed875  83ec2c               sub esp, 0x2c
// 004ed878  8b442440             mov eax, dword ptr [esp + 0x40]
// 004ed87c  53                   push ebx
// 004ed87d  55                   push ebp
// 004ed87e  56                   push esi
// 004ed87f  57                   push edi
// 004ed880  8bd9                 mov ebx, ecx
// 004ed882  50                   push eax
// 004ed883  8d4c241c             lea ecx, [esp + 0x1c]
// 004ed887  51                   push ecx
// 004ed888  e843fdffff           call 0x4ed5d0
// 004ed88d  8b7004               mov esi, dword ptr [eax + 4]
// 004ed890  8b38                 mov edi, dword ptr [eax]
// 004ed892  83c408               add esp, 8
// 004ed895  897c2410             mov dword ptr [esp + 0x10], edi
// 004ed899  89742414             mov dword ptr [esp + 0x14], esi
// 004ed89d  85f6                 test esi, esi
// 004ed89f  740c                 je 0x4ed8ad
// 004ed8a1  8d5604               lea edx, [esi + 4]
// 004ed8a4  b801000000           mov eax, 1
// 004ed8a9  f00fc102             lock xadd dword ptr [edx], eax
// 004ed8ad  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004ed8b1  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004ed8b9  85ed                 test ebp, ebp
// 004ed8bb  742c                 je 0x4ed8e9
// 004ed8bd  8d4d04               lea ecx, [ebp + 4]
// 004ed8c0  83caff               or edx, 0xffffffff
// 004ed8c3  f00fc111             lock xadd dword ptr [ecx], edx
// 004ed8c7  7520                 jne 0x4ed8e9
// 004ed8c9  8b4500               mov eax, dword ptr [ebp]
// 004ed8cc  8b5004               mov edx, dword ptr [eax + 4]
// 004ed8cf  8bcd                 mov ecx, ebp
// 004ed8d1  ffd2                 call edx
// 004ed8d3  8d4508               lea eax, [ebp + 8]
// 004ed8d6  83c9ff               or ecx, 0xffffffff
// 004ed8d9  f00fc108             lock xadd dword ptr [eax], ecx
// 004ed8dd  750a                 jne 0x4ed8e9
// 004ed8df  8b5500               mov edx, dword ptr [ebp]
// 004ed8e2  8b4208               mov eax, dword ptr [edx + 8]
// 004ed8e5  8bcd                 mov ecx, ebp
// 004ed8e7  ffd0                 call eax
// 004ed8e9  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004ed8ed  51                   push ecx
// 004ed8ee  8d4c2424             lea ecx, [esp + 0x24]
// 004ed8f2  ff15b4e48900         call dword ptr [0x89e4b4]
// 004ed8f8  8b17                 mov edx, dword ptr [edi]
// 004ed8fa  8b5204               mov edx, dword ptr [edx + 4]
// 004ed8fd  8d442420             lea eax, [esp + 0x20]
// 004ed901  50                   push eax
// 004ed902  8bcf                 mov ecx, edi
// 004ed904  c644244801           mov byte ptr [esp + 0x48], 1
// 004ed909  ffd2                 call edx
// 004ed90b  8d4c2420             lea ecx, [esp + 0x20]
// 004ed90f  c644244400           mov byte ptr [esp + 0x44], 0
// 004ed914  ff15c4e48900         call dword ptr [0x89e4c4]
// 004ed91a  53                   push ebx
// 004ed91b  8bcf                 mov ecx, edi
// 004ed91d  e82e450e00           call 0x5d1e50
// 004ed922  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 004ed92a  85f6                 test esi, esi
// 004ed92c  742a                 je 0x4ed958
// 004ed92e  8d4604               lea eax, [esi + 4]
// 004ed931  83c9ff               or ecx, 0xffffffff
// 004ed934  f00fc108             lock xadd dword ptr [eax], ecx
// 004ed938  751e                 jne 0x4ed958
// 004ed93a  8b16                 mov edx, dword ptr [esi]
// 004ed93c  8b4204               mov eax, dword ptr [edx + 4]
// 004ed93f  8bce                 mov ecx, esi
// 004ed941  ffd0                 call eax
// 004ed943  8d4e08               lea ecx, [esi + 8]
// 004ed946  83caff               or edx, 0xffffffff
// 004ed949  f00fc111             lock xadd dword ptr [ecx], edx
// 004ed94d  7509                 jne 0x4ed958
// 004ed94f  8b06                 mov eax, dword ptr [esi]
// 004ed951  8b5008               mov edx, dword ptr [eax + 8]
// 004ed954  8bce                 mov ecx, esi
// 004ed956  ffd2                 call edx
// 004ed958  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004ed95c  8bc7                 mov eax, edi
// 004ed95e  5f                   pop edi
// 004ed95f  5e                   pop esi
// 004ed960  5d                   pop ebp
// 004ed961  5b                   pop ebx
// 004ed962  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed969  83c438               add esp, 0x38
// 004ed96c  c20800               ret 8
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
