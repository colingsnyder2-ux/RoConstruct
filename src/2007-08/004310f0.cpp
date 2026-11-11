// from server: 100% by EspClaude
// from server: 72% by EspClaude
// roc 2007-08 004310f0  unit: CSelectionPropGrid  size: 242 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004310f0
//
// 004310f0  6aff                 push -1
// 004310f2  6898da7300           push 0x73da98
// 004310f7  64a100000000         mov eax, dword ptr fs:[0]
// 004310fd  50                   push eax
// 004310fe  83ec5c               sub esp, 0x5c
// 00431101  56                   push esi
// 00431102  a188518b00           mov eax, dword ptr [0x8b5188]
// 00431107  33c4                 xor eax, esp
// 00431109  50                   push eax
// 0043110a  8d442464             lea eax, [esp + 0x64]
// 0043110e  64a300000000         mov dword ptr fs:[0], eax
// 00431114  8bf1                 mov esi, ecx
// 00431116  80beec00000000       cmp byte ptr [esi + 0xec], 0
// 0043111d  0f85ae000000         jne 0x4311d1
// 00431123  680cb17800           push 0x78b10c
// 00431128  51                   push ecx
// 00431129  8bc4                 mov eax, esp
// 0043112b  89642410             mov dword ptr [esp + 0x10], esp
// 0043112f  6a00                 push 0
// 00431131  8d4c2418             lea ecx, [esp + 0x18]
// 00431135  c70000000000         mov dword ptr [eax], 0
// 0043113b  e800732500           call 0x688440
// 00431140  8d4c240c             lea ecx, [esp + 0xc]
// 00431144  c744246c00000000     mov dword ptr [esp + 0x6c], 0
// 0043114c  e82f7d2500           call 0x688e80
// 00431151  85c0                 test eax, eax
// 00431153  7426                 je 0x43117b
// 00431155  6a01                 push 1
// 00431157  8d442410             lea eax, [esp + 0x10]
// 0043115b  50                   push eax
// 0043115c  8bce                 mov ecx, esi
// 0043115e  e82defffff           call 0x430090
// 00431163  6a01                 push 1
// 00431165  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0043116b  ff1598dd7700         call dword ptr [0x77dd98]
// 00431171  50                   push eax
// 00431172  8d4c2414             lea ecx, [esp + 0x14]
// 00431176  e8555b2500           call 0x686cd0
// 0043117b  6a00                 push 0
// 0043117d  8d8ec8030000         lea ecx, [esi + 0x3c8]
// 00431183  e8c2ed1f00           call 0x62ff4a
// 00431188  6a00                 push 0
// 0043118a  8d8e6c020000         lea ecx, [esi + 0x26c]
// 00431190  e86bc32500           call 0x68d500
// 00431195  8b8ed8000000         mov ecx, dword ptr [esi + 0xd8]
// 0043119b  e860362000           call 0x634800
// 004311a0  8d8e20010000         lea ecx, [esi + 0x120]
// 004311a6  e875cf2300           call 0x66e120
// 004311ab  8b16                 mov edx, dword ptr [esi]
// 004311ad  8b8250010000         mov eax, dword ptr [edx + 0x150]
// 004311b3  6a01                 push 1
// 004311b5  8bce                 mov ecx, esi
// 004311b7  ffd0                 call eax
// 004311b9  8d4c240c             lea ecx, [esp + 0xc]
// 004311bd  c686ec00000001       mov byte ptr [esi + 0xec], 1
// 004311c4  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 004311cc  e8cffeffff           call 0x4310a0
// 004311d1  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 004311d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004311dc  59                   pop ecx
// 004311dd  5e                   pop esi
// 004311de  83c468               add esp, 0x68
// 004311e1  c3                   ret 

// 2007-08 offsets: commandBars +0xd8, initialized +0xec, item +0xf0, panel +0x120, control +0x26c, auxiliary +0x3c8, vtable slot 0x150
struct Value {
    int value;
    Value(int);
    Value(const Value &);
};

__forceinline Value::Value(int n) : value(n) {}

struct Selection {
    int storage[0x54 / 4];  // 2007-08 frame: Settings occupies esp+0xc..0x64 => 0x58 total
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
    char padding04[0xD4];
    CommandBars *commandBars;
    char paddingDC[0x10];
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
        vtable[0x54](this, 1);
        initialized = 1;
    }
}
