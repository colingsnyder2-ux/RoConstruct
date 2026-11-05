// from server: 100% by EspClaude
// roc 2009-06 004ed970  unit: RBX::Network::VSharedStringDictionary::?$sp_counted_impl_p  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ed970
//
// 004ed970  6aff                 push -1
// 004ed972  6831c48500           push 0x85c431
// 004ed977  64a100000000         mov eax, dword ptr fs:[0]
// 004ed97d  50                   push eax
// 004ed97e  64892500000000       mov dword ptr fs:[0], esp
// 004ed985  83ec2c               sub esp, 0x2c
// 004ed988  8b442440             mov eax, dword ptr [esp + 0x40]
// 004ed98c  53                   push ebx
// 004ed98d  55                   push ebp
// 004ed98e  56                   push esi
// 004ed98f  57                   push edi
// 004ed990  8bd9                 mov ebx, ecx
// 004ed992  50                   push eax
// 004ed993  8d4c241c             lea ecx, [esp + 0x1c]
// 004ed997  51                   push ecx
// 004ed998  e8f3fcffff           call 0x4ed690
// 004ed99d  8b7004               mov esi, dword ptr [eax + 4]
// 004ed9a0  8b38                 mov edi, dword ptr [eax]
// 004ed9a2  83c408               add esp, 8
// 004ed9a5  897c2410             mov dword ptr [esp + 0x10], edi
// 004ed9a9  89742414             mov dword ptr [esp + 0x14], esi
// 004ed9ad  85f6                 test esi, esi
// 004ed9af  740c                 je 0x4ed9bd
// 004ed9b1  8d5604               lea edx, [esi + 4]
// 004ed9b4  b801000000           mov eax, 1
// 004ed9b9  f00fc102             lock xadd dword ptr [edx], eax
// 004ed9bd  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004ed9c1  c744244400000000     mov dword ptr [esp + 0x44], 0
// 004ed9c9  85ed                 test ebp, ebp
// 004ed9cb  742c                 je 0x4ed9f9
// 004ed9cd  8d4d04               lea ecx, [ebp + 4]
// 004ed9d0  83caff               or edx, 0xffffffff
// 004ed9d3  f00fc111             lock xadd dword ptr [ecx], edx
// 004ed9d7  7520                 jne 0x4ed9f9
// 004ed9d9  8b4500               mov eax, dword ptr [ebp]
// 004ed9dc  8b5004               mov edx, dword ptr [eax + 4]
// 004ed9df  8bcd                 mov ecx, ebp
// 004ed9e1  ffd2                 call edx
// 004ed9e3  8d4508               lea eax, [ebp + 8]
// 004ed9e6  83c9ff               or ecx, 0xffffffff
// 004ed9e9  f00fc108             lock xadd dword ptr [eax], ecx
// 004ed9ed  750a                 jne 0x4ed9f9
// 004ed9ef  8b5500               mov edx, dword ptr [ebp]
// 004ed9f2  8b4208               mov eax, dword ptr [edx + 8]
// 004ed9f5  8bcd                 mov ecx, ebp
// 004ed9f7  ffd0                 call eax
// 004ed9f9  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004ed9fd  51                   push ecx
// 004ed9fe  8d4c2424             lea ecx, [esp + 0x24]
// 004eda02  ff15b4e48900         call dword ptr [0x89e4b4]
// 004eda08  8b17                 mov edx, dword ptr [edi]
// 004eda0a  8b5204               mov edx, dword ptr [edx + 4]
// 004eda0d  8d442420             lea eax, [esp + 0x20]
// 004eda11  50                   push eax
// 004eda12  8bcf                 mov ecx, edi
// 004eda14  c644244801           mov byte ptr [esp + 0x48], 1
// 004eda19  ffd2                 call edx
// 004eda1b  8d4c2420             lea ecx, [esp + 0x20]
// 004eda1f  c644244400           mov byte ptr [esp + 0x44], 0
// 004eda24  ff15c4e48900         call dword ptr [0x89e4c4]
// 004eda2a  53                   push ebx
// 004eda2b  8bcf                 mov ecx, edi
// 004eda2d  e81e440e00           call 0x5d1e50
// 004eda32  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 004eda3a  85f6                 test esi, esi
// 004eda3c  742a                 je 0x4eda68
// 004eda3e  8d4604               lea eax, [esi + 4]
// 004eda41  83c9ff               or ecx, 0xffffffff
// 004eda44  f00fc108             lock xadd dword ptr [eax], ecx
// 004eda48  751e                 jne 0x4eda68
// 004eda4a  8b16                 mov edx, dword ptr [esi]
// 004eda4c  8b4204               mov eax, dword ptr [edx + 4]
// 004eda4f  8bce                 mov ecx, esi
// 004eda51  ffd0                 call eax
// 004eda53  8d4e08               lea ecx, [esi + 8]
// 004eda56  83caff               or edx, 0xffffffff
// 004eda59  f00fc111             lock xadd dword ptr [ecx], edx
// 004eda5d  7509                 jne 0x4eda68
// 004eda5f  8b06                 mov eax, dword ptr [esi]
// 004eda61  8b5008               mov edx, dword ptr [eax + 8]
// 004eda64  8bce                 mov ecx, esi
// 004eda66  ffd2                 call edx
// 004eda68  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004eda6c  8bc7                 mov eax, edi
// 004eda6e  5f                   pop edi
// 004eda6f  5e                   pop esi
// 004eda70  5d                   pop ebp
// 004eda71  5b                   pop ebx
// 004eda72  64890d00000000       mov dword ptr fs:[0], ecx
// 004eda79  83c438               add esp, 0x38
// 004eda7c  c20800               ret 8
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
