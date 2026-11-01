// from server: 86% by EspClaude
// from server: 100% by colin
// roc 2008-06 00453990  unit: CRobloxDoc  size: 350 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00453990
//
// 00453990  6aff                 push -1
// 00453992  68221f7c00           push 0x7c1f22
// 00453997  64a100000000         mov eax, dword ptr fs:[0]
// 0045399d  50                   push eax
// 0045399e  64892500000000       mov dword ptr fs:[0], esp
// 004539a5  83ec38               sub esp, 0x38
// 004539a8  8b8994000000         mov ecx, dword ptr [ecx + 0x94]
// 004539ae  55                   push ebp
// 004539af  56                   push esi
// 004539b0  57                   push edi
// 004539b1  8d442414             lea eax, [esp + 0x14]
// 004539b5  50                   push eax
// 004539b6  e8856f0100           call 0x46a940
// 004539bb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004539bf  83ec08               sub esp, 8
// 004539c2  8bc4                 mov eax, esp
// 004539c4  8908                 mov dword ptr [eax], ecx
// 004539c6  8b542420             mov edx, dword ptr [esp + 0x20]
// 004539ca  895004               mov dword ptr [eax + 4], edx
// 004539cd  8b442420             mov eax, dword ptr [esp + 0x20]
// 004539d1  c744245400000000     mov dword ptr [esp + 0x54], 0
// 004539d9  89642418             mov dword ptr [esp + 0x18], esp
// 004539dd  85c0                 test eax, eax
// 004539df  740c                 je 0x4539ed
// 004539e1  83c004               add eax, 4
// 004539e4  b901000000           mov ecx, 1
// 004539e9  f00fc108             lock xadd dword ptr [eax], ecx
// 004539ed  8d4c2424             lea ecx, [esp + 0x24]
// 004539f1  e84ae1fbff           call 0x411b40
// 004539f6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004539fa  c644244c01           mov byte ptr [esp + 0x4c], 1
// 004539ff  e8fcf5ffff           call 0x453000
// 00453a04  8d4c2428             lea ecx, [esp + 0x28]
// 00453a08  8bf8                 mov edi, eax
// 00453a0a  ff1560248000         call dword ptr [0x802460]
// 00453a10  8b742454             mov esi, dword ptr [esp + 0x54]
// 00453a14  8b2e                 mov ebp, dword ptr [esi]
// 00453a16  6a00                 push 0
// 00453a18  8d54242c             lea edx, [esp + 0x2c]
// 00453a1c  52                   push edx
// 00453a1d  8bcf                 mov ecx, edi
// 00453a1f  c644245402           mov byte ptr [esp + 0x54], 2
// 00453a24  e867401300           call 0x587a90
// 00453a29  8b5500               mov edx, dword ptr [ebp]
// 00453a2c  0fb6c0               movzx eax, al
// 00453a2f  50                   push eax
// 00453a30  8bce                 mov ecx, esi
// 00453a32  ffd2                 call edx
// 00453a34  8d4c240c             lea ecx, [esp + 0xc]
// 00453a38  ff15043f8000         call dword ptr [0x803f04]
// 00453a3e  8d4c2428             lea ecx, [esp + 0x28]
// 00453a42  c644244c03           mov byte ptr [esp + 0x4c], 3
// 00453a47  ff1564248000         call dword ptr [0x802464]
// 00453a4d  50                   push eax
// 00453a4e  8d442410             lea eax, [esp + 0x10]
// 00453a52  6883000000           push 0x83
// 00453a57  50                   push eax
// 00453a58  ff15c4328000         call dword ptr [0x8032c4]
// 00453a5e  8b3e                 mov edi, dword ptr [esi]
// 00453a60  83c40c               add esp, 0xc
// 00453a63  8d4c240c             lea ecx, [esp + 0xc]
// 00453a67  83c70c               add edi, 0xc
// 00453a6a  ff15e03e8000         call dword ptr [0x803ee0]
// 00453a70  8b17                 mov edx, dword ptr [edi]
// 00453a72  50                   push eax
// 00453a73  8bce                 mov ecx, esi
// 00453a75  ffd2                 call edx
// 00453a77  8d4c240c             lea ecx, [esp + 0xc]
// 00453a7b  ff15143f8000         call dword ptr [0x803f14]
// 00453a81  8d4c2428             lea ecx, [esp + 0x28]
// 00453a85  c644244c01           mov byte ptr [esp + 0x4c], 1
// 00453a8a  ff1568248000         call dword ptr [0x802468]
// 00453a90  8d4c241c             lea ecx, [esp + 0x1c]
// 00453a94  c644244c00           mov byte ptr [esp + 0x4c], 0
// 00453a99  e822391200           call 0x5773c0
// 00453a9e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00453aa2  c744244cffffffff     mov dword ptr [esp + 0x4c], 0xffffffff
// 00453aaa  85c0                 test eax, eax
// 00453aac  742c                 je 0x453ada
// 00453aae  8bf0                 mov esi, eax
// 00453ab0  83c004               add eax, 4
// 00453ab3  83c9ff               or ecx, 0xffffffff
// 00453ab6  f00fc108             lock xadd dword ptr [eax], ecx
// 00453aba  751e                 jne 0x453ada
// 00453abc  8b16                 mov edx, dword ptr [esi]
// 00453abe  8b4204               mov eax, dword ptr [edx + 4]
// 00453ac1  8bce                 mov ecx, esi
// 00453ac3  ffd0                 call eax
// 00453ac5  8d4e08               lea ecx, [esi + 8]
// 00453ac8  83caff               or edx, 0xffffffff
// 00453acb  f00fc111             lock xadd dword ptr [ecx], edx
// 00453acf  7509                 jne 0x453ada
// 00453ad1  8b06                 mov eax, dword ptr [esi]
// 00453ad3  8b5008               mov edx, dword ptr [eax + 8]
// 00453ad6  8bce                 mov ecx, esi
// 00453ad8  ffd2                 call edx
// 00453ada  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00453ade  5f                   pop edi
// 00453adf  5e                   pop esi
// 00453ae0  64890d00000000       mov dword ptr fs:[0], ecx
// 00453ae7  5d                   pop ebp
// 00453ae8  83c444               add esp, 0x44
// 00453aeb  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Model;

