// from server: 100% by Yeetserama
// roc 2010-06 005a9870  unit: RBX::W4NormalId::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a9870
//
// 005a9870  64a100000000         mov eax, dword ptr fs:[0]
// 005a9876  6aff                 push -1
// 005a9878  68383c9900           push 0x993c38
// 005a987d  50                   push eax
// 005a987e  64892500000000       mov dword ptr fs:[0], esp
// 005a9885  83ec0c               sub esp, 0xc
// 005a9888  56                   push esi
// 005a9889  8b742420             mov esi, dword ptr [esp + 0x20]
// 005a988d  85f6                 test esi, esi
// 005a988f  742c                 je 0x5a98bd
// 005a9891  8b0e                 mov ecx, dword ptr [esi]
// 005a9893  85c9                 test ecx, ecx
// 005a9895  7409                 je 0x5a98a0
// 005a9897  8b01                 mov eax, dword ptr [ecx]
// 005a9899  8b5004               mov edx, dword ptr [eax + 4]
// 005a989c  ffd2                 call edx
// 005a989e  eb05                 jmp 0x5a98a5
// 005a98a0  b80c93b700           mov eax, 0xb7930c
// 005a98a5  68f4feb900           push 0xb9fef4
// 005a98aa  8bc8                 mov ecx, eax
// 005a98ac  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005a98b2  84c0                 test al, al
// 005a98b4  7407                 je 0x5a98bd
// 005a98b6  8b06                 mov eax, dword ptr [esi]
// 005a98b8  83c004               add eax, 4
// 005a98bb  7529                 jne 0x5a98e6
// 005a98bd  68540aa000           push 0xa00a54
// 005a98c2  8d4c2408             lea ecx, [esp + 8]
// 005a98c6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005a98cc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005a98d4  8d442404             lea eax, [esp + 4]
// 005a98d8  50                   push eax
// 005a98d9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005a98e1  e84a0ce6ff           call 0x40a530
// 005a98e6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a98ea  5e                   pop esi
// 005a98eb  64890d00000000       mov dword ptr fs:[0], ecx
// 005a98f2  83c418               add esp, 0x18
// 005a98f5  c3                   ret 
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
