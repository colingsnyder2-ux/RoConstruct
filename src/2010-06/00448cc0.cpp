// from server: 100% by Yeetserama
// roc 2010-06 00448cc0  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00448cc0
//
// 00448cc0  64a100000000         mov eax, dword ptr fs:[0]
// 00448cc6  6aff                 push -1
// 00448cc8  68383c9900           push 0x993c38
// 00448ccd  50                   push eax
// 00448cce  64892500000000       mov dword ptr fs:[0], esp
// 00448cd5  83ec0c               sub esp, 0xc
// 00448cd8  56                   push esi
// 00448cd9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00448cdd  85f6                 test esi, esi
// 00448cdf  742c                 je 0x448d0d
// 00448ce1  8b0e                 mov ecx, dword ptr [esi]
// 00448ce3  85c9                 test ecx, ecx
// 00448ce5  7409                 je 0x448cf0
// 00448ce7  8b01                 mov eax, dword ptr [ecx]
// 00448ce9  8b5004               mov edx, dword ptr [eax + 4]
// 00448cec  ffd2                 call edx
// 00448cee  eb05                 jmp 0x448cf5
// 00448cf0  b80c93b700           mov eax, 0xb7930c
// 00448cf5  686018b800           push 0xb81860
// 00448cfa  8bc8                 mov ecx, eax
// 00448cfc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00448d02  84c0                 test al, al
// 00448d04  7407                 je 0x448d0d
// 00448d06  8b06                 mov eax, dword ptr [esi]
// 00448d08  83c004               add eax, 4
// 00448d0b  7529                 jne 0x448d36
// 00448d0d  68540aa000           push 0xa00a54
// 00448d12  8d4c2408             lea ecx, [esp + 8]
// 00448d16  ff159ca89e00         call dword ptr [0x9ea89c]
// 00448d1c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00448d24  8d442404             lea eax, [esp + 4]
// 00448d28  50                   push eax
// 00448d29  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00448d31  e8fa17fcff           call 0x40a530
// 00448d36  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00448d3a  5e                   pop esi
// 00448d3b  64890d00000000       mov dword ptr fs:[0], ecx
// 00448d42  83c418               add esp, 0x18
// 00448d45  c3                   ret 
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
