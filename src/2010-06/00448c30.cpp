// from server: 100% by Yeetserama
// roc 2010-06 00448c30  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00448c30
//
// 00448c30  64a100000000         mov eax, dword ptr fs:[0]
// 00448c36  6aff                 push -1
// 00448c38  68383c9900           push 0x993c38
// 00448c3d  50                   push eax
// 00448c3e  64892500000000       mov dword ptr fs:[0], esp
// 00448c45  83ec0c               sub esp, 0xc
// 00448c48  56                   push esi
// 00448c49  8b742420             mov esi, dword ptr [esp + 0x20]
// 00448c4d  85f6                 test esi, esi
// 00448c4f  742c                 je 0x448c7d
// 00448c51  8b0e                 mov ecx, dword ptr [esi]
// 00448c53  85c9                 test ecx, ecx
// 00448c55  7409                 je 0x448c60
// 00448c57  8b01                 mov eax, dword ptr [ecx]
// 00448c59  8b5004               mov edx, dword ptr [eax + 4]
// 00448c5c  ffd2                 call edx
// 00448c5e  eb05                 jmp 0x448c65
// 00448c60  b80c93b700           mov eax, 0xb7930c
// 00448c65  689417b800           push 0xb81794
// 00448c6a  8bc8                 mov ecx, eax
// 00448c6c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00448c72  84c0                 test al, al
// 00448c74  7407                 je 0x448c7d
// 00448c76  8b06                 mov eax, dword ptr [esi]
// 00448c78  83c004               add eax, 4
// 00448c7b  7529                 jne 0x448ca6
// 00448c7d  68540aa000           push 0xa00a54
// 00448c82  8d4c2408             lea ecx, [esp + 8]
// 00448c86  ff159ca89e00         call dword ptr [0x9ea89c]
// 00448c8c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00448c94  8d442404             lea eax, [esp + 4]
// 00448c98  50                   push eax
// 00448c99  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00448ca1  e88a18fcff           call 0x40a530
// 00448ca6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00448caa  5e                   pop esi
// 00448cab  64890d00000000       mov dword ptr fs:[0], ecx
// 00448cb2  83c418               add esp, 0x18
// 00448cb5  c3                   ret 
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
