// from server: 100% by Xemicl
// roc 2012-06 00455940  unit: CPropertyGridItemBrickColor  size: 402 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00455940
//
// 00455940  6aff                 push -1
// 00455942  64a100000000         mov eax, dword ptr fs:[0]
// 00455948  6883efa900           push 0xa9ef83
// 0045594d  50                   push eax
// 0045594e  64892500000000       mov dword ptr fs:[0], esp
// 00455955  8b442410             mov eax, dword ptr [esp + 0x10]
// 00455959  83ec14               sub esp, 0x14
// 0045595c  53                   push ebx
// 0045595d  55                   push ebp
// 0045595e  56                   push esi
// 0045595f  57                   push edi
// 00455960  8bf1                 mov esi, ecx
// 00455962  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 00455968  50                   push eax
// 00455969  6a05                 push 5
// 0045596b  e8008a5900           call 0x9ee370
// 00455970  83f801               cmp eax, 1
// 00455973  0f8444010000         je 0x455abd
// 00455979  8b16                 mov edx, dword ptr [esi]
// 0045597b  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 00455981  8bce                 mov ecx, esi
// 00455983  ffd0                 call eax
// 00455985  85c0                 test eax, eax
// 00455987  0f8430010000         je 0x455abd
// 0045598d  8d4c2414             lea ecx, [esp + 0x14]
// 00455991  51                   push ecx
// 00455992  8bce                 mov ecx, esi
// 00455994  e8a7c75900           call 0x9f2140
// 00455999  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0045599f  8d542414             lea edx, [esp + 0x14]
// 004559a3  52                   push edx
// 004559a4  e805cd5200           call 0x9826ae
// 004559a9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004559ad  0562ffffff           add eax, 0xffffff62
// 004559b2  6a00                 push 0
// 004559b4  89442418             mov dword ptr [esp + 0x18], eax
// 004559b8  e833635700           call 0x9cbcf0
// 004559bd  6884010000           push 0x184
// 004559c2  8be8                 mov ebp, eax
// 004559c4  e851c75200           call 0x98211a
// 004559c9  83c408               add esp, 8
// 004559cc  89442434             mov dword ptr [esp + 0x34], eax
// 004559d0  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004559d8  85c0                 test eax, eax
// 004559da  740b                 je 0x4559e7
// 004559dc  8bc8                 mov ecx, eax
// 004559de  e8cd2b0200           call 0x4785b0
// 004559e3  8bf8                 mov edi, eax
// 004559e5  eb02                 jmp 0x4559e9
// 004559e7  33ff                 xor edi, edi
// 004559e9  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 004559ef  6a00                 push 0
// 004559f1  6aff                 push -1
// 004559f3  6a00                 push 0
// 004559f5  6a00                 push 0
// 004559f7  57                   push edi
// 004559f8  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00455a00  e89bc45700           call 0x9d1ea0
// 00455a05  8d4c2434             lea ecx, [esp + 0x34]
// 00455a09  51                   push ecx
// 00455a0a  8bce                 mov ecx, esi
// 00455a0c  e82fecffff           call 0x454640
// 00455a11  68e83bb400           push 0xb43be8
// 00455a16  8bc8                 mov ecx, eax
// 00455a18  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00455a20  ff159c47b200         call dword ptr [0xb2479c]
// 00455a26  85c0                 test eax, eax
// 00455a28  8d4c2434             lea ecx, [esp + 0x34]
// 00455a2c  0f95c3               setne bl
// 00455a2f  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00455a37  ff15d047b200         call dword ptr [0xb247d0]
// 00455a3d  84db                 test bl, bl
// 00455a3f  7414                 je 0x455a55
// 00455a41  8b16                 mov edx, dword ptr [esi]
// 00455a43  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 00455a49  8bce                 mov ecx, esi
// 00455a4b  ffd0                 call eax
// 00455a4d  50                   push eax
// 00455a4e  8bcf                 mov ecx, edi
// 00455a50  e8fb210200           call 0x477c50
// 00455a55  e83ace5200           call 0x982894
// 00455a5a  85c0                 test eax, eax
// 00455a5c  740b                 je 0x455a69
// 00455a5e  8b10                 mov edx, dword ptr [eax]
// 00455a60  8bc8                 mov ecx, eax
// 00455a62  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00455a65  ffd0                 call eax
// 00455a67  eb02                 jmp 0x455a6b
// 00455a69  33c0                 xor eax, eax
// 00455a6b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00455a6f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00455a73  6a00                 push 0
// 00455a75  6a00                 push 0
// 00455a77  50                   push eax
// 00455a78  51                   push ecx
// 00455a79  52                   push edx
// 00455a7a  6888000000           push 0x88
// 00455a7f  55                   push ebp
// 00455a80  e80bec5400           call 0x9a4690
// 00455a85  83c41c               add esp, 0x1c
// 00455a88  85c0                 test eax, eax
// 00455a8a  742a                 je 0x455ab6
// 00455a8c  80bf7c01000000       cmp byte ptr [edi + 0x17c], 0
// 00455a93  7421                 je 0x455ab6
// 00455a95  8bcf                 mov ecx, edi
// 00455a97  e8a4210200           call 0x477c40
// 00455a9c  51                   push ecx
// 00455a9d  8bcc                 mov ecx, esp
// 00455a9f  89642414             mov dword ptr [esp + 0x14], esp
// 00455aa3  50                   push eax
// 00455aa4  51                   push ecx
// 00455aa5  e8e6f0ffff           call 0x454b90
// 00455aaa  8b16                 mov edx, dword ptr [esi]
// 00455aac  8b4264               mov eax, dword ptr [edx + 0x64]
// 00455aaf  83c408               add esp, 8
// 00455ab2  8bce                 mov ecx, esi
// 00455ab4  ffd0                 call eax
// 00455ab6  8bcd                 mov ecx, ebp
// 00455ab8  e8cdcb5200           call 0x98268a
// 00455abd  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00455ac1  5f                   pop edi
// 00455ac2  5e                   pop esi
// 00455ac3  5d                   pop ebp
// 00455ac4  64890d00000000       mov dword ptr fs:[0], ecx
// 00455acb  5b                   pop ebx
// 00455acc  83c420               add esp, 0x20
// 00455acf  c20400               ret 4
// copied from an identical function in another client (function ?activate@Item@@QAEXH@Z)

