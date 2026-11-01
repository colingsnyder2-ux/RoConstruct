// from server: 100% by Yeetserama
// roc 2010-06 00448960  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00448960
//
// 00448960  64a100000000         mov eax, dword ptr fs:[0]
// 00448966  6aff                 push -1
// 00448968  68383c9900           push 0x993c38
// 0044896d  50                   push eax
// 0044896e  64892500000000       mov dword ptr fs:[0], esp
// 00448975  83ec0c               sub esp, 0xc
// 00448978  56                   push esi
// 00448979  8b742420             mov esi, dword ptr [esp + 0x20]
// 0044897d  85f6                 test esi, esi
// 0044897f  742c                 je 0x4489ad
// 00448981  8b0e                 mov ecx, dword ptr [esi]
// 00448983  85c9                 test ecx, ecx
// 00448985  7409                 je 0x448990
// 00448987  8b01                 mov eax, dword ptr [ecx]
// 00448989  8b5004               mov edx, dword ptr [eax + 4]
// 0044898c  ffd2                 call edx
// 0044898e  eb05                 jmp 0x448995
// 00448990  b80c93b700           mov eax, 0xb7930c
// 00448995  687813b800           push 0xb81378
// 0044899a  8bc8                 mov ecx, eax
// 0044899c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004489a2  84c0                 test al, al
// 004489a4  7407                 je 0x4489ad
// 004489a6  8b06                 mov eax, dword ptr [esi]
// 004489a8  83c004               add eax, 4
// 004489ab  7529                 jne 0x4489d6
// 004489ad  68540aa000           push 0xa00a54
// 004489b2  8d4c2408             lea ecx, [esp + 8]
// 004489b6  ff159ca89e00         call dword ptr [0x9ea89c]
// 004489bc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004489c4  8d442404             lea eax, [esp + 4]
// 004489c8  50                   push eax
// 004489c9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004489d1  e85a1bfcff           call 0x40a530
// 004489d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004489da  5e                   pop esi
// 004489db  64890d00000000       mov dword ptr fs:[0], ecx
// 004489e2  83c418               add esp, 0x18
// 004489e5  c3                   ret 
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
