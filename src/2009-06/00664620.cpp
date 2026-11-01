// from server: 100% by EspClaude
// roc 2009-06 00664620  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 308 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664620
//
// 00664620  64a100000000         mov eax, dword ptr fs:[0]
// 00664626  6aff                 push -1
// 00664628  68d9b88500           push 0x85b8d9
// 0066462d  50                   push eax
// 0066462e  64892500000000       mov dword ptr fs:[0], esp
// 00664635  83ec24               sub esp, 0x24
// 00664638  55                   push ebp
// 00664639  56                   push esi
// 0066463a  8b742440             mov esi, dword ptr [esp + 0x40]
// 0066463e  8be9                 mov ebp, ecx
// 00664640  8bce                 mov ecx, esi
// 00664642  e8a959faff           call 0x609ff0
// 00664647  84c0                 test al, al
// 00664649  0f85f2000000         jne 0x664741
// 0066464f  53                   push ebx
// 00664650  8d5e10               lea ebx, [esi + 0x10]
// 00664653  8bcb                 mov ecx, ebx
// 00664655  e8a653faff           call 0x609a00
// 0066465a  84c0                 test al, al
// 0066465c  0f84b2000000         je 0x664714
// 00664662  8d4c2414             lea ecx, [esp + 0x14]
// 00664666  ff15c0e48900         call dword ptr [0x89e4c0]
// 0066466c  8d442414             lea eax, [esp + 0x14]
// 00664670  50                   push eax
// 00664671  8bcb                 mov ecx, ebx
// 00664673  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0066467b  e89053faff           call 0x609a10
// 00664680  84c0                 test al, al
// 00664682  747e                 je 0x664702
// 00664684  837c242c10           cmp dword ptr [esp + 0x2c], 0x10
// 00664689  57                   push edi
// 0066468a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0066468e  7304                 jae 0x664694
// 00664690  8d7c241c             lea edi, [esp + 0x1c]
// 00664694  6830f25e00           push 0x5ef230
// 00664699  68c0a4a400           push 0xa4a4c0
// 0066469e  e86dd0d9ff           call 0x401710
// 006646a3  83c408               add esp, 8
// 006646a6  e825abf8ff           call 0x5ef1d0
// 006646ab  8d4c2448             lea ecx, [esp + 0x48]
// 006646af  51                   push ecx
// 006646b0  57                   push edi
// 006646b1  8bf0                 mov esi, eax
// 006646b3  e8c892f6ff           call 0x5cd980
// 006646b8  83c404               add esp, 4
// 006646bb  50                   push eax
// 006646bc  8bce                 mov ecx, esi
// 006646be  e88d9ef8ff           call 0x5ee550
// 006646c3  5f                   pop edi
// 006646c4  84c0                 test al, al
// 006646c6  743a                 je 0x664702
// 006646c8  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 006646cb  8b11                 mov edx, dword ptr [ecx]
// 006646cd  8b520c               mov edx, dword ptr [edx + 0xc]
// 006646d0  8d442444             lea eax, [esp + 0x44]
// 006646d4  50                   push eax
// 006646d5  8b442444             mov eax, dword ptr [esp + 0x44]
// 006646d9  50                   push eax
// 006646da  ffd2                 call edx
// 006646dc  8d4c2414             lea ecx, [esp + 0x14]
// 006646e0  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 006646e8  ff15c4e48900         call dword ptr [0x89e4c4]
// 006646ee  5b                   pop ebx
// 006646ef  5e                   pop esi
// 006646f0  5d                   pop ebp
// 006646f1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006646f5  64890d00000000       mov dword ptr fs:[0], ecx
// 006646fc  83c430               add esp, 0x30
// 006646ff  c20c00               ret 0xc
// 00664702  8d4c2414             lea ecx, [esp + 0x14]
// 00664706  c7442438ffffffff     mov dword ptr [esp + 0x38], 0xffffffff
// 0066470e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00664714  8d44240c             lea eax, [esp + 0xc]
// 00664718  50                   push eax
// 00664719  8bcb                 mov ecx, ebx
// 0066471b  e8c055faff           call 0x609ce0
// 00664720  84c0                 test al, al
// 00664722  741c                 je 0x664740
// 00664724  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00664728  894c2410             mov dword ptr [esp + 0x10], ecx
// 0066472c  8b4d1c               mov ecx, dword ptr [ebp + 0x1c]
// 0066472f  8b11                 mov edx, dword ptr [ecx]
// 00664731  8b520c               mov edx, dword ptr [edx + 0xc]
// 00664734  8d442410             lea eax, [esp + 0x10]
// 00664738  50                   push eax
// 00664739  8b442444             mov eax, dword ptr [esp + 0x44]
// 0066473d  50                   push eax
// 0066473e  ffd2                 call edx
// 00664740  5b                   pop ebx
// 00664741  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00664745  5e                   pop esi
// 00664746  5d                   pop ebp
// 00664747  64890d00000000       mov dword ptr fs:[0], ecx
// 0066474e  83c430               add esp, 0x30
// 00664751  c20c00               ret 0xc
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