// from server: 99% by colin
// roc 2008-06 004382b0  unit: CPropertyGridItemBrickColor  size: 402 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004382b0
//
// 004382b0  6aff                 push -1
// 004382b2  64a100000000         mov eax, dword ptr fs:[0]
// 004382b8  68c3037c00           push 0x7c03c3
// 004382bd  50                   push eax
// 004382be  64892500000000       mov dword ptr fs:[0], esp
// 004382c5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004382c9  83ec14               sub esp, 0x14
// 004382cc  53                   push ebx
// 004382cd  55                   push ebp
// 004382ce  56                   push esi
// 004382cf  57                   push edi
// 004382d0  8bf1                 mov esi, ecx
// 004382d2  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 004382d8  50                   push eax
// 004382d9  6a05                 push 5
// 004382db  e820be2d00           call 0x714100
// 004382e0  83f801               cmp eax, 1
// 004382e3  0f8444010000         je 0x43842d
// 004382e9  8b16                 mov edx, dword ptr [esi]
// 004382eb  8b8290000000         mov eax, dword ptr [edx + 0x90]
// 004382f1  8bce                 mov ecx, esi
// 004382f3  ffd0                 call eax
// 004382f5  85c0                 test eax, eax
// 004382f7  0f8430010000         je 0x43842d
// 004382fd  8d4c2414             lea ecx, [esp + 0x14]
// 00438301  51                   push ecx
// 00438302  8bce                 mov ecx, esi
// 00438304  e8e7982d00           call 0x711bf0
// 00438309  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 0043830f  8d542414             lea edx, [esp + 0x14]
// 00438313  52                   push edx
// 00438314  e819892600           call 0x6a0c32
// 00438319  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043831d  0562ffffff           add eax, 0xffffff62
// 00438322  6a00                 push 0
// 00438324  89442418             mov dword ptr [esp + 0x18], eax
// 00438328  e8f3632b00           call 0x6ee720
// 0043832d  6884010000           push 0x184
// 00438332  8be8                 mov ebp, eax
// 00438334  e8e7852600           call 0x6a0920
// 00438339  83c408               add esp, 8
// 0043833c  89442434             mov dword ptr [esp + 0x34], eax
// 00438340  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00438348  85c0                 test eax, eax
// 0043834a  740b                 je 0x438357
// 0043834c  8bc8                 mov ecx, eax
// 0043834e  e80d690100           call 0x44ec60
// 00438353  8bf8                 mov edi, eax
// 00438355  eb02                 jmp 0x438359
// 00438357  33ff                 xor edi, edi
// 00438359  8b8dfc000000         mov ecx, dword ptr [ebp + 0xfc]
// 0043835f  6a00                 push 0
// 00438361  6aff                 push -1
// 00438363  6a00                 push 0
// 00438365  6a00                 push 0
// 00438367  57                   push edi
// 00438368  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00438370  e85bc52b00           call 0x6f48d0
// 00438375  8d4c2434             lea ecx, [esp + 0x34]
// 00438379  51                   push ecx
// 0043837a  8bce                 mov ecx, esi
// 0043837c  e84ffbffff           call 0x437ed0
// 00438381  6816b78000           push 0x80b716
// 00438386  8bc8                 mov ecx, eax
// 00438388  c744243001000000     mov dword ptr [esp + 0x30], 1
// 00438390  ff15f02f8000         call dword ptr [0x802ff0]
// 00438396  85c0                 test eax, eax
// 00438398  8d4c2434             lea ecx, [esp + 0x34]
// 0043839c  0f95c3               setne bl
// 0043839f  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004383a7  ff15143f8000         call dword ptr [0x803f14]
// 004383ad  84db                 test bl, bl
// 004383af  7414                 je 0x4383c5
// 004383b1  8b16                 mov edx, dword ptr [esi]
// 004383b3  8b82e8000000         mov eax, dword ptr [edx + 0xe8]
// 004383b9  8bce                 mov ecx, esi
// 004383bb  ffd0                 call eax
// 004383bd  50                   push eax
// 004383be  8bcf                 mov ecx, edi
// 004383c0  e84b5a0100           call 0x44de10
// 004383c5  e8848a2600           call 0x6a0e4e
// 004383ca  85c0                 test eax, eax
// 004383cc  740b                 je 0x4383d9
// 004383ce  8b10                 mov edx, dword ptr [eax]
// 004383d0  8bc8                 mov ecx, eax
// 004383d2  8b427c               mov eax, dword ptr [edx + 0x7c]
// 004383d5  ffd0                 call eax
// 004383d7  eb02                 jmp 0x4383db
// 004383d9  33c0                 xor eax, eax
// 004383db  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004383df  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004383e3  6a00                 push 0
// 004383e5  6a00                 push 0
// 004383e7  50                   push eax
// 004383e8  51                   push ecx
// 004383e9  52                   push edx
// 004383ea  6888000000           push 0x88
// 004383ef  55                   push ebp
// 004383f0  e8bbcb2600           call 0x6a4fb0
// 004383f5  83c41c               add esp, 0x1c
// 004383f8  85c0                 test eax, eax
// 004383fa  742a                 je 0x438426
// 004383fc  80bf7c01000000       cmp byte ptr [edi + 0x17c], 0
// 00438403  7421                 je 0x438426
// 00438405  8bcf                 mov ecx, edi
// 00438407  e8f4590100           call 0x44de00
// 0043840c  51                   push ecx
// 0043840d  8bcc                 mov ecx, esp
// 0043840f  89642414             mov dword ptr [esp + 0x14], esp
// 00438413  50                   push eax
// 00438414  51                   push ecx
// 00438415  e806f6ffff           call 0x437a20
// 0043841a  8b16                 mov edx, dword ptr [esi]
// 0043841c  8b4264               mov eax, dword ptr [edx + 0x64]
// 0043841f  83c408               add esp, 8
// 00438422  8bce                 mov ecx, esi
// 00438424  ffd0                 call eax
// 00438426  8bcd                 mov ecx, ebp
// 00438428  e8b7872600           call 0x6a0be4
// 0043842d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00438431  5f                   pop edi
// 00438432  5e                   pop esi
// 00438433  5d                   pop ebp
// 00438434  64890d00000000       mov dword ptr fs:[0], ecx
// 0043843b  5b                   pop ebx
// 0043843c  83c420               add esp, 0x20
// 0043843f  c20400               ret 4

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct Str {
    int words[8];
};

