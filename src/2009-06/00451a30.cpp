// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 00451a30  unit: CRobloxDoc  size: 352 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00451a30
//
// 00451a30  6aff                 push -1
// 00451a32  6802178500           push 0x851702
// 00451a37  64a100000000         mov eax, dword ptr fs:[0]
// 00451a3d  50                   push eax
// 00451a3e  64892500000000       mov dword ptr fs:[0], esp
// 00451a45  83ec30               sub esp, 0x30
// 00451a48  8b899c000000         mov ecx, dword ptr [ecx + 0x9c]
// 00451a4e  55                   push ebp
// 00451a4f  56                   push esi
// 00451a50  57                   push edi
// 00451a51  8d442418             lea eax, [esp + 0x18]
// 00451a55  50                   push eax
// 00451a56  e8d5301d00           call 0x624b30
// 00451a5b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00451a5f  6a01                 push 1
// 00451a61  83ec08               sub esp, 8
// 00451a64  8bc4                 mov eax, esp
// 00451a66  8908                 mov dword ptr [eax], ecx
// 00451a68  8b542428             mov edx, dword ptr [esp + 0x28]
// 00451a6c  895004               mov dword ptr [eax + 4], edx
// 00451a6f  8b442428             mov eax, dword ptr [esp + 0x28]
// 00451a73  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00451a7b  89642420             mov dword ptr [esp + 0x20], esp
// 00451a7f  85c0                 test eax, eax
// 00451a81  740c                 je 0x451a8f
// 00451a83  83c004               add eax, 4
// 00451a86  b901000000           mov ecx, 1
// 00451a8b  f00fc108             lock xadd dword ptr [eax], ecx
// 00451a8f  8d4c241c             lea ecx, [esp + 0x1c]
// 00451a93  e878201b00           call 0x603b10
// 00451a98  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00451a9c  c644244401           mov byte ptr [esp + 0x44], 1
// 00451aa1  e86a88ffff           call 0x44a310
// 00451aa6  8d4c2420             lea ecx, [esp + 0x20]
// 00451aaa  8bf8                 mov edi, eax
// 00451aac  ff15c0e48900         call dword ptr [0x89e4c0]
// 00451ab2  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 00451ab6  8b2e                 mov ebp, dword ptr [esi]
// 00451ab8  6a00                 push 0
// 00451aba  8d542424             lea edx, [esp + 0x24]
// 00451abe  52                   push edx
// 00451abf  8bcf                 mov ecx, edi
// 00451ac1  c644244c02           mov byte ptr [esp + 0x4c], 2
// 00451ac6  e855711c00           call 0x618c20
// 00451acb  8b5500               mov edx, dword ptr [ebp]
// 00451ace  0fb6c0               movzx eax, al
// 00451ad1  50                   push eax
// 00451ad2  8bce                 mov ecx, esi
// 00451ad4  ffd2                 call edx
// 00451ad6  8d4c240c             lea ecx, [esp + 0xc]
// 00451ada  ff15bcfc8900         call dword ptr [0x89fcbc]
// 00451ae0  8d4c2420             lea ecx, [esp + 0x20]
// 00451ae4  c644244403           mov byte ptr [esp + 0x44], 3
// 00451ae9  ff15bce48900         call dword ptr [0x89e4bc]
// 00451aef  50                   push eax
// 00451af0  8d442410             lea eax, [esp + 0x10]
// 00451af4  6882000000           push 0x82
// 00451af9  50                   push eax
// 00451afa  ff1510028a00         call dword ptr [0x8a0210]
// 00451b00  8b3e                 mov edi, dword ptr [esi]
// 00451b02  83c40c               add esp, 0xc
// 00451b05  8d4c240c             lea ecx, [esp + 0xc]
// 00451b09  83c70c               add edi, 0xc
// 00451b0c  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00451b12  8b17                 mov edx, dword ptr [edi]
// 00451b14  50                   push eax
// 00451b15  8bce                 mov ecx, esi
// 00451b17  ffd2                 call edx
// 00451b19  8d4c240c             lea ecx, [esp + 0xc]
// 00451b1d  ff1510fd8900         call dword ptr [0x89fd10]
// 00451b23  8d4c2420             lea ecx, [esp + 0x20]
// 00451b27  c644244401           mov byte ptr [esp + 0x44], 1
// 00451b2c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00451b32  8d4c2410             lea ecx, [esp + 0x10]
// 00451b36  c644244400           mov byte ptr [esp + 0x44], 0
// 00451b3b  e860da1a00           call 0x5ff5a0
// 00451b40  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00451b44  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00451b4c  85c0                 test eax, eax
// 00451b4e  742c                 je 0x451b7c
// 00451b50  8bf0                 mov esi, eax
// 00451b52  83c004               add eax, 4
// 00451b55  83c9ff               or ecx, 0xffffffff
// 00451b58  f00fc108             lock xadd dword ptr [eax], ecx
// 00451b5c  751e                 jne 0x451b7c
// 00451b5e  8b16                 mov edx, dword ptr [esi]
// 00451b60  8b4204               mov eax, dword ptr [edx + 4]
// 00451b63  8bce                 mov ecx, esi
// 00451b65  ffd0                 call eax
// 00451b67  8d4e08               lea ecx, [esi + 8]
// 00451b6a  83caff               or edx, 0xffffffff
// 00451b6d  f00fc111             lock xadd dword ptr [ecx], edx
// 00451b71  7509                 jne 0x451b7c
// 00451b73  8b06                 mov eax, dword ptr [esi]
// 00451b75  8b5008               mov edx, dword ptr [eax + 8]
// 00451b78  8bce                 mov ecx, esi
// 00451b7a  ffd2                 call edx
// 00451b7c  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00451b80  5f                   pop edi
// 00451b81  5e                   pop esi
// 00451b82  64890d00000000       mov dword ptr fs:[0], ecx
// 00451b89  5d                   pop ebp
// 00451b8a  83c43c               add esp, 0x3c
// 00451b8d  c20400               ret 4

