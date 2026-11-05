// from server: 100% by Yeetserama
// roc 2010-06 004d0ad0  unit: W4PacketReliability::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004d0ad0
//
// 004d0ad0  64a100000000         mov eax, dword ptr fs:[0]
// 004d0ad6  6aff                 push -1
// 004d0ad8  68383c9900           push 0x993c38
// 004d0add  50                   push eax
// 004d0ade  64892500000000       mov dword ptr fs:[0], esp
// 004d0ae5  83ec0c               sub esp, 0xc
// 004d0ae8  56                   push esi
// 004d0ae9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004d0aed  85f6                 test esi, esi
// 004d0aef  742c                 je 0x4d0b1d
// 004d0af1  8b0e                 mov ecx, dword ptr [esi]
// 004d0af3  85c9                 test ecx, ecx
// 004d0af5  7409                 je 0x4d0b00
// 004d0af7  8b01                 mov eax, dword ptr [ecx]
// 004d0af9  8b5004               mov edx, dword ptr [eax + 4]
// 004d0afc  ffd2                 call edx
// 004d0afe  eb05                 jmp 0x4d0b05
// 004d0b00  b80c93b700           mov eax, 0xb7930c
// 004d0b05  6894eab800           push 0xb8ea94
// 004d0b0a  8bc8                 mov ecx, eax
// 004d0b0c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004d0b12  84c0                 test al, al
// 004d0b14  7407                 je 0x4d0b1d
// 004d0b16  8b06                 mov eax, dword ptr [esi]
// 004d0b18  83c004               add eax, 4
// 004d0b1b  7529                 jne 0x4d0b46
// 004d0b1d  68540aa000           push 0xa00a54
// 004d0b22  8d4c2408             lea ecx, [esp + 8]
// 004d0b26  ff159ca89e00         call dword ptr [0x9ea89c]
// 004d0b2c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004d0b34  8d442404             lea eax, [esp + 4]
// 004d0b38  50                   push eax
// 004d0b39  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004d0b41  e8ea99f3ff           call 0x40a530
// 004d0b46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004d0b4a  5e                   pop esi
// 004d0b4b  64890d00000000       mov dword ptr fs:[0], ecx
// 004d0b52  83c418               add esp, 0x18
// 004d0b55  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000000@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
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