extern int (__thiscall* string_compare)(Str*, const char*);
extern void (__thiscall* string_destroy)(Str*);

struct StringTemporary {
    int storage;
    operator Str*();
    ~StringTemporary();
};

inline StringTemporary::operator Str*()
{
    return reinterpret_cast<Str*>(this);
}

inline StringTemporary::~StringTemporary()
{
    string_destroy(reinterpret_cast<Str*>(this));
}

struct Rect {
    int left, top, right, bottom;
};

struct Value {
    int data;
    Value(int);
    Value(const Value&);
    ~Value();
};

extern Value __cdecl make_value(int);

struct Grid {
    int notify(int, int);
    void convert_rect(Rect*);
};

struct Popup {
    char padding[0x17c];
    unsigned char accepted;
    char padding2[3];
    int color;

    Popup();
    void set_color(int);
    int get_color();
};

struct Manager {
    void attach(Popup*, int, int, int, int);
};

struct Owner {
    char padding[0xfc];
    Manager* manager;
    void release();
};

struct Window {
    void** table;
};

extern Owner* __cdecl get_owner(int);
extern Window* __cdecl get_window();
extern int __cdecl show_popup(Owner*, int, int, int, int, int, int);

struct Item {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void set_value(Value);

    char padding[0xb8];
    Grid* grid;