// from server: 100% by colin
// roc 2008-06 00453750  unit: CRobloxDoc  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00453750
//
// 00453750  6aff                 push -1
// 00453752  68221f7c00           push 0x7c1f22
// 00453757  64a100000000         mov eax, dword ptr fs:[0]
// 0045375d  50                   push eax
// 0045375e  64892500000000       mov dword ptr fs:[0], esp
// 00453765  83ec38               sub esp, 0x38
// 00453768  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 0045376e  55                   push ebp
// 0045376f  56                   push esi
// 00453770  57                   push edi
// 00453771  8d442414             lea eax, [esp + 0x14]
// 00453775  50                   push eax
// 00453776  e8c5710100           call 0x46a940
// 0045377b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0045377f  83ec08               sub esp, 8
// 00453782  8bc4                 mov eax, esp
// 00453784  8908                 mov dword ptr [eax], ecx
// 00453786  8b542420             mov edx, dword ptr [esp + 0x20]
// 0045378a  895004               mov dword ptr [eax + 4], edx
// 0045378d  8b442420             mov eax, dword ptr [esp + 0x20]
// 00453791  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00453799  89642418             mov dword ptr [esp + 0x18], esp
// 0045379d  85c0                 test eax, eax
// 0045379f  740c                 je 0x4537ad
// 004537a1  83c004               add eax, 4
// 004537a4  b901000000           mov ecx, 1
// 004537a9  f00fc108             lock xadd dword ptr [eax], ecx
// 004537ad  8d4c2424             lea ecx, [esp + 0x24]
// 004537b1  e88ae3fbff           call 0x411b40
// 004537b6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004537ba  c644244c01           mov byte ptr [esp + 0x4c], 1
// 004537bf  e83cf8ffff           call 0x453000
// 004537c4  8d4c2428             lea ecx, [esp + 0x28]
// 004537c8  8bf8                 mov edi, eax
// 004537ca  ff1560248000         call dword ptr [0x802460]
// 004537d0  8b742454             mov esi, dword ptr [esp + 0x54]
// 004537d4  8b2e                 mov ebp, dword ptr [esi]
// 004537d6  6a00                 push 0
// 004537d8  8d54242c             lea edx, [esp + 0x2c]
// 004537dc  52                   push edx
// 004537dd  8bcf                 mov ecx, edi
// 004537df  c644245402           mov byte ptr [esp + 0x54], 2
// 004537e4  e887431300           call 0x587b70
// 004537e9  8b5500               mov edx, dword ptr [ebp]
// 004537ec  0fb6c0               movzx eax, al
// 004537ef  50                   push eax
// 004537f0  8bce                 mov ecx, esi
// 004537f2  ffd2                 call edx
// 004537f4  8d4c240c             lea ecx, [esp + 0xc]
// 004537f8  ff15043f8000         call dword ptr [0x803f04]
// 004537fe  8d4c2428             lea ecx, [esp + 0x28]
// 00453802  c644244c03           mov byte ptr [esp + 0x4c], 3
// 00453807  ff1564248000         call dword ptr [0x802464]
// 0045380d  50                   push eax
// 0045380e  8d442410             lea eax, [esp + 0x10]
// 00453812  6882000000           push 0x82
// 00453817  50                   push eax
// 00453818  ff15c4328000         call dword ptr [0x8032c4]
// 0045381e  8b3e                 mov edi, dword ptr [esi]
// 00453820  83c40c               add esp, 0xc
// 00453823  8d4c240c             lea ecx, [esp + 0xc]
// 00453827  83c70c               add edi, 0xc
// 0045382a  ff15e03e8000         call dword ptr [0x803ee0]
// 00453830  8b17                 mov edx, dword ptr [edi]
// 00453832  50                   push eax
// 00453833  8bce                 mov ecx, esi
// 00453835  ffd2                 call edx
// 00453837  8d4c240c             lea ecx, [esp + 0xc]
// 0045383b  ff15143f8000         call dword ptr [0x803f14]
// 00453841  8d4c2428             lea ecx, [esp + 0x28]
// 00453845  c644244c01           mov byte ptr [esp + 0x4c], 1
// 0045384a  ff1568248000         call dword ptr [0x802468]
// 00453850  8d4c241c             lea ecx, [esp + 0x1c]
// 00453854  c644244c00           mov byte ptr [esp + 0x4c], 0
// 00453859  e8623b1200           call 0x5773c0
// 0045385e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00453862  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 0045386a  85c0                 test eax, eax
// 0045386c  742c                 je 0x45389a
// 0045386e  8bf0                 mov esi, eax
// 00453870  83c004               add eax, 4
// 00453873  83c9ff               or ecx, 0xffffffff
// 00453876  f00fc108             lock xadd dword ptr [eax], ecx
// 0045387a  751e                 jne 0x45389a
// 0045387c  8b16                 mov edx, dword ptr [esi]
// 0045387e  8b4204               mov eax, dword ptr [edx + 4]
// 00453881  8bce                 mov ecx, esi
// 00453883  ffd0                 call eax
// 00453885  8d4e08               lea ecx, [esi + 8]
// 00453888  83caff               or edx, 0xffffffff
// 0045388b  f00fc111             lock xadd dword ptr [ecx], edx
// 0045388f  7509                 jne 0x45389a
// 00453891  8b06                 mov eax, dword ptr [esi]
// 00453893  8b5008               mov edx, dword ptr [eax + 8]
// 00453896  8bce                 mov ecx, esi
// 00453898  ffd2                 call edx
// 0045389a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0045389e  5f                   pop edi
// 0045389f  5e                   pop esi
// 004538a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004538a7  5d                   pop ebp
// 004538a8  83c444               add esp, 0x44
// 004538ab  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long use_count;
    volatile long weak_count;
};

