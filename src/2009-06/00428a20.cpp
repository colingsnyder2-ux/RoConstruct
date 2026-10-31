// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0042f9d0  unit: MyXTPCommandBars  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042f9d0
//
// 0042f9d0  6aff                 push -1
// 0042f9d2  6850fa7b00           push 0x7bfa50
// 0042f9d7  64a100000000         mov eax, dword ptr fs:[0]
// 0042f9dd  50                   push eax
// 0042f9de  64892500000000       mov dword ptr fs:[0], esp
// 0042f9e5  83ec30               sub esp, 0x30
// 0042f9e8  53                   push ebx
// 0042f9e9  55                   push ebp
// 0042f9ea  56                   push esi
// 0042f9eb  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 0042f9ef  8b16                 mov edx, dword ptr [esi]
// 0042f9f1  8be9                 mov ebp, ecx
// 0042f9f3  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0042f9f7  b801000000           mov eax, 1
// 0042f9fc  33db                 xor ebx, ebx
// 0042f9fe  57                   push edi
// 0042f9ff  8bbdec000000         mov edi, dword ptr [ebp + 0xec]
// 0042fa05  8944241c             mov dword ptr [esp + 0x1c], eax
// 0042fa09  89442424             mov dword ptr [esp + 0x24], eax
// 0042fa0d  89442430             mov dword ptr [esp + 0x30], eax
// 0042fa11  894c2418             mov dword ptr [esp + 0x18], ecx
// 0042fa15  89442420             mov dword ptr [esp + 0x20], eax
// 0042fa19  8b4270               mov eax, dword ptr [edx + 0x70]
// 0042fa1c  68c00d8100           push 0x810dc0
// 0042fa21  8bce                 mov ecx, esi
// 0042fa23  895c2440             mov dword ptr [esp + 0x40], ebx
// 0042fa27  895c2430             mov dword ptr [esp + 0x30], ebx
// 0042fa2b  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0042fa2f  895c2438             mov dword ptr [esp + 0x38], ebx
// 0042fa33  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0042fa37  ffd0                 call eax
// 0042fa39  89442410             mov dword ptr [esp + 0x10], eax
// 0042fa3d  8d4c2418             lea ecx, [esp + 0x18]
// 0042fa41  51                   push ecx
// 0042fa42  50                   push eax
// 0042fa43  8bcf                 mov ecx, edi
// 0042fa45  895c2450             mov dword ptr [esp + 0x50], ebx
// 0042fa49  e8124a2b00           call 0x6e4460
// 0042fa4e  8b16                 mov edx, dword ptr [esi]
// 0042fa50  8b4270               mov eax, dword ptr [edx + 0x70]
// 0042fa53  68b40d8100           push 0x810db4
// 0042fa58  8bce                 mov ecx, esi
// 0042fa5a  ffd0                 call eax
// 0042fa5c  89442454             mov dword ptr [esp + 0x54], eax
// 0042fa60  8bcf                 mov ecx, edi
// 0042fa62  c644244801           mov byte ptr [esp + 0x48], 1
// 0042fa67  e8d42e2700           call 0x6a2940
// 0042fa6c  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0042fa70  8b10                 mov edx, dword ptr [eax]
// 0042fa72  8b5270               mov edx, dword ptr [edx + 0x70]
// 0042fa75  51                   push ecx
// 0042fa76  8bc8                 mov ecx, eax
// 0042fa78  ffd2                 call edx
// 0042fa7a  8b06                 mov eax, dword ptr [esi]
// 0042fa7c  8b5070               mov edx, dword ptr [eax + 0x70]
// 0042fa7f  68ac0d8100           push 0x810dac
// 0042fa84  8bce                 mov ecx, esi
// 0042fa86  ffd2                 call edx
// 0042fa88  89442450             mov dword ptr [esp + 0x50], eax
// 0042fa8c  8b7f74               mov edi, dword ptr [edi + 0x74]
// 0042fa8f  6a01                 push 1
// 0042fa91  50                   push eax
// 0042fa92  8bcf                 mov ecx, edi
// 0042fa94  c644245002           mov byte ptr [esp + 0x50], 2
// 0042fa99  e842692700           call 0x6a63e0
// 0042fa9e  8b06                 mov eax, dword ptr [esi]
// 0042faa0  8b5070               mov edx, dword ptr [eax + 0x70]
// 0042faa3  68a00d8100           push 0x810da0
// 0042faa8  8bce                 mov ecx, esi
// 0042faaa  ffd2                 call edx
// 0042faac  8bf0                 mov esi, eax
// 0042faae  89742414             mov dword ptr [esp + 0x14], esi
// 0042fab2  56                   push esi
// 0042fab3  8d8d38010000         lea ecx, [ebp + 0x138]
// 0042fab9  c644244c03           mov byte ptr [esp + 0x4c], 3
// 0042fabe  e88d6e2b00           call 0x6e6950
// 0042fac3  c644244802           mov byte ptr [esp + 0x48], 2
// 0042fac8  3bf3                 cmp esi, ebx
// 0042faca  7407                 je 0x42fad3
// 0042facc  8bce                 mov ecx, esi
// 0042face  e811112700           call 0x6a0be4
// 0042fad3  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0042fad7  c644244801           mov byte ptr [esp + 0x48], 1
// 0042fadc  3bcb                 cmp ecx, ebx
// 0042fade  7405                 je 0x42fae5
// 0042fae0  e8ff102700           call 0x6a0be4
// 0042fae5  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0042fae9  885c2448             mov byte ptr [esp + 0x48], bl
// 0042faed  3bcb                 cmp ecx, ebx
// 0042faef  7405                 je 0x42faf6
// 0042faf1  e8ee102700           call 0x6a0be4
// 0042faf6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042fafa  5f                   pop edi
// 0042fafb  5e                   pop esi
// 0042fafc  5d                   pop ebp
// 0042fafd  3bcb                 cmp ecx, ebx
// 0042faff  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0042fb07  5b                   pop ebx
// 0042fb08  7405                 je 0x42fb0f
// 0042fb0a  e8d5102700           call 0x6a0be4
// 0042fb0f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0042fb13  64890d00000000       mov dword ptr fs:[0], ecx
// 0042fb1a  83c43c               add esp, 0x3c
// 0042fb1d  c20800               ret 8

