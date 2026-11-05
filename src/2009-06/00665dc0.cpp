// from server: 100% by EspClaude
// roc 2009-06 00665dc0  unit: RBX::VNetworkSettings::?$EnumPropDescriptor  size: 322 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00665dc0
//
// 00665dc0  64a100000000         mov eax, dword ptr fs:[0]
// 00665dc6  6aff                 push -1
// 00665dc8  68d9b88500           push 0x85b8d9
// 00665dcd  50                   push eax
// 00665dce  64892500000000       mov dword ptr fs:[0], esp
// 00665dd5  83ec20               sub esp, 0x20
// 00665dd8  56                   push esi
// 00665dd9  57                   push edi
// 00665dda  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 00665dde  8bf1                 mov esi, ecx
// 00665de0  8bcf                 mov ecx, edi
// 00665de2  e80942faff           call 0x609ff0
// 00665de7  84c0                 test al, al
// 00665de9  0f8500010000         jne 0x665eef
// 00665def  53                   push ebx
// 00665df0  8d5f10               lea ebx, [edi + 0x10]
// 00665df3  55                   push ebp
// 00665df4  8bcb                 mov ecx, ebx
// 00665df6  e8053cfaff           call 0x609a00
// 00665dfb  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00665dff  84c0                 test al, al
// 00665e01  0f84be000000         je 0x665ec5
// 00665e07  8d4c2414             lea ecx, [esp + 0x14]
// 00665e0b  ff15c0e48900         call dword ptr [0x89e4c0]
// 00665e11  8d442414             lea eax, [esp + 0x14]
// 00665e15  50                   push eax
// 00665e16  8bcb                 mov ecx, ebx
// 00665e18  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 00665e20  e8eb3bfaff           call 0x609a10
// 00665e25  84c0                 test al, al
// 00665e27  0f8486000000         je 0x665eb3
// 00665e2d  837c242c10           cmp dword ptr [esp + 0x2c], 0x10
// 00665e32  8b442418             mov eax, dword ptr [esp + 0x18]
// 00665e36  7304                 jae 0x665e3c
// 00665e38  8d442418             lea eax, [esp + 0x18]
// 00665e3c  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00665e3f  8d4c2444             lea ecx, [esp + 0x44]
// 00665e43  51                   push ecx
// 00665e44  50                   push eax
// 00665e45  e8367bf6ff           call 0x5cd980
// 00665e4a  83c404               add esp, 4
// 00665e4d  50                   push eax
// 00665e4e  8bcf                 mov ecx, edi
// 00665e50  e8fb86f8ff           call 0x5ee550
// 00665e55  84c0                 test al, al
// 00665e57  7443                 je 0x665e9c
// 00665e59  8b542444             mov edx, dword ptr [esp + 0x44]
// 00665e5d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665e60  89542444             mov dword ptr [esp + 0x44], edx
// 00665e64  8b01                 mov eax, dword ptr [ecx]
// 00665e66  8b400c               mov eax, dword ptr [eax + 0xc]
// 00665e69  8d542444             lea edx, [esp + 0x44]
// 00665e6d  52                   push edx
// 00665e6e  8b542444             mov edx, dword ptr [esp + 0x44]
// 00665e72  52                   push edx
// 00665e73  ffd0                 call eax
// 00665e75  8d4c2414             lea ecx, [esp + 0x14]
// 00665e79  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00665e81  ff15c4e48900         call dword ptr [0x89e4c4]
// 00665e87  5d                   pop ebp
// 00665e88  5b                   pop ebx
// 00665e89  5f                   pop edi
// 00665e8a  5e                   pop esi
// 00665e8b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00665e8f  64890d00000000       mov dword ptr fs:[0], ecx
// 00665e96  83c42c               add esp, 0x2c
// 00665e99  c20c00               ret 0xc
// 00665e9c  837c242800           cmp dword ptr [esp + 0x28], 0
// 00665ea1  7510                 jne 0x665eb3
// 00665ea3  8b16                 mov edx, dword ptr [esi]
// 00665ea5  8b4234               mov eax, dword ptr [edx + 0x34]
// 00665ea8  6a00                 push 0
// 00665eaa  55                   push ebp
// 00665eab  8bce                 mov ecx, esi
// 00665ead  ffd0                 call eax
// 00665eaf  84c0                 test al, al
// 00665eb1  75c2                 jne 0x665e75
// 00665eb3  8d4c2414             lea ecx, [esp + 0x14]
// 00665eb7  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00665ebf  ff15c4e48900         call dword ptr [0x89e4c4]
// 00665ec5  8d4c2410             lea ecx, [esp + 0x10]
// 00665ec9  51                   push ecx
// 00665eca  8bcb                 mov ecx, ebx
// 00665ecc  e80f3efaff           call 0x609ce0
// 00665ed1  84c0                 test al, al
// 00665ed3  7418                 je 0x665eed
// 00665ed5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00665ed9  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665edc  89542440             mov dword ptr [esp + 0x40], edx
// 00665ee0  8b01                 mov eax, dword ptr [ecx]
// 00665ee2  8b400c               mov eax, dword ptr [eax + 0xc]
// 00665ee5  8d542440             lea edx, [esp + 0x40]
// 00665ee9  52                   push edx
// 00665eea  55                   push ebp
// 00665eeb  ffd0                 call eax
// 00665eed  5d                   pop ebp
// 00665eee  5b                   pop ebx
// 00665eef  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00665ef3  5f                   pop edi
// 00665ef4  5e                   pop esi
// 00665ef5  64890d00000000       mov dword ptr fs:[0], ecx
// 00665efc  83c42c               add esp, 0x2c
// 00665eff  c20c00               ret 0xc
// copied from an identical function in another client (function ?read@S@ns_ROCX000010@@QAEXPAXPAUElement@2@H@Z)

namespace ns_ROCX000010 {
struct String
{
    unsigned int proxy;
    union { char buffer[16]; char* pointer; } storage;
    unsigned int length;
    unsigned int capacity;
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
    const char* c_str() const { const char* p = storage.pointer; if (capacity < 16) p = storage.buffer; return p; }
    unsigned int size() const { return length; }
};

struct Name;
extern const Name& __cdecl lookupName(const char*);

enum EnumValue
{
    EnumValueZero = 0
};

struct Value
{
    bool isString() const;
    bool getString(String&) const;
    bool getInteger(int&) const;
};

struct Element
{
    char padding[16];
    Value value;
    bool isNull() const;
};

struct EnumDescriptor
{
    bool convert(const Name&, int&) const;
};

struct Setter
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const EnumValue&);
};

struct S
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual bool setEmpty(void*, int);

    char padding[24];
    Setter* setter;
    EnumDescriptor* descriptor;

    void read(void*, Element*, int);
    void setValue(void* o, EnumValue value) { setter->set(o, value); }
    __forceinline bool convertToValue(const char* text, EnumValue& value) { EnumDescriptor* d = descriptor; int v; if (d->convert(lookupName(text), v)) { value = (EnumValue)v; return true; } return false; }
};

void S::read(void* object, Element* element, int)
{
    if (element->isNull())
        return;
    if (element->value.isString())
    {
        String text;
        if (element->value.getString(text))
        {
            EnumValue val;
            if (convertToValue(text.c_str(), val))
            {
                setValue(object, val);
                return;
            }
            if (text.size() == 0 && setEmpty(object, 0))
                return;
        }
    }
    int value;
    if (element->value.getInteger(value))
        setValue(object, (EnumValue)value);
}
}
