// from server: 100% by colin
// from server: 97% by colin
// roc 2008-06 00437880  unit: MVCXTPPropertyGridItem::?$XItem  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00437880
//
// 00437880  83ec20               sub esp, 0x20
// 00437883  8b442424             mov eax, dword ptr [esp + 0x24]
// 00437887  d900                 fld dword ptr [eax]
// 00437889  56                   push esi
// 0043788a  83ec08               sub esp, 8
// 0043788d  dd1c24               fstp qword ptr [esp]
// 00437890  8bf1                 mov esi, ecx
// 00437892  8d4c240c             lea ecx, [esp + 0xc]
// 00437896  68c8358100           push 0x8135c8
// 0043789b  51                   push ecx
// 0043789c  ff1530288000         call dword ptr [0x802830]
// 004378a2  83c40c               add esp, 0xc
// 004378a5  8d542408             lea edx, [esp + 8]
// 004378a9  8bcc                 mov ecx, esp
// 004378ab  8964242c             mov dword ptr [esp + 0x2c], esp
// 004378af  52                   push edx
// 004378b0  ff15103f8000         call dword ptr [0x803f10]
// 004378b6  8b06                 mov eax, dword ptr [esi]
// 004378b8  8b5060               mov edx, dword ptr [eax + 0x60]
// 004378bb  8bce                 mov ecx, esi
// 004378bd  ffd2                 call edx
// 004378bf  5e                   pop esi
// 004378c0  83c420               add esp, 0x20
// 004378c3  c20400               ret 4

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

struct S {
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

    void setValue(const float *);
};

void S::setValue(const float *value)
{
    char buffer[32];
    sprintf(buffer, "%.3g", *value);
    setText(Text(buffer));
}