struct Pair {
    Model* object;
    Control* control;
    Pair(const Pair&);
    ~Pair();
};

Pair::Pair(const Pair& other) : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

Pair::~Pair()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Guard {
    unsigned char storage[12];
    Guard(Pair);
    ~Guard();
};

struct String;
extern void (__thiscall *string_construct)(String*);
extern void (__thiscall *string_destroy)(String*);
extern const char* (__thiscall *string_c_str)(const String*);

struct String {
    unsigned char storage[28];
    String();
    ~String();
    const char* c_str() const;
};

String::String()
{
    string_construct(this);
}

String::~String()
{
    string_destroy(this);
}

const char* String::c_str() const
{
    return string_c_str(this);
}

struct Text;
extern void (__thiscall *text_construct)(Text*);
extern void (__thiscall *text_destroy)(Text*);
extern const char* (__thiscall *text_data)(const Text*);
extern void (__cdecl *format_text)(Text*, unsigned int, const char*);

struct Text {
    void* storage;
    Text();
    __declspec(nothrow) ~Text();
    operator const char*() const;

    __declspec(dllimport) void __thiscall destroyImport() throw();
};

Text::Text()
{
    text_construct(this);
}

__declspec(nothrow) Text::~Text()
{
    destroyImport();
}

Text::operator const char*() const
{
    return text_data(this);
}

struct Command {
    virtual void enable(int) = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void setText(const char*) = 0;
};

typedef void (__thiscall *SetTextFunction)(Command*, const char*);

struct Controller {
    bool query(String*, int);
};

struct Model {
    Controller* controller();
};

struct Source {
    Pair get();
};

struct Document {
    unsigned char padding[148];
    Source* source;
    void update(Command*);
};

void Document::update(Command* command)
{
    Pair model = source->get();
    Guard guard(model);
    Controller* controller = model.object->controller();
    String message;
    command->enable(controller->query(&message, 0));
    Text text;
    format_text(&text, 0x83, message.c_str());
    SetTextFunction* slot =
        *reinterpret_cast<SetTextFunction**>(command) + 3;
    const char* value = text;
    (*slot)(command, value);
}
