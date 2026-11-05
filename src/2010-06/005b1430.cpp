// from server: 100% by Yeetserama
// roc 2010-06 005b1430  unit: RBX::Handles::W4VisualStyle::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005b1430
//
// 005b1430  64a100000000         mov eax, dword ptr fs:[0]
// 005b1436  6aff                 push -1
// 005b1438  68383c9900           push 0x993c38
// 005b143d  50                   push eax
// 005b143e  64892500000000       mov dword ptr fs:[0], esp
// 005b1445  83ec0c               sub esp, 0xc
// 005b1448  56                   push esi
// 005b1449  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b144d  85f6                 test esi, esi
// 005b144f  742c                 je 0x5b147d
// 005b1451  8b0e                 mov ecx, dword ptr [esi]
// 005b1453  85c9                 test ecx, ecx
// 005b1455  7409                 je 0x5b1460
// 005b1457  8b01                 mov eax, dword ptr [ecx]
// 005b1459  8b5004               mov edx, dword ptr [eax + 4]
// 005b145c  ffd2                 call edx
// 005b145e  eb05                 jmp 0x5b1465
// 005b1460  b80c93b700           mov eax, 0xb7930c
// 005b1465  68a417ba00           push 0xba17a4
// 005b146a  8bc8                 mov ecx, eax
// 005b146c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005b1472  84c0                 test al, al
// 005b1474  7407                 je 0x5b147d
// 005b1476  8b06                 mov eax, dword ptr [esi]
// 005b1478  83c004               add eax, 4
// 005b147b  7529                 jne 0x5b14a6
// 005b147d  68540aa000           push 0xa00a54
// 005b1482  8d4c2408             lea ecx, [esp + 8]
// 005b1486  ff159ca89e00         call dword ptr [0x9ea89c]
// 005b148c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005b1494  8d442404             lea eax, [esp + 4]
// 005b1498  50                   push eax
// 005b1499  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005b14a1  e88a90e5ff           call 0x40a530
// 005b14a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b14aa  5e                   pop esi
// 005b14ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005b14b2  83c418               add esp, 0x18
// 005b14b5  c3                   ret 
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
