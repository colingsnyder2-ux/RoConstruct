// from server: 100% by EspClaude
// roc 2009-06 00444340  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 321 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444340
//
// 00444340  64a100000000         mov eax, dword ptr fs:[0]
// 00444346  6aff                 push -1
// 00444348  68d9b88500           push 0x85b8d9
// 0044434d  50                   push eax
// 0044434e  64892500000000       mov dword ptr fs:[0], esp
// 00444355  83ec20               sub esp, 0x20
// 00444358  56                   push esi
// 00444359  57                   push edi
// 0044435a  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0044435e  8bf1                 mov esi, ecx
// 00444360  8bcf                 mov ecx, edi
// 00444362  e8895c1c00           call 0x609ff0
// 00444367  84c0                 test al, al
// 00444369  0f85ff000000         jne 0x44446e
// 0044436f  53                   push ebx
// 00444370  8d5f10               lea ebx, [edi + 0x10]
// 00444373  55                   push ebp
// 00444374  8bcb                 mov ecx, ebx
// 00444376  e885561c00           call 0x609a00
// 0044437b  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0044437f  84c0                 test al, al
// 00444381  0f84bd000000         je 0x444444
// 00444387  8d4c2414             lea ecx, [esp + 0x14]
// 0044438b  ff15c0e48900         call dword ptr [0x89e4c0]
// 00444391  8d442414             lea eax, [esp + 0x14]
// 00444395  50                   push eax
// 00444396  8bcb                 mov ecx, ebx
// 00444398  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 004443a0  e86b561c00           call 0x609a10
// 004443a5  84c0                 test al, al
// 004443a7  0f8485000000         je 0x444432
// 004443ad  8d4c2414             lea ecx, [esp + 0x14]
// 004443b1  ff15bce48900         call dword ptr [0x89e4bc]
// 004443b7  8b7e20               mov edi, dword ptr [esi + 0x20]
// 004443ba  8d4c2444             lea ecx, [esp + 0x44]
// 004443be  51                   push ecx
// 004443bf  50                   push eax
// 004443c0  e8bb951800           call 0x5cd980
// 004443c5  83c404               add esp, 4
// 004443c8  50                   push eax
// 004443c9  8bcf                 mov ecx, edi
// 004443cb  e880a11a00           call 0x5ee550
// 004443d0  84c0                 test al, al
// 004443d2  7441                 je 0x444415
// 004443d4  8b542444             mov edx, dword ptr [esp + 0x44]
// 004443d8  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 004443db  89542444             mov dword ptr [esp + 0x44], edx
// 004443df  8b01                 mov eax, dword ptr [ecx]
// 004443e1  8b400c               mov eax, dword ptr [eax + 0xc]
// 004443e4  8d542444             lea edx, [esp + 0x44]
// 004443e8  52                   push edx
// 004443e9  8bd5                 mov edx, ebp
// 004443eb  52                   push edx
// 004443ec  ffd0                 call eax
// 004443ee  8d4c2414             lea ecx, [esp + 0x14]
// 004443f2  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 004443fa  ff15c4e48900         call dword ptr [0x89e4c4]
// 00444400  5d                   pop ebp
// 00444401  5b                   pop ebx
// 00444402  5f                   pop edi
// 00444403  5e                   pop esi
// 00444404  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00444408  64890d00000000       mov dword ptr fs:[0], ecx
// 0044440f  83c42c               add esp, 0x2c
// 00444412  c20c00               ret 0xc
// 00444415  8d4c2414             lea ecx, [esp + 0x14]
// 00444419  ff1568e48900         call dword ptr [0x89e468]
// 0044441f  85c0                 test eax, eax
// 00444421  750f                 jne 0x444432
// 00444423  8b16                 mov edx, dword ptr [esi]
// 00444425  50                   push eax
// 00444426  8b4234               mov eax, dword ptr [edx + 0x34]
// 00444429  55                   push ebp
// 0044442a  8bce                 mov ecx, esi
// 0044442c  ffd0                 call eax
// 0044442e  84c0                 test al, al
// 00444430  75bc                 jne 0x4443ee
// 00444432  8d4c2414             lea ecx, [esp + 0x14]
// 00444436  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0044443e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00444444  8d4c2410             lea ecx, [esp + 0x10]
// 00444448  51                   push ecx
// 00444449  8bcb                 mov ecx, ebx
// 0044444b  e890581c00           call 0x609ce0
// 00444450  84c0                 test al, al
// 00444452  7418                 je 0x44446c
// 00444454  8b542410             mov edx, dword ptr [esp + 0x10]
// 00444458  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0044445b  89542440             mov dword ptr [esp + 0x40], edx
// 0044445f  8b01                 mov eax, dword ptr [ecx]
// 00444461  8b400c               mov eax, dword ptr [eax + 0xc]
// 00444464  8d542440             lea edx, [esp + 0x40]
// 00444468  52                   push edx
// 00444469  55                   push ebp
// 0044446a  ffd0                 call eax
// 0044446c  5d                   pop ebp
// 0044446d  5b                   pop ebx
// 0044446e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00444472  5f                   pop edi
// 00444473  5e                   pop esi
// 00444474  64890d00000000       mov dword ptr fs:[0], ecx
// 0044447b  83c42c               add esp, 0x2c
// 0044447e  c20c00               ret 0xc
// copied from an identical function in another client (function ?read@S@ns_ROCX00003c@@QAEXPAXPAUElement@2@H@Z)

namespace ns_ROCX00003c {
struct String
{
    char storage[28];
    __declspec(dllimport) String();
    __declspec(dllimport) ~String();
    __declspec(dllimport) const char* data() const;
    __declspec(dllimport) unsigned int size() const;
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
            if (convertToValue(text.data(), val))
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
