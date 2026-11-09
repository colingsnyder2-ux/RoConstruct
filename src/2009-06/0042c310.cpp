// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00431f10  unit: CDataModelPropGrid  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431f10
//
// 00431f10  64a100000000         mov eax, dword ptr fs:[0]
// 00431f16  6aff                 push -1
// 00431f18  6858fb7b00           push 0x7bfb58
// 00431f1d  50                   push eax
// 00431f1e  64892500000000       mov dword ptr fs:[0], esp
// 00431f25  83ec60               sub esp, 0x60
// 00431f28  56                   push esi
// 00431f29  8bf1                 mov esi, ecx
// 00431f2b  57                   push edi
// 00431f2c  8bbef4000000         mov edi, dword ptr [esi + 0xf4]
// 00431f32  c786f400000000000000 mov dword ptr [esi + 0xf4], 0
// 00431f3c  85ff                 test edi, edi
// 00431f3e  7410                 je 0x431f50
// 00431f40  8bcf                 mov ecx, edi
// 00431f42  e85954ffff           call 0x4273a0
// 00431f47  57                   push edi
// 00431f48  e82de72600           call 0x6a067a
// 00431f4d  83c404               add esp, 4
// 00431f50  80bef800000000       cmp byte ptr [esi + 0xf8], 0
// 00431f57  7412                 je 0x431f6b
// 00431f59  6a00                 push 0
// 00431f5b  8bce                 mov ecx, esi
// 00431f5d  e8defbffff           call 0x431b40
// 00431f62  c686f900000001       mov byte ptr [esi + 0xf9], 1
// 00431f69  eb07                 jmp 0x431f72
// 00431f6b  c686f900000000       mov byte ptr [esi + 0xf9], 0
// 00431f72  80be0401000000       cmp byte ptr [esi + 0x104], 0
// 00431f79  7569                 jne 0x431fe4
// 00431f7b  6814128100           push 0x811214
// 00431f80  51                   push ecx
// 00431f81  8bc4                 mov eax, esp
// 00431f83  89642410             mov dword ptr [esp + 0x10], esp
// 00431f87  6a00                 push 0
// 00431f89  8d4c2418             lea ecx, [esp + 0x18]
// 00431f8d  c70000000000         mov dword ptr [eax], 0
// 00431f93  e818e12c00           call 0x7000b0
// 00431f98  8d4c240c             lea ecx, [esp + 0xc]
// 00431f9c  c744247000000000     mov dword ptr [esp + 0x70], 0
// 00431fa4  e897eb2c00           call 0x700b40
// 00431fa9  85c0                 test eax, eax
// 00431fab  7426                 je 0x431fd3
// 00431fad  6a01                 push 1
// 00431faf  8d442410             lea eax, [esp + 0x10]
// 00431fb3  50                   push eax
// 00431fb4  8bce                 mov ecx, esi
// 00431fb6  e815daffff           call 0x42f9d0
// 00431fbb  6a01                 push 1
// 00431fbd  8d8e08010000         lea ecx, [esi + 0x108]
// 00431fc3  ff15e03e8000         call dword ptr [0x803ee0]
// 00431fc9  50                   push eax
// 00431fca  8d4c2414             lea ecx, [esp + 0x14]
// 00431fce  e8bdc92c00           call 0x6fe990
// 00431fd3  8d4c240c             lea ecx, [esp + 0xc]
// 00431fd7  c7442470ffffffff     mov dword ptr [esp + 0x70], 0xffffffff
// 00431fdf  e8bce9ffff           call 0x4309a0
// 00431fe4  8bce                 mov ecx, esi
// 00431fe6  e837ea2600           call 0x6a0a22
// 00431feb  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00431fef  5f                   pop edi
// 00431ff0  64890d00000000       mov dword ptr fs:[0], ecx
// 00431ff7  5e                   pop esi
// 00431ff8  83c46c               add esp, 0x6c
// 00431ffb  c3                   ret 

struct Owned {
    ~Owned();
};

struct Handle {
    void *value;

    Handle() : value(0) {}
    Handle(const Handle &other) : value(other.value) {}
    ~Handle() {}
};

struct SettingValue {
    void apply(int);
};

struct Settings {
    int prefix;
    SettingValue value;
    char data[0x57];

    Settings(int, Handle, const char *);
    ~Settings();
    int available();
};

extern int (__thiscall *getHandle)(void *, int);

struct CDataModelPropGrid {
    char padding[0xF8];
    Owned *owned;
    unsigned char flagF8;
    unsigned char flagF9;
    char paddingFA[10];
    unsigned char flag104;
    char padding105[3];
    int handle;

    void reset(int);
    void configure(Settings *, int);
    void complete();
    void f();
};

void CDataModelPropGrid::f()
{
    Owned *old = owned;
    owned = 0;
    if (old)
        delete old;

    if (flagF8) {
        reset(0);
        flagF9 = 1;
    } else {
        flagF9 = 0;
    }

    if (!flag104) {
        Settings settings(0, Handle(), "IDE\0Settings");
        if (settings.available()) {
            configure(&settings, 1);
            settings.value.apply(getHandle(&handle, 1));
        }
    }

    complete();
}