struct Object;
struct Shared {
    Object* object;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->use_count;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->use_count) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak_count) == 0)
                p->destroy();
        }
    }
}

struct Text {
    unsigned char data[28];
    Text();
    ~Text();
    const char* c_str() const;
};

extern void (__thiscall* text_construct)(Text*);
extern void (__thiscall* text_destroy)(Text*);
extern const char* (__thiscall* text_data)(const Text*);

inline Text::Text()
{
    text_construct(this);
}

inline Text::~Text()
{
    text_destroy(this);
}

inline const char* Text::c_str() const
{
    return text_data(this);
}

struct Message {
    void* data;
    Message();
    __declspec(nothrow) ~Message();
    const char* text() const;

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

extern void (__thiscall* message_construct)(Message*);
extern void (__thiscall* message_destroy)(Message*);
extern const char* (__thiscall* message_data)(const Message*);
extern void (__cdecl* format_message)(Message*, unsigned int, const char*);

inline Message::Message()
{
    message_construct(this);
}

inline Message::~Message()
{
    destroyImport();
}

inline const char* Message::text() const
{
    return message_data(this);
}

struct Worker {
    bool query(Text*, int);
};

struct Object {
    Worker* worker();
};

struct Provider {
    Shared acquire();
};

struct Guard {
    unsigned char data[4];
    Guard(Shared, bool);
    ~Guard();
};

struct Receiver;
typedef void (__thiscall* MessageSetter)(Receiver*, const char*);

struct ReceiverTable {
    void (__thiscall* set_result)(Receiver*, int);
    void (__thiscall* reserved1)(Receiver*);
    void (__thiscall* reserved2)(Receiver*);
    MessageSetter set_message;
};

struct Receiver {
    ReceiverTable* table;
};

struct CRobloxDoc {
    unsigned char padding[0x9c];
    Provider* provider;
    void f(Receiver*);
};

void CRobloxDoc::f(Receiver* receiver)
{
    Shared shared = provider->acquire();
    Guard guard(shared, true);
    Worker* worker = shared.object->worker();
    Text text;
    receiver->table->set_result(receiver, worker->query(&text, 0));
    Message message;
    format_message(&message, 130, text.c_str());
    MessageSetter* setter = &receiver->table->set_message;
    const char* value = message.text();
    (*setter)(receiver, value);
}
