// from server: 100% by EspClaude
// roc 2009-06 006c1040  unit: VWaitScriptSlot::?$TGenericSlotWrapper  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c1040
//
// 006c1040  64a100000000         mov eax, dword ptr fs:[0]
// 006c1046  6aff                 push -1
// 006c1048  68789d8600           push 0x869d78
// 006c104d  50                   push eax
// 006c104e  64892500000000       mov dword ptr fs:[0], esp
// 006c1055  83ec0c               sub esp, 0xc
// 006c1058  56                   push esi
// 006c1059  8b742420             mov esi, dword ptr [esp + 0x20]
// 006c105d  85f6                 test esi, esi
// 006c105f  742c                 je 0x6c108d
// 006c1061  8b0e                 mov ecx, dword ptr [esi]
// 006c1063  85c9                 test ecx, ecx
// 006c1065  7409                 je 0x6c1070
// 006c1067  8b01                 mov eax, dword ptr [ecx]
// 006c1069  8b5004               mov edx, dword ptr [eax + 4]
// 006c106c  ffd2                 call edx
// 006c106e  eb05                 jmp 0x6c1075
// 006c1070  b8d4c29d00           mov eax, 0x9dc2d4
// 006c1075  6808f39f00           push 0x9ff308
// 006c107a  8bc8                 mov ecx, eax
// 006c107c  ff15a4e98900         call dword ptr [0x89e9a4]
// 006c1082  84c0                 test al, al
// 006c1084  7407                 je 0x6c108d
// 006c1086  8b06                 mov eax, dword ptr [esi]
// 006c1088  83c004               add eax, 4
// 006c108b  7529                 jne 0x6c10b6
// 006c108d  6850d38a00           push 0x8ad350
// 006c1092  8d4c2408             lea ecx, [esp + 8]
// 006c1096  ff1570e98900         call dword ptr [0x89e970]
// 006c109c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006c10a4  8d442404             lea eax, [esp + 4]
// 006c10a8  50                   push eax
// 006c10a9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006c10b1  e80a92d4ff           call 0x40a2c0
// 006c10b6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c10ba  5e                   pop esi
// 006c10bb  64890d00000000       mov dword ptr fs:[0], ecx
// 006c10c2  83c418               add esp, 0x18
// 006c10c5  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000002@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000002 {
namespace std {
    class type_info {
    public:
        bool operator==(const type_info&) const;
    };
}

extern bool (__thiscall* typeInfoEqual)(
    const std::type_info*, const std::type_info&);

inline bool std::type_info::operator==(const type_info& other) const {
    return typeInfoEqual(this, other);
}

struct BadAnyCast {
    const void* table;
    const char* message;
    int owned;

    BadAnyCast();
    ~BadAnyCast();
};

extern BadAnyCast* (__thiscall* badCastConstructor)(
    BadAnyCast*, const char*);
extern const void* badAnyCastTable[];

inline BadAnyCast::BadAnyCast() {
    badCastConstructor(this, "bad cast");
    table = badAnyCastTable;
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const std::type_info& type() const = 0;
};

struct Any {
    Placeholder* content;
};

extern const std::type_info placeholderType;
extern const std::type_info vectorType;

__declspec(noreturn) void __cdecl throwBadCast(const BadAnyCast&);

void* __cdecl castValue(const Any* value) {
    if (value) {
        const std::type_info& type =
            value->content ? value->content->type() : placeholderType;
        if (type == vectorType) {
            void* result = reinterpret_cast<char*>(value->content) + 4;
            if (result)
                return result;
        }
    }
    throwBadCast(BadAnyCast());
}
}
