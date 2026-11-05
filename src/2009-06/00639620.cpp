// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005adf80  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005adf80
//
// 005adf80  6aff                 push -1
// 005adf82  6802337d00           push 0x7d3302
// 005adf87  64a100000000         mov eax, dword ptr fs:[0]
// 005adf8d  50                   push eax
// 005adf8e  64892500000000       mov dword ptr fs:[0], esp
// 005adf95  83ec40               sub esp, 0x40
// 005adf98  55                   push ebp
// 005adf99  56                   push esi
// 005adf9a  57                   push edi
// 005adf9b  68f4468300           push 0x8346f4
// 005adfa0  6a01                 push 1
// 005adfa2  e8b957eeff           call 0x493760
// 005adfa7  8bc8                 mov ecx, eax
// 005adfa9  e862b8edff           call 0x489810
// 005adfae  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 005adfb2  6a00                 push 0
// 005adfb4  6a00                 push 0
// 005adfb6  6a01                 push 1
// 005adfb8  56                   push esi
// 005adfb9  e862370600           call 0x611720
// 005adfbe  56                   push esi
// 005adfbf  8bf8                 mov edi, eax
// 005adfc1  e84a3c0600           call 0x611c10
// 005adfc6  83c414               add esp, 0x14
// 005adfc9  57                   push edi
// 005adfca  8d4c2430             lea ecx, [esp + 0x30]
// 005adfce  8be8                 mov ebp, eax
// 005adfd0  ff1558248000         call dword ptr [0x802458]
// 005adfd6  c744245400000000     mov dword ptr [esp + 0x54], 0
// 005adfde  e88d62faff           call 0x554270
// 005adfe3  89442448             mov dword ptr [esp + 0x48], eax
// 005adfe7  83ec20               sub esp, 0x20
// 005adfea  8bfc                 mov edi, esp
// 005adfec  8d44244c             lea eax, [esp + 0x4c]
// 005adff0  8964242c             mov dword ptr [esp + 0x2c], esp
// 005adff4  50                   push eax
// 005adff5  8bcf                 mov ecx, edi
// 005adff7  c744247801000000     mov dword ptr [esp + 0x78], 1
// 005adfff  ff155c248000         call dword ptr [0x80245c]
// 005ae005  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 005ae009  894f1c               mov dword ptr [edi + 0x1c], ecx
// 005ae00c  6a43                 push 0x43
// 005ae00e  56                   push esi
// 005ae00f  c644247c02           mov byte ptr [esp + 0x7c], 2
// 005ae014  e8f7430600           call 0x612410
// 005ae019  68eed8ffff           push 0xffffd8ee
// 005ae01e  56                   push esi
// 005ae01f  e83c440600           call 0x612460
// 005ae024  6aff                 push -1
// 005ae026  56                   push esi
// 005ae027  e8f4400600           call 0x612120
// 005ae02c  6afe                 push -2
// 005ae02e  56                   push esi
// 005ae02f  8bf8                 mov edi, eax
// 005ae031  e8ea3b0600           call 0x611c20
// 005ae036  83c420               add esp, 0x20
// 005ae039  8d542430             lea edx, [esp + 0x30]
// 005ae03d  52                   push edx
// 005ae03e  57                   push edi
// 005ae03f  e8cc71ebff           call 0x465210
// 005ae044  83c404               add esp, 4
// 005ae047  8bc8                 mov ecx, eax
// 005ae049  c644247801           mov byte ptr [esp + 0x78], 1
// 005ae04e  e8dd3dfbff           call 0x561e30
// 005ae053  837c242810           cmp dword ptr [esp + 0x28], 0x10
// 005ae058  8b442414             mov eax, dword ptr [esp + 0x14]
// 005ae05c  c644245403           mov byte ptr [esp + 0x54], 3
// 005ae061  7304                 jae 0x5ae067
// 005ae063  8d442414             lea eax, [esp + 0x14]
// 005ae067  50                   push eax
// 005ae068  56                   push esi
// 005ae069  e802320600           call 0x611270
// 005ae06e  83c408               add esp, 8
// 005ae071  85c0                 test eax, eax
// 005ae073  7409                 je 0x5ae07e
// 005ae075  56                   push esi
// 005ae076  e8f54a0600           call 0x612b70
// 005ae07b  83c404               add esp, 4
// 005ae07e  6aff                 push -1
// 005ae080  6a00                 push 0
// 005ae082  56                   push esi
// 005ae083  e898480600           call 0x612920
// 005ae088  56                   push esi
// 005ae089  e8823b0600           call 0x611c10
// 005ae08e  8bf0                 mov esi, eax
// 005ae090  83c410               add esp, 0x10
// 005ae093  8d4c2410             lea ecx, [esp + 0x10]
// 005ae097  2bf5                 sub esi, ebp
// 005ae099  c644245401           mov byte ptr [esp + 0x54], 1
// 005ae09e  ff1568248000         call dword ptr [0x802468]
// 005ae0a4  8d4c242c             lea ecx, [esp + 0x2c]
// 005ae0a8  c7442454ffffffff     mov dword ptr [esp + 0x54], 0xffffffff
// 005ae0b0  ff1568248000         call dword ptr [0x802468]
// 005ae0b6  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005ae0ba  5f                   pop edi
// 005ae0bb  8bc6                 mov eax, esi
// 005ae0bd  5e                   pop esi
// 005ae0be  64890d00000000       mov dword ptr fs:[0], ecx
// 005ae0c5  5d                   pop ebp
// 005ae0c6  83c44c               add esp, 0x4c
// 005ae0c9  c3                   ret 

