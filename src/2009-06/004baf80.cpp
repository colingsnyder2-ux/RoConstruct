// from server: 100% by EspClaude
// roc 2009-06 004baf80  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004baf80
//
// 004baf80  64a100000000         mov eax, dword ptr fs:[0]
// 004baf86  6aff                 push -1
// 004baf88  68789d8600           push 0x869d78
// 004baf8d  50                   push eax
// 004baf8e  64892500000000       mov dword ptr fs:[0], esp
// 004baf95  83ec0c               sub esp, 0xc
// 004baf98  56                   push esi
// 004baf99  8b742420             mov esi, dword ptr [esp + 0x20]
// 004baf9d  85f6                 test esi, esi
// 004baf9f  742c                 je 0x4bafcd
// 004bafa1  8b0e                 mov ecx, dword ptr [esi]
// 004bafa3  85c9                 test ecx, ecx
// 004bafa5  7409                 je 0x4bafb0
// 004bafa7  8b01                 mov eax, dword ptr [ecx]
// 004bafa9  8b5004               mov edx, dword ptr [eax + 4]
// 004bafac  ffd2                 call edx
// 004bafae  eb05                 jmp 0x4bafb5
// 004bafb0  b8d4c29d00           mov eax, 0x9dc2d4
// 004bafb5  68e0d39e00           push 0x9ed3e0
// 004bafba  8bc8                 mov ecx, eax
// 004bafbc  ff15a4e98900         call dword ptr [0x89e9a4]
// 004bafc2  84c0                 test al, al
// 004bafc4  7407                 je 0x4bafcd
// 004bafc6  8b06                 mov eax, dword ptr [esi]
// 004bafc8  83c004               add eax, 4
// 004bafcb  7529                 jne 0x4baff6
// 004bafcd  6850d38a00           push 0x8ad350
// 004bafd2  8d4c2408             lea ecx, [esp + 8]
// 004bafd6  ff1570e98900         call dword ptr [0x89e970]
// 004bafdc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 004bafe4  8d442404             lea eax, [esp + 4]
// 004bafe8  50                   push eax
// 004bafe9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004baff1  e8caf2f4ff           call 0x40a2c0
// 004baff6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004baffa  5e                   pop esi
// 004baffb  64890d00000000       mov dword ptr fs:[0], ecx
// 004bb002  83c418               add esp, 0x18
// 004bb005  c3                   ret 
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
