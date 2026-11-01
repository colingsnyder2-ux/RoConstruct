// from server: 100% by Yeetserama
// roc 2010-06 005af860  unit: RBX::W4KeywordFilterType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005af860
//
// 005af860  64a100000000         mov eax, dword ptr fs:[0]
// 005af866  6aff                 push -1
// 005af868  68383c9900           push 0x993c38
// 005af86d  50                   push eax
// 005af86e  64892500000000       mov dword ptr fs:[0], esp
// 005af875  83ec0c               sub esp, 0xc
// 005af878  56                   push esi
// 005af879  8b742420             mov esi, dword ptr [esp + 0x20]
// 005af87d  85f6                 test esi, esi
// 005af87f  742c                 je 0x5af8ad
// 005af881  8b0e                 mov ecx, dword ptr [esi]
// 005af883  85c9                 test ecx, ecx
// 005af885  7409                 je 0x5af890
// 005af887  8b01                 mov eax, dword ptr [ecx]
// 005af889  8b5004               mov edx, dword ptr [eax + 4]
// 005af88c  ffd2                 call edx
// 005af88e  eb05                 jmp 0x5af895
// 005af890  b80c93b700           mov eax, 0xb7930c
// 005af895  68ec10ba00           push 0xba10ec
// 005af89a  8bc8                 mov ecx, eax
// 005af89c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005af8a2  84c0                 test al, al
// 005af8a4  7407                 je 0x5af8ad
// 005af8a6  8b06                 mov eax, dword ptr [esi]
// 005af8a8  83c004               add eax, 4
// 005af8ab  7529                 jne 0x5af8d6
// 005af8ad  68540aa000           push 0xa00a54
// 005af8b2  8d4c2408             lea ecx, [esp + 8]
// 005af8b6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005af8bc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005af8c4  8d442404             lea eax, [esp + 4]
// 005af8c8  50                   push eax
// 005af8c9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005af8d1  e85aace5ff           call 0x40a530
// 005af8d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005af8da  5e                   pop esi
// 005af8db  64890d00000000       mov dword ptr fs:[0], ecx
// 005af8e2  83c418               add esp, 0x18
// 005af8e5  c3                   ret 
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
