// from server: 100% by EspClaude
// roc 2009-06 0066eb00  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066eb00
//
// 0066eb00  64a100000000         mov eax, dword ptr fs:[0]
// 0066eb06  6aff                 push -1
// 0066eb08  68789d8600           push 0x869d78
// 0066eb0d  50                   push eax
// 0066eb0e  64892500000000       mov dword ptr fs:[0], esp
// 0066eb15  83ec0c               sub esp, 0xc
// 0066eb18  56                   push esi
// 0066eb19  8b742420             mov esi, dword ptr [esp + 0x20]
// 0066eb1d  85f6                 test esi, esi
// 0066eb1f  742c                 je 0x66eb4d
// 0066eb21  8b0e                 mov ecx, dword ptr [esi]
// 0066eb23  85c9                 test ecx, ecx
// 0066eb25  7409                 je 0x66eb30
// 0066eb27  8b01                 mov eax, dword ptr [ecx]
// 0066eb29  8b5004               mov edx, dword ptr [eax + 4]
// 0066eb2c  ffd2                 call edx
// 0066eb2e  eb05                 jmp 0x66eb35
// 0066eb30  b8d4c29d00           mov eax, 0x9dc2d4
// 0066eb35  688064a100           push 0xa16480
// 0066eb3a  8bc8                 mov ecx, eax
// 0066eb3c  ff15a4e98900         call dword ptr [0x89e9a4]
// 0066eb42  84c0                 test al, al
// 0066eb44  7407                 je 0x66eb4d
// 0066eb46  8b06                 mov eax, dword ptr [esi]
// 0066eb48  83c004               add eax, 4
// 0066eb4b  7529                 jne 0x66eb76
// 0066eb4d  6850d38a00           push 0x8ad350
// 0066eb52  8d4c2408             lea ecx, [esp + 8]
// 0066eb56  ff1570e98900         call dword ptr [0x89e970]
// 0066eb5c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 0066eb64  8d442404             lea eax, [esp + 4]
// 0066eb68  50                   push eax
// 0066eb69  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0066eb71  e84ab7d9ff           call 0x40a2c0
// 0066eb76  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066eb7a  5e                   pop esi
// 0066eb7b  64890d00000000       mov dword ptr fs:[0], ecx
// 0066eb82  83c418               add esp, 0x18
// 0066eb85  c3                   ret 
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
