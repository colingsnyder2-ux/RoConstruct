// from server: 100% by EspClaude
// roc 2009-06 00663c50  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 308 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663c50
//
// 00663c50  64a100000000         mov eax, dword ptr fs:[0]
// 00663c56  6aff                 push -1
// 00663c58  68d9b88500           push 0x85b8d9
// 00663c5d  50                   push eax
// 00663c5e  64892500000000       mov dword ptr fs:[0], esp
// 00663c65  83ec24               sub esp, 0x24
// 00663c68  55                   push ebp
// 00663c69  56                   push esi
// 00663c6a  8b742440             mov esi, dword ptr [esp + 0x40]
// 00663c6e  8be9                 mov ebp, ecx
// 00663c70  8bce                 mov ecx, esi
// 00663c72  e87963faff           call 0x609ff0
// 00663c77  84c0                 test al, al
// 00663c79  0f85f2000000         jne 0x663d71
// 00663c7f  53                   push ebx
// 00663c80  8d5e10               lea ebx, [esi + 0x10]
// 00663c83  8bcb                 mov ecx, ebx
// 00663c85  e8765dfaff           call 0x609a00
// 00663c8a  84c0                 test al, al
// 00663c8c  0f84b2000000         je 0x663d44
// 00663c92  8d4c2414             lea ecx, [esp + 0x14]
// 00663c96  ff15c0e48900         call dword ptr [0x89e4c0]
// 00663c9c  8d442414             lea eax, [esp + 0x14]
// 00663ca0  50                   push eax
// 00663ca1  8bcb                 mov ecx, ebx
// 00663ca3  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 00663cab  e8605dfaff           call 0x609a10
// 00663cb0  84c0                 test al, al
// 00663cb2  747e                 je 0x663d32
// 00663cb4  837c242c10           cmp dword ptr [esp + 0x2c], 0x10
// 00663cb9  57                   push edi
// 00663cba  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00663cbe  7304                 jae 0x663cc4
// 00663cc0  8d7c241c             lea edi, [esp + 0x1c]
// 00663cc4  6800f75e00           push 0x5ef700
// 00663cc9  68eca4a400           push 0xa4a4ec
// 00663cce  e83ddad9ff           call 0x401710
// 00663cd3  83c408               add esp, 8
// 00663cd6  e8c5b9f8ff           call 0x5ef6a0
// 00663cdb  8d4c2448             lea ecx, [esp + 0x48]
// 00663cdf  51                   push ecx
// 00663ce0  57                   push edi
// 00663ce1  8bf0                 mov esi, eax
// 00663ce3  e8989cf6ff           call 0x5cd980
// 00663ce8  83c404               add esp, 4
// 00663ceb  50                   push eax
// 00663cec  8bce                 mov ecx, esi
// 00663cee  e85da8f8ff           call 0x5ee550
// 00663cf3  5f                   pop edi
// 00663cf4  84c0                 test al, al
// 00663cf6  743a                 je 0x663d32
// 00663cf8  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 00663cfb  8b11                 mov edx, dword ptr [ecx]
// 00663cfd  8b520c               mov edx, dword ptr [edx + 0xc]
// 00663d00  8d442444             lea eax, [esp + 0x44]
// 00663d04  50                   push eax
// 00663d05  8b442444             mov eax, dword ptr [esp + 0x44]
// 00663d09  50                   push eax
// 00663d0a  ffd2                 call edx
// 00663d0c  8d4c2414             lea ecx, [esp + 0x14]
// 00663d10  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00663d18  ff15c4e48900         call dword ptr [0x89e4c4]
// 00663d1e  5b                   pop ebx
// 00663d1f  5e                   pop esi
// 00663d20  5d                   pop ebp
// 00663d21  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00663d25  64890d00000000       mov dword ptr fs:[0], ecx
// 00663d2c  83c430               add esp, 0x30
// 00663d2f  c20c00               ret 0xc
// 00663d32  8d4c2414             lea ecx, [esp + 0x14]
// 00663d36  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 00663d3e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00663d44  8d44240c             lea eax, [esp + 0xc]
// 00663d48  50                   push eax
// 00663d49  8bcb                 mov ecx, ebx
// 00663d4b  e8905ffaff           call 0x609ce0
// 00663d50  84c0                 test al, al
// 00663d52  741c                 je 0x663d70
// 00663d54  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00663d58  894c2410             mov dword ptr [esp + 0x10], ecx
// 00663d5c  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 00663d5f  8b11                 mov edx, dword ptr [ecx]
// 00663d61  8b520c               mov edx, dword ptr [edx + 0xc]
// 00663d64  8d442410             lea eax, [esp + 0x10]
// 00663d68  50                   push eax
// 00663d69  8b442444             mov eax, dword ptr [esp + 0x44]
// 00663d6d  50                   push eax
// 00663d6e  ffd2                 call edx
// 00663d70  5b                   pop ebx
// 00663d71  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663d75  5e                   pop esi
// 00663d76  5d                   pop ebp
// 00663d77  64890d00000000       mov dword ptr fs:[0], ecx
// 00663d7e  83c430               add esp, 0x30
// 00663d81  c20c00               ret 0xc
// copied from an identical function in another client (function ?read@S@ns_ROCX000016@@QAEXPAXPAUElement@2@H@Z)

namespace ns_ROCX000016 {
struct String {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    String();
    ~String();
};

extern void (__thiscall* stringConstructor)(String*);
extern void (__thiscall* stringDestructor)(String*);

__forceinline String::String()
{
    stringConstructor(this);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

struct Name;

struct Value {
    unsigned int name;
    unsigned int type;
    void* data;

    bool isString() const;
    bool getString(String* result) const;
    bool getInteger(int* result) const;
};

struct Element {
    char padding[16];
    Value value;

    bool isNull() const;
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, const int* value);
};

struct EnumDescriptor {
    bool convert(const Name& name, int* result);
};

extern void __cdecl initializeEnum();
extern int enumFlag;
extern void __cdecl registerEnum(void (__cdecl* initializer)(), int* flag);
extern EnumDescriptor* __cdecl getEnumDescriptor();
extern const Name& __cdecl getName(const char* text);

struct S {
    char padding[28];
    Setter* setter;

    void read(void* instance, Element* element, int unused);
};

void S::read(void* instance, Element* element, int unused)
{
    if (element->isNull())
        return;

    Value* source = &element->value;
    if (source->isString()) {
        String text;
        if (source->getString(&text)) {
            const char* characters =
                text.capacity >= 16 ? text.pointer : text.buffer;
            registerEnum(initializeEnum, &enumFlag);
            EnumDescriptor* descriptor = getEnumDescriptor();
            int value;
            if (descriptor->convert(getName(characters), &value)) {
                setter->set(instance, &value);
                return;
            }
        }
    }

    int integer;
    if (source->getInteger(&integer)) {
        int converted = integer;
        setter->set(instance, &converted);
    }
}
}
