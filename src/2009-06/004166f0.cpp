// from server: 100% by EspClaude
// roc 2009-06 004166f0  unit: CopyVerb  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004166f0
//
// 004166f0  64a100000000         mov eax, dword ptr fs:[0]
// 004166f6  6aff                 push -1
// 004166f8  68789d8600           push 0x869d78
// 004166fd  50                   push eax
// 004166fe  64892500000000       mov dword ptr fs:[0], esp
// 00416705  83ec0c               sub esp, 0xc
// 00416708  56                   push esi
// 00416709  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041670d  85f6                 test esi, esi
// 0041670f  742c                 je 0x41673d
// 00416711  8b0e                 mov ecx, dword ptr [esi]
// 00416713  85c9                 test ecx, ecx
// 00416715  7409                 je 0x416720
// 00416717  8b01                 mov eax, dword ptr [ecx]
// 00416719  8b5004               mov edx, dword ptr [eax + 4]
// 0041671c  ffd2                 call edx
// 0041671e  eb05                 jmp 0x416725
// 00416720  b8d4c29d00           mov eax, 0x9dc2d4
// 00416725  68e8f29d00           push 0x9df2e8
// 0041672a  8bc8                 mov ecx, eax
// 0041672c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00416732  84c0                 test al, al
// 00416734  7407                 je 0x41673d
// 00416736  8b06                 mov eax, dword ptr [esi]
// 00416738  83c004               add eax, 4
// 0041673b  7529                 jne 0x416766
// 0041673d  6850d38a00           push 0x8ad350
// 00416742  8d4c2408             lea ecx, [esp + 8]
// 00416746  ff1570e98900         call dword ptr [0x89e970]
// 0041674c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00416754  8d442404             lea eax, [esp + 4]
// 00416758  50                   push eax
// 00416759  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00416761  e85a3bffff           call 0x40a2c0
// 00416766  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041676a  5e                   pop esi
// 0041676b  64890d00000000       mov dword ptr fs:[0], ecx
// 00416772  83c418               add esp, 0x18
// 00416775  c3                   ret 
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
