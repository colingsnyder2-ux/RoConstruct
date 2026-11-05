// from server: 100% by Yeetserama
// roc 2010-06 00448b10  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00448b10
//
// 00448b10  64a100000000         mov eax, dword ptr fs:[0]
// 00448b16  6aff                 push -1
// 00448b18  68383c9900           push 0x993c38
// 00448b1d  50                   push eax
// 00448b1e  64892500000000       mov dword ptr fs:[0], esp
// 00448b25  83ec0c               sub esp, 0xc
// 00448b28  56                   push esi
// 00448b29  8b742420             mov esi, dword ptr [esp + 0x20]
// 00448b2d  85f6                 test esi, esi
// 00448b2f  742c                 je 0x448b5d
// 00448b31  8b0e                 mov ecx, dword ptr [esi]
// 00448b33  85c9                 test ecx, ecx
// 00448b35  7409                 je 0x448b40
// 00448b37  8b01                 mov eax, dword ptr [ecx]
// 00448b39  8b5004               mov edx, dword ptr [eax + 4]
// 00448b3c  ffd2                 call edx
// 00448b3e  eb05                 jmp 0x448b45
// 00448b40  b80c93b700           mov eax, 0xb7930c
// 00448b45  68f415b800           push 0xb815f4
// 00448b4a  8bc8                 mov ecx, eax
// 00448b4c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00448b52  84c0                 test al, al
// 00448b54  7407                 je 0x448b5d
// 00448b56  8b06                 mov eax, dword ptr [esi]
// 00448b58  83c004               add eax, 4
// 00448b5b  7529                 jne 0x448b86
// 00448b5d  68540aa000           push 0xa00a54
// 00448b62  8d4c2408             lea ecx, [esp + 8]
// 00448b66  ff159ca89e00         call dword ptr [0x9ea89c]
// 00448b6c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00448b74  8d442404             lea eax, [esp + 4]
// 00448b78  50                   push eax
// 00448b79  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00448b81  e8aa19fcff           call 0x40a530
// 00448b86  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00448b8a  5e                   pop esi
// 00448b8b  64890d00000000       mov dword ptr fs:[0], ecx
// 00448b92  83c418               add esp, 0x18
// 00448b95  c3                   ret 
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
