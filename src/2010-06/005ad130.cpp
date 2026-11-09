// from server: 100% by Yeetserama
// roc 2010-06 005ad130  unit: W4AffectType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ad130
//
// 005ad130  64a100000000         mov eax, dword ptr fs:[0]
// 005ad136  6aff                 push -1
// 005ad138  68383c9900           push 0x993c38
// 005ad13d  50                   push eax
// 005ad13e  64892500000000       mov dword ptr fs:[0], esp
// 005ad145  83ec0c               sub esp, 0xc
// 005ad148  56                   push esi
// 005ad149  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ad14d  85f6                 test esi, esi
// 005ad14f  742c                 je 0x5ad17d
// 005ad151  8b0e                 mov ecx, dword ptr [esi]
// 005ad153  85c9                 test ecx, ecx
// 005ad155  7409                 je 0x5ad160
// 005ad157  8b01                 mov eax, dword ptr [ecx]
// 005ad159  8b5004               mov edx, dword ptr [eax + 4]
// 005ad15c  ffd2                 call edx
// 005ad15e  eb05                 jmp 0x5ad165
// 005ad160  b80c93b700           mov eax, 0xb7930c
// 005ad165  683008ba00           push 0xba0830
// 005ad16a  8bc8                 mov ecx, eax
// 005ad16c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005ad172  84c0                 test al, al
// 005ad174  7407                 je 0x5ad17d
// 005ad176  8b06                 mov eax, dword ptr [esi]
// 005ad178  83c004               add eax, 4
// 005ad17b  7529                 jne 0x5ad1a6
// 005ad17d  68540aa000           push 0xa00a54
// 005ad182  8d4c2408             lea ecx, [esp + 8]
// 005ad186  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ad18c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005ad194  8d442404             lea eax, [esp + 4]
// 005ad198  50                   push eax
// 005ad199  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005ad1a1  e88ad3e5ff           call 0x40a530
// 005ad1a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ad1aa  5e                   pop esi
// 005ad1ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005ad1b2  83c418               add esp, 0x18
// 005ad1b5  c3                   ret 
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
