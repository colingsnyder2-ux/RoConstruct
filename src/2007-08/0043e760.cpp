// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 0043e760  unit: Vector3ComponentItem  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e760
//
// 0043e760  83ec28               sub esp, 0x28
// 0043e763  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e768  33c4                 xor eax, esp
// 0043e76a  89442424             mov dword ptr [esp + 0x24], eax
// 0043e76e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043e772  d900                 fld dword ptr [eax]
// 0043e774  56                   push esi
// 0043e775  8bf1                 mov esi, ecx
// 0043e777  d99e20010000         fstp dword ptr [esi + 0x120]
// 0043e77d  83ec08               sub esp, 8
// 0043e780  d94004               fld dword ptr [eax + 4]
// 0043e783  8d542410             lea edx, [esp + 0x10]
// 0043e787  d99e24010000         fstp dword ptr [esi + 0x124]
// 0043e78d  d94008               fld dword ptr [eax + 8]
// 0043e790  d99e28010000         fstp dword ptr [esi + 0x128]
// 0043e796  8b8e1c010000         mov ecx, dword ptr [esi + 0x11c]
// 0043e79c  d90488               fld dword ptr [eax + ecx*4]
// 0043e79f  dd1c24               fstp qword ptr [esp]
// 0043e7a2  6898d37800           push 0x78d398
// 0043e7a7  52                   push edx
// 0043e7a8  ff1568e97700         call dword ptr [0x77e968]
// 0043e7ae  83c40c               add esp, 0xc
// 0043e7b1  8d44240c             lea eax, [esp + 0xc]
// 0043e7b5  8bcc                 mov ecx, esp
// 0043e7b7  89642408             mov dword ptr [esp + 8], esp
// 0043e7bb  50                   push eax
// 0043e7bc  ff15b8dd7700         call dword ptr [0x77ddb8]
// 0043e7c2  8b16                 mov edx, dword ptr [esi]
// 0043e7c4  8b4260               mov eax, dword ptr [edx + 0x60]
// 0043e7c7  8bce                 mov ecx, esi
// 0043e7c9  ffd0                 call eax
// 0043e7cb  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043e7cf  5e                   pop esi
// 0043e7d0  33cc                 xor ecx, esp
// 0043e7d2  e847221f00           call 0x630a1e
// 0043e7d7  83c428               add esp, 0x28
// 0043e7da  c20400               ret 4

extern "C" {
    extern int (__cdecl *sprintf)(char *, const char *, ...);
}

struct Vector3 { float x, y, z; float operator[](int i) const { return (&x)[i]; }
    Vector3 &operator=(const Vector3 &o) { x = o.x; y = o.y; z = o.z; return *this; } };

struct Text {
    void *data;
    __declspec(dllimport) Text(const char *s);
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

    char pad[0x11c - 4];
    int component;
    Vector3 value;

    void setValue(const Vector3 &);
};

void Vector3ComponentItem::setValue(const Vector3 &v)
{
    value = v;
    char buffer[32];
    sprintf(buffer, "%.3g", v[component]);
    setText(Text(buffer));
}