    void get_rect(Rect*);
    StringTemporary copy();
    void activate(int);
};

void Item::activate(int argument)
{
    if (grid->notify(5, argument) == 1)
        return;

    if (!reinterpret_cast<int (__thiscall*)(Item*)>(
            (*reinterpret_cast<void***>(this))[0x90 / 4])(this))
        return;

    Rect rect;
    get_rect(&rect);
    grid->convert_rect(&rect);
    rect.left = rect.right - 158;

    Owner* owner = get_owner(0);
    Popup* popup = new Popup;
    owner->manager->attach(popup, 0, 0, -1, 0);

    bool authoring = string_compare(copy(), "") != 0;

    if (authoring)
        popup->set_color(
            reinterpret_cast<int (__thiscall*)(Item*)>(
                (*reinterpret_cast<void***>(this))[0xe8 / 4])(this));

    Window* window = get_window();
    int handle = window
        ? reinterpret_cast<int (__thiscall*)(Window*)>(
            window->table[0x7c / 4])(window)
        : 0;

    if (show_popup(owner, 0x88, rect.right, rect.bottom, handle, 0, 0)
        && popup->accepted)
    {
        int color = popup->get_color();
        reinterpret_cast<void (__thiscall*)(Item*, Value)>(
            (*reinterpret_cast<void***>(this))[0x64 / 4])(this, make_value(color));
    }

    owner->release();
}