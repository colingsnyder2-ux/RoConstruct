// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00431250  unit: CMainFrame  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431250
//
// 00431250  6aff                 push -1
// 00431252  68c8da7300           push 0x73dac8
// 00431257  64a100000000         mov eax, dword ptr fs:[0]
// 0043125d  50                   push eax
// 0043125e  83ec5c               sub esp, 0x5c
// 00431261  56                   push esi
// 00431262  57                   push edi
// 00431263  a188518b00           mov eax, dword ptr [0x8b5188]
// 00431268  33c4                 xor eax, esp
// 0043126a  50                   push eax
// 0043126b  8d442468             lea eax, [esp + 0x68]
// 0043126f  64a300000000         mov dword ptr fs:[0], eax
// 00431275  8bf1                 mov esi, ecx
// 00431277  80beec00000000       cmp byte ptr [esi + 0xec], 0
// 0043127e  7569                 jne 0x4312e9
// 00431280  680cb17800           push 0x78b10c
// 00431285  51                   push ecx
// 00431286  8bc4                 mov eax, esp
// 00431288  89642414             mov dword ptr [esp + 0x14], esp
// 0043128c  6a00                 push 0
// 0043128e  8d4c241c             lea ecx, [esp + 0x1c]
// 00431292  c70000000000         mov dword ptr [eax], 0
// 00431298  e8a3712500           call 0x688440
// 0043129d  8d4c2410             lea ecx, [esp + 0x10]
// 004312a1  c744247000000000     mov dword ptr [esp + 0x70], 0
// 004312a9  e8d27b2500           call 0x688e80
// 004312ae  85c0                 test eax, eax
// 004312b0  7426                 je 0x4312d8
// 004312b2  6a01                 push 1
// 004312b4  8d442414             lea eax, [esp + 0x14]
// 004312b8  50                   push eax
// 004312b9  8bce                 mov ecx, esi
// 004312bb  e8d0edffff           call 0x430090
// 004312c0  6a01                 push 1
// 004312c2  8d8ef0000000         lea ecx, [esi + 0xf0]
// 004312c8  ff1598dd7700         call dword ptr [0x77dd98]
// 004312ce  50                   push eax
// 004312cf  8d4c2418             lea ecx, [esp + 0x18]
// 004312d3  e8f8592500           call 0x686cd0
// 004312d8  8d4c2410             lea ecx, [esp + 0x10]
// 004312dc  c7442470ffffffff     mov dword ptr [esp + 0x70], 0xffffffff
// 004312e4  e8b7fdffff           call 0x4310a0
// 004312e9  8bce                 mov ecx, esi
// 004312eb  e80eed1f00           call 0x62fffe
// 004312f0  e80dec1f00           call 0x62ff02
// 004312f5  8b7804               mov edi, dword ptr [eax + 4]
// 004312f8  85ff                 test edi, edi
// 004312fa  741a                 je 0x431316
// 004312fc  397720               cmp dword ptr [edi + 0x20], esi
// 004312ff  7515                 jne 0x431316
// 00431301  e88cf21f00           call 0x630592
// 00431306  85c0                 test eax, eax
// 00431308  750c                 jne 0x431316
// 0043130a  894720               mov dword ptr [edi + 0x20], eax
// 0043130d  8b16                 mov edx, dword ptr [esi]
// 0043130f  8b4268               mov eax, dword ptr [edx + 0x68]
// 00431312  8bce                 mov ecx, esi
// 00431314  ffd0                 call eax
// 00431316  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0043131a  64890d00000000       mov dword ptr fs:[0], ecx
// 00431321  59                   pop ecx
// 00431322  5f                   pop edi
// 00431323  5e                   pop esi
// 00431324  83c468               add esp, 0x68

// Shape from sibling 004310f0 (CSelectionPropGrid donor): Settings(0, Value(0), "IDE").
struct Value {
    int value;
    Value(int);
    Value(const Value &);
};

__forceinline Value::Value(int n) : value(n) {}

struct Selection {
    void select(int);                       // 0x686cd0, ecx = settings+4
};

struct Settings {
    int header;
    Selection selection;                    // +4
    int storage[0x14];                       // frame: object spans esp+0x10..0x68
    Settings(int, Value, const char *);     // 0x688440
    ~Settings();                            // 0x4310a0
    int available();                        // 0x688e80
};

struct Item {
    __declspec(dllimport) int op(int);      // [0x77dd98] ordinal import, ecx = this+0xf0
};

struct CWinThreadView {
    char pad[0x20];
    struct S *mainWnd;                      // +0x20
};

struct ThreadState {
    int pad0;
    CWinThreadView *thread;                 // +4
};

ThreadState *getThreadState();              // 0x62ff02
int canExit();                              // 0x630592

struct S {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64();
    virtual void v68();                     // slot 0x68

    char padding04[0xe8];
    unsigned char initialized;              // +0xec
    char padding0ed[3];
    Item item;                              // +0xf0

    void apply(Settings *, int);            // 0x430090
    void baseHandler();                     // 0x62fffe
    void f();
};

void S::f()
{
    if (!initialized) {
        Settings settings(0, Value(0), "IDE");
        if (settings.available()) {
            apply(&settings, 1);
            settings.selection.select(item.op(1));
        }
    }
    baseHandler();
    CWinThreadView *thread = getThreadState()->thread;
    if (thread != 0 && thread->mainWnd == this && !canExit()) {
        thread->mainWnd = 0;
        v68();
    }
}
