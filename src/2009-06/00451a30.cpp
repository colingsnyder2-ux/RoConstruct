// from server: 86% by EspClaude
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
    unsigned char data[12];
    Guard(Shared);
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
    unsigned char padding[148];
    Provider* provider;
    void f(Receiver*);
};

void CRobloxDoc::f(Receiver* receiver)
{
    Shared shared = provider->acquire();
    Guard guard(shared);
    Worker* worker = shared.object->worker();
    Text text;
    receiver->table->set_result(receiver, worker->query(&text, 0));
    Message message;
    format_message(&message, 130, text.c_str());
    MessageSetter* setter = &receiver->table->set_message;
    const char* value = message.text();
    (*setter)(receiver, value);
}