struct String;
typedef void (__thiscall *StringFromText)(String *, const char *);
typedef void (__thiscall *StringCopy)(String *, const String &);
typedef void (__thiscall *StringDestroy)(String *);

extern StringFromText import_802458;
extern StringCopy import_80245c;
extern StringDestroy import_802468;

struct String
{
    void *proxy;
    union
    {
        char buffer[16];
        char *pointer;
    };
    unsigned length;
    unsigned capacity;

    String(const char *);
    String(const String &);
    ~String();
    const char *c_str() const;
};

inline String::String(const char *p)
{
    import_802458(this, p);
}

inline String::String(const String &s)
{
    import_80245c(this, s);
}

inline String::~String()
{
    import_802468(this);
}

inline const char *String::c_str() const
{
    const char *p = pointer;
    if (capacity < 16)
        p = buffer;
    return p;
}

struct Guid
{
    String text;
    const void *scope;
    ~Guid();
};

inline Guid::~Guid()
{
}

struct Name
{
    void sub_489810();
};

namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        String sub_561e30(Guid);
    };
}

extern Name *__stdcall sub_493760(int, const char *);
extern const void *__cdecl sub_554270();
extern RBX::ServiceProvider *__cdecl func_00465210(RBX::Instance *);

extern "C" const char *__cdecl sub_611720(void *, int, void *, void *);
extern "C" int __cdecl sub_611c10(void *);
extern "C" void __cdecl sub_611c20(void *, int);
extern "C" RBX::Instance *__cdecl sub_612120(void *, int);
extern "C" void __cdecl sub_612410(void *, int);
extern "C" void __cdecl sub_612460(void *, int);
extern int __cdecl sub_611270(void *, const char *);
extern "C" void __cdecl sub_612b70(void *);
extern "C" void __cdecl sub_612920(void *, int, int);

inline RBX::Instance *getInstance(void *state)
{
    sub_612410(state, 67);
    sub_612460(state, -10002);
    RBX::Instance *instance = sub_612120(state, -1);
    sub_611c20(state, -2);
    return instance;
}

int __cdecl sub_5adf80(void *state)
{
    sub_493760(1, "dofile")->sub_489810();

    const char *text = sub_611720(state, 1, 0, 0);
    int top = sub_611c10(state);

    Guid guid = { String(text), sub_554270() };
    String result = func_00465210(getInstance(state))->sub_561e30(guid);

    if (sub_611270(state, result.c_str()))
        sub_612b70(state);

    sub_612920(state, 0, -1);
    return sub_611c10(state) - top;
}