struct Section {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual Section* section(const char*);
    void release();
};

struct SectionOwner {
    Section* p;
    ~SectionOwner();
};

inline SectionOwner::~SectionOwner()
{
    if (p)
        p->release();
}

struct ExchangeOptions {
    int mode;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
};

struct Options {
    void exchange(Section*, int);
};

struct CommandBars {
    char pad0[116];
    Options* options;
    void exchange(Section*, ExchangeOptions*);
    int f();
};

struct DockingPane {
    void exchange(Section*);
};

struct MyXTPCommandBars {
    char pad0[236];
    CommandBars* bars;
    char pad1[72];
    DockingPane docking;
    void exchange(Section*, int);
};

void MyXTPCommandBars::exchange(Section* px, int mode)
{
    CommandBars* manager = bars;
    ExchangeOptions options;
    options.a = 1;
    options.c = 1;
    options.f = 1;
    options.mode = mode;
    options.b = 1;
    options.i = 0;
    options.e = 0;
    options.d = 0;
    options.g = 0;
    options.h = 0;

    SectionOwner commandBars = { px->section("CommandBars") };
    manager->exchange(commandBars.p, &options);

    SectionOwner shortcuts = { px->section("Shortcuts") };
    reinterpret_cast<Section*>(manager->f())->section(
        reinterpret_cast<const char*>(shortcuts.p));

    SectionOwner commandOptions = { px->section("Options") };
    manager = reinterpret_cast<CommandBars*>(manager->options);
    reinterpret_cast<Options*>(manager)->exchange(commandOptions.p, 1);

    SectionOwner dockingPane = { px->section("DockingPane") };
    docking.exchange(dockingPane.p);
}
