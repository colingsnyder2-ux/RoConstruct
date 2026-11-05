// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0043d8c0  unit: Vector3ComponentItem  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043d8c0
//
// 0043d8c0  83ec20               sub esp, 0x20
// 0043d8c3  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043d8c7  d900                 fld dword ptr [eax]
// 0043d8c9  56                   push esi
// 0043d8ca  8bf1                 mov esi, ecx
// 0043d8cc  d99e34010000         fstp dword ptr [esi + 0x134]
// 0043d8d2  83ec08               sub esp, 8
// 0043d8d5  d94004               fld dword ptr [eax + 4]
// 0043d8d8  8d54240c             lea edx, [esp + 0xc]
// 0043d8dc  d99e38010000         fstp dword ptr [esi + 0x138]
// 0043d8e2  d94008               fld dword ptr [eax + 8]
// 0043d8e5  d99e3c010000         fstp dword ptr [esi + 0x13c]
// 0043d8eb  8b8e30010000         mov ecx, dword ptr [esi + 0x130]
// 0043d8f1  d90488               fld dword ptr [eax + ecx*4]
// 0043d8f4  dd1c24               fstp qword ptr [esp]
// 0043d8f7  68c8358100           push 0x8135c8
// 0043d8fc  52                   push edx
// 0043d8fd  ff1530288000         call dword ptr [0x802830]
// 0043d903  83c40c               add esp, 0xc
// 0043d906  8d442408             lea eax, [esp + 8]
// 0043d90a  8bcc                 mov ecx, esp
// 0043d90c  8964242c             mov dword ptr [esp + 0x2c], esp
// 0043d910  50                   push eax
// 0043d911  ff15103f8000         call dword ptr [0x803f10]
// 0043d917  8b16                 mov edx, dword ptr [esi]
// 0043d919  8b4260               mov eax, dword ptr [edx + 0x60]
// 0043d91c  8bce                 mov ecx, esi
// 0043d91e  ffd0                 call eax
// 0043d920  5e                   pop esi
// 0043d921  83c420               add esp, 0x20
// 0043d924  c20400               ret 4

extern "C" {
    extern int (__cdecl *sprintf)(char *, const char *, ...);
}

struct Text;
extern void (__thiscall *constructText)(Text *, const char *);

struct __declspec(dllimport) Text {
    void *data;
    Text(const char *);
    Text(const Text &);
    ~Text();
};

struct Vector3ComponentItem {
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

    char padding[0x12c];
    volatile int component;
    volatile float x;
    volatile float y;
    volatile float z;

    void setValue(const volatile float *);
};

void Vector3ComponentItem::setValue(const volatile float *value)
{
    char buffer[32];
    x = value[0];
    y = value[1];
    z = value[2];
    sprintf(buffer, "%.3g", value[component]);
    setText(Text(buffer));
}
