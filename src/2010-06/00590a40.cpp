// from server: 100% by Yeetserama
// roc 2010-06 00590a40  unit: RBX::DataModelArbiter::W4ConcurrencyModel::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00590a40
//
// 00590a40  64a100000000         mov eax, dword ptr fs:[0]
// 00590a46  6aff                 push -1
// 00590a48  68383c9900           push 0x993c38
// 00590a4d  50                   push eax
// 00590a4e  64892500000000       mov dword ptr fs:[0], esp
// 00590a55  83ec0c               sub esp, 0xc
// 00590a58  56                   push esi
// 00590a59  8b742420             mov esi, dword ptr [esp + 0x20]
// 00590a5d  85f6                 test esi, esi
// 00590a5f  742c                 je 0x590a8d
// 00590a61  8b0e                 mov ecx, dword ptr [esi]
// 00590a63  85c9                 test ecx, ecx
// 00590a65  7409                 je 0x590a70
// 00590a67  8b01                 mov eax, dword ptr [ecx]
// 00590a69  8b5004               mov edx, dword ptr [eax + 4]
// 00590a6c  ffd2                 call edx
// 00590a6e  eb05                 jmp 0x590a75
// 00590a70  b80c93b700           mov eax, 0xb7930c
// 00590a75  6884ccb900           push 0xb9cc84
// 00590a7a  8bc8                 mov ecx, eax
// 00590a7c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00590a82  84c0                 test al, al
// 00590a84  7407                 je 0x590a8d
// 00590a86  8b06                 mov eax, dword ptr [esi]
// 00590a88  83c004               add eax, 4
// 00590a8b  7529                 jne 0x590ab6
// 00590a8d  68540aa000           push 0xa00a54
// 00590a92  8d4c2408             lea ecx, [esp + 8]
// 00590a96  ff159ca89e00         call dword ptr [0x9ea89c]
// 00590a9c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00590aa4  8d442404             lea eax, [esp + 4]
// 00590aa8  50                   push eax
// 00590aa9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00590ab1  e87a9ae7ff           call 0x40a530
// 00590ab6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00590aba  5e                   pop esi
// 00590abb  64890d00000000       mov dword ptr fs:[0], ecx
// 00590ac2  83c418               add esp, 0x18
// 00590ac5  c3                   ret 
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
