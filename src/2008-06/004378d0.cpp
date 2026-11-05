// from server: 100% by colin
// from server: 96% by colin
// roc 2008-06 004378d0  unit: HVCXTPPropertyGridItem::?$XItem  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004378d0
//
// 004378d0  83ec20               sub esp, 0x20
// 004378d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 004378d7  56                   push esi
// 004378d8  8bf1                 mov esi, ecx
// 004378da  8b08                 mov ecx, dword ptr [eax]
// 004378dc  51                   push ecx
// 004378dd  8d542408             lea edx, [esp + 8]
// 004378e1  68d0358100           push 0x8135d0
// 004378e6  52                   push edx
// 004378e7  ff1530288000         call dword ptr [0x802830]
// 004378ed  83c408               add esp, 8
// 004378f0  8d442408             lea eax, [esp + 8]
// 004378f4  8bcc                 mov ecx, esp
// 004378f6  8964242c             mov dword ptr [esp + 0x2c], esp
// 004378fa  50                   push eax
// 004378fb  ff15103f8000         call dword ptr [0x803f10]
// 00437901  8b16                 mov edx, dword ptr [esi]
// 00437903  8b4260               mov eax, dword ptr [edx + 0x60]
// 00437906  8bce                 mov ecx, esi
// 00437908  ffd0                 call eax
// 0043790a  5e                   pop esi
// 0043790b  83c420               add esp, 0x20
// 0043790e  c20400               ret 4

extern "C" {
    extern int (__cdecl *sprintf)(char *, const char *, ...);
}

struct Text;
extern void (__thiscall *constructText)(Text *, const char *);

struct Text {
    void *data;
    __declspec(dllimport) Text(const char *s);
    Text(const Text &);
    ~Text();
};

struct Item {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void setText(Text);

    void setValue(const int *);
};

extern const char formatString[];

void Item::setValue(const int *value)
{
    char buffer[32];
    sprintf(buffer, formatString, *value);
    setText(Text(buffer));
}
