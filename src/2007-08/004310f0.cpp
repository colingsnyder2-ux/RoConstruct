// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004309f0  unit: CSelectionPropGrid  size: 230 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004309f0
//
// 004309f0  64a100000000         mov eax, dword ptr fs:[0]
// 004309f6  6aff                 push -1
// 004309f8  6858fb7b00           push 0x7bfb58
// 004309fd  50                   push eax
// 004309fe  64892500000000       mov dword ptr fs:[0], esp
// 00430a05  83ec60               sub esp, 0x60
// 00430a08  56                   push esi
// 00430a09  8bf1                 mov esi, ecx
// 00430a0b  80be0401000000       cmp byte ptr [esi + 0x104], 0
// 00430a12  0f85ae000000         jne 0x430ac6
// 00430a18  6814128100           push 0x811214
// 00430a1d  51                   push ecx
// 00430a1e  8bc4                 mov eax, esp
// 00430a20  8964240c             mov dword ptr [esp + 0xc], esp
// 00430a24  6a00                 push 0
// 00430a26  8d4c2414             lea ecx, [esp + 0x14]
// 00430a2a  c70000000000         mov dword ptr [eax], 0
// 00430a30  e87bf62c00           call 0x7000b0
// 00430a35  8d4c2408             lea ecx, [esp + 8]
// 00430a39  c744246c00000000     mov dword ptr [esp + 0x6c], 0
// 00430a41  e8fa002d00           call 0x700b40
// 00430a46  85c0                 test eax, eax
// 00430a48  7426                 je 0x430a70
// 00430a4a  6a01                 push 1
// 00430a4c  8d44240c             lea eax, [esp + 0xc]
// 00430a50  50                   push eax
// 00430a51  8bce                 mov ecx, esi
// 00430a53  e878efffff           call 0x42f9d0
// 00430a58  6a01                 push 1
// 00430a5a  8d8e08010000         lea ecx, [esi + 0x108]
// 00430a60  ff15e03e8000         call dword ptr [0x803ee0]
// 00430a66  50                   push eax
// 00430a67  8d4c2410             lea ecx, [esp + 0x10]
// 00430a6b  e820df2c00           call 0x6fe990
// 00430a70  6a00                 push 0
// 00430a72  8d8ee0030000         lea ecx, [esi + 0x3e0]
// 00430a78  e8f1fe2600           call 0x6a096e
// 00430a7d  6a00                 push 0
// 00430a7f  8d8e84020000         lea ecx, [esi + 0x284]
// 00430a85  e8b6492d00           call 0x705440
// 00430a8a  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00430a90  e84b4a2700           call 0x6a54e0
// 00430a95  8d8e38010000         lea ecx, [esi + 0x138]
// 00430a9b  e850452b00           call 0x6e4ff0
// 00430aa0  8b16                 mov edx, dword ptr [esi]
// 00430aa2  8b8258010000         mov eax, dword ptr [edx + 0x158]
// 00430aa8  6a01                 push 1
// 00430aaa  8bce                 mov ecx, esi
// 00430aac  ffd0                 call eax
// 00430aae  8d4c2408             lea ecx, [esp + 8]
// 00430ab2  c6860401000001       mov byte ptr [esi + 0x104], 1
// 00430ab9  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 00430ac1  e8dafeffff           call 0x4309a0
// 00430ac6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00430aca  64890d00000000       mov dword ptr fs:[0], ecx
// 00430ad1  5e                   pop esi
// 00430ad2  83c46c               add esp, 0x6c
// 00430ad5  c3                   ret 

struct Value {
    int value;
    Value(int);
    Value(const Value &);
};

__forceinline Value::Value(int n) : value(n) {}

struct Selection {
    char storage[0x58];
    void select(int);
};

struct Settings {
    int header;
    Selection selection;
    Settings(int, Value, const char *);
    ~Settings();
    int available();
};

struct Item {
    char storage[0x30];
};

extern int (__thiscall *itemOperation)(Item *, int);

struct Panel {
    char storage[0x14C];
    void clear();
};

struct Control {
    char storage[0x15C];
    void reset(int);
};

struct Auxiliary {
    void reset(int);
};

struct CommandBars {
    void update();
};

struct S {
    typedef void (__thiscall *VirtualOperation)(S *, int);

    VirtualOperation *vtable;
    char padding04[0xE8];
    CommandBars *commandBars;
    char paddingF0[0x14];
    unsigned char initialized;
    char padding105[3];
    Item item;
    Panel panel;
    Control control;
    Auxiliary auxiliary;

    void apply(Settings *, int);
    void f();
};

void S::f()
{
    if (!initialized) {
        Settings settings(0, Value(0), "IDE");
        if (settings.available()) {
            apply(&settings, 1);
            settings.selection.select(itemOperation(&item, 1));
        }
        auxiliary.reset(0);
        control.reset(0);
        commandBars->update();
        panel.clear();
        vtable[0x56](this, 1);
        initialized = 1;
    }
}
