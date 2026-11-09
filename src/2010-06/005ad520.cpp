// from server: 100% by Yeetserama
// roc 2010-06 005ad520  unit: RBX::Controller::W4Button::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ad520
//
// 005ad520  64a100000000         mov eax, dword ptr fs:[0]
// 005ad526  6aff                 push -1
// 005ad528  68383c9900           push 0x993c38
// 005ad52d  50                   push eax
// 005ad52e  64892500000000       mov dword ptr fs:[0], esp
// 005ad535  83ec0c               sub esp, 0xc
// 005ad538  56                   push esi
// 005ad539  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ad53d  85f6                 test esi, esi
// 005ad53f  742c                 je 0x5ad56d
// 005ad541  8b0e                 mov ecx, dword ptr [esi]
// 005ad543  85c9                 test ecx, ecx
// 005ad545  7409                 je 0x5ad550
// 005ad547  8b01                 mov eax, dword ptr [ecx]
// 005ad549  8b5004               mov edx, dword ptr [eax + 4]
// 005ad54c  ffd2                 call edx
// 005ad54e  eb05                 jmp 0x5ad555
// 005ad550  b80c93b700           mov eax, 0xb7930c
// 005ad555  68c408ba00           push 0xba08c4
// 005ad55a  8bc8                 mov ecx, eax
// 005ad55c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005ad562  84c0                 test al, al
// 005ad564  7407                 je 0x5ad56d
// 005ad566  8b06                 mov eax, dword ptr [esi]
// 005ad568  83c004               add eax, 4
// 005ad56b  7529                 jne 0x5ad596
// 005ad56d  68540aa000           push 0xa00a54
// 005ad572  8d4c2408             lea ecx, [esp + 8]
// 005ad576  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ad57c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005ad584  8d442404             lea eax, [esp + 4]
// 005ad588  50                   push eax
// 005ad589  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005ad591  e89acfe5ff           call 0x40a530
// 005ad596  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ad59a  5e                   pop esi
// 005ad59b  64890d00000000       mov dword ptr fs:[0], ecx
// 005ad5a2  83c418               add esp, 0x18
// 005ad5a5  c3                   ret 
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
