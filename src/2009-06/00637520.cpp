// from server: 100% by EspClaude
// roc 2009-06 00637520  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00637520
//
// 00637520  64a100000000         mov eax, dword ptr fs:[0]
// 00637526  6aff                 push -1
// 00637528  68789d8600           push 0x869d78
// 0063752d  50                   push eax
// 0063752e  64892500000000       mov dword ptr fs:[0], esp
// 00637535  83ec0c               sub esp, 0xc
// 00637538  56                   push esi
// 00637539  8b742420             mov esi, dword ptr [esp + 0x20]
// 0063753d  85f6                 test esi, esi
// 0063753f  742c                 je 0x63756d
// 00637541  8b0e                 mov ecx, dword ptr [esi]
// 00637543  85c9                 test ecx, ecx
// 00637545  7409                 je 0x637550
// 00637547  8b01                 mov eax, dword ptr [ecx]
// 00637549  8b5004               mov edx, dword ptr [eax + 4]
// 0063754c  ffd2                 call edx
// 0063754e  eb05                 jmp 0x637555
// 00637550  b8d4c29d00           mov eax, 0x9dc2d4
// 00637555  6810caa000           push 0xa0ca10
// 0063755a  8bc8                 mov ecx, eax
// 0063755c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00637562  84c0                 test al, al
// 00637564  7407                 je 0x63756d
// 00637566  8b06                 mov eax, dword ptr [esi]
// 00637568  83c004               add eax, 4
// 0063756b  7529                 jne 0x637596
// 0063756d  6850d38a00           push 0x8ad350
// 00637572  8d4c2408             lea ecx, [esp + 8]
// 00637576  ff1570e98900         call dword ptr [0x89e970]
// 0063757c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00637584  8d442404             lea eax, [esp + 4]
// 00637588  50                   push eax
// 00637589  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00637591  e82a2dddff           call 0x40a2c0
// 00637596  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063759a  5e                   pop esi
// 0063759b  64890d00000000       mov dword ptr fs:[0], ecx
// 006375a2  83c418               add esp, 0x18
// 006375a5  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000002@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000002 {
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
