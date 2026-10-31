// from server: 97% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00430f50  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430f50
//
// 00430f50  64a100000000         mov eax, dword ptr fs:[0]
// 00430f56  6aff                 push -1
// 00430f58  6858fb7b00           push 0x7bfb58
// 00430f5d  50                   push eax
// 00430f5e  64892500000000       mov dword ptr fs:[0], esp
// 00430f65  83ec5c               sub esp, 0x5c
// 00430f68  56                   push esi
// 00430f69  8bf1                 mov esi, ecx
// 00430f6b  80be0401000000       cmp byte ptr [esi + 0x104], 0
// 00430f72  0f84a8000000         je 0x431020
// 00430f78  80be0501000000       cmp byte ptr [esi + 0x105], 0
// 00430f7f  0f859b000000         jne 0x431020
// 00430f85  6a05                 push 5
// 00430f87  8d8ee0030000         lea ecx, [esi + 0x3e0]
// 00430f8d  e8dcf92600           call 0x6a096e
// 00430f92  8b442470             mov eax, dword ptr [esp + 0x70]
// 00430f96  50                   push eax
// 00430f97  8bce                 mov ecx, esi
// 00430f99  e842f8ffff           call 0x4307e0
// 00430f9e  6a01                 push 1
// 00430fa0  8d8e84020000         lea ecx, [esi + 0x284]
// 00430fa6  e895442d00           call 0x705440
// 00430fab  6814128100           push 0x811214
// 00430fb0  51                   push ecx
// 00430fb1  8bc4                 mov eax, esp
// 00430fb3  89642478             mov dword ptr [esp + 0x78], esp
// 00430fb7  6a01                 push 1
// 00430fb9  8d4c2410             lea ecx, [esp + 0x10]
// 00430fbd  c70000000000         mov dword ptr [eax], 0
// 00430fc3  e8e8f02c00           call 0x7000b0
// 00430fc8  8d8e08010000         lea ecx, [esi + 0x108]
// 00430fce  c744246800000000     mov dword ptr [esp + 0x68], 0
// 00430fd6  ff15e03e8000         call dword ptr [0x803ee0]
// 00430fdc  50                   push eax
// 00430fdd  8d4c2408             lea ecx, [esp + 8]
// 00430fe1  e82afa2c00           call 0x700a10
// 00430fe6  85c0                 test eax, eax
// 00430fe8  7410                 je 0x430ffa
// 00430fea  6a01                 push 1
// 00430fec  8d4c2408             lea ecx, [esp + 8]
// 00430ff0  51                   push ecx
// 00430ff1  8bce                 mov ecx, esi
// 00430ff3  e8d8e9ffff           call 0x42f9d0
// 00430ff8  eb0e                 jmp 0x431008
// 00430ffa  8bce                 mov ecx, esi
// 00430ffc  e8dfd5ffff           call 0x42e5e0
// 00431001  8bce                 mov ecx, esi
// 00431003  e808d6ffff           call 0x42e610
// 00431008  8d4c2404             lea ecx, [esp + 4]
// 0043100c  c6860401000000       mov byte ptr [esi + 0x104], 0
// 00431013  c7442468ffffffff     mov dword ptr [esp + 0x68], 0xffffffff
// 0043101b  e880f9ffff           call 0x4309a0
// 00431020  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00431024  64890d00000000       mov dword ptr fs:[0], ecx
// 0043102b  5e                   pop esi
// 0043102c  83c468               add esp, 0x68
// 0043102f  c20400               ret 4

struct String
{
    char* value;
    String() : value(0) {}
    String(const String&);
    ~String();
};

extern const char* (__thiscall *getString)(const String*);

struct Registry
{
    char storage[0x5C];
    Registry(int loading, String parent, const char* section);
    ~Registry();
    int open(const char* name);
};

struct Switch
{
    void set(int value);
};

struct State
{
    void set(int value);
};

struct Frame
{
    char padding0[0x104];
    unsigned char pending;
    unsigned char blocked;
    char padding1[2];
    String name;
    char padding2[0x178];
    Switch option;
    char padding3[0x15B];
    State state;

    void load(int value);
    void exchange(Registry* registry, int loading);
    void reset();
    void finish();
    void restore(int value);
};

void Frame::restore(int value)
{
    if (pending && !blocked)
    {
        state.set(5);
        load(value);
        option.set(1);

        Registry registry(1, String(), "IDE");
        if (registry.open(getString(&name)))
            exchange(&registry, 1);
        else
        {
            reset();
            finish();
        }

        pending = 0;
    }
}
