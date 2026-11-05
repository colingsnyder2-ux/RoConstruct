// from server: 100% by Yeetserama
// roc 2007-08 004387c0  unit: HVCXTPPropertyGridItem::?$XItem  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004387c0
//
// 004387c0  83ec28               sub esp, 0x28
// 004387c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004387c8  33c4                 xor eax, esp
// 004387ca  89442424             mov dword ptr [esp + 0x24], eax
// 004387ce  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004387d2  8b00                 mov eax, dword ptr [eax]
// 004387d4  56                   push esi
// 004387d5  50                   push eax
// 004387d6  8bf1                 mov esi, ecx
// 004387d8  8d4c240c             lea ecx, [esp + 0xc]
// 004387dc  68a0d37800           push 0x78d3a0
// 004387e1  51                   push ecx
// 004387e2  ff1568e97700         call dword ptr [0x77e968]
// 004387e8  83c408               add esp, 8
// 004387eb  8d54240c             lea edx, [esp + 0xc]
// 004387ef  8bcc                 mov ecx, esp
// 004387f1  89642408             mov dword ptr [esp + 8], esp
// 004387f5  52                   push edx
// 004387f6  ff15b8dd7700         call dword ptr [0x77ddb8]
// 004387fc  8b06                 mov eax, dword ptr [esi]
// 004387fe  8b5060               mov edx, dword ptr [eax + 0x60]
// 00438801  8bce                 mov ecx, esi
// 00438803  ffd2                 call edx
// 00438805  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00438809  5e                   pop esi
// 0043880a  33cc                 xor ecx, esp
// 0043880c  e80d821f00           call 0x630a1e
// 00438811  83c428               add esp, 0x28
// 00438814  c20400               ret 4
// copied from an identical function in another client (function ?setValue@Item@ns_ROCX000003@@QAEXPBH@Z)

namespace ns_ROCX000003 {
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
}
