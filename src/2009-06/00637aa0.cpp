// from server: 100% by EspClaude
// roc 2009-06 00637aa0  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00637aa0
//
// 00637aa0  64a100000000         mov eax, dword ptr fs:[0]
// 00637aa6  6aff                 push -1
// 00637aa8  68789d8600           push 0x869d78
// 00637aad  50                   push eax
// 00637aae  64892500000000       mov dword ptr fs:[0], esp
// 00637ab5  83ec0c               sub esp, 0xc
// 00637ab8  56                   push esi
// 00637ab9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00637abd  85f6                 test esi, esi
// 00637abf  742c                 je 0x637aed
// 00637ac1  8b0e                 mov ecx, dword ptr [esi]
// 00637ac3  85c9                 test ecx, ecx
// 00637ac5  7409                 je 0x637ad0
// 00637ac7  8b01                 mov eax, dword ptr [ecx]
// 00637ac9  8b5004               mov edx, dword ptr [eax + 4]
// 00637acc  ffd2                 call edx
// 00637ace  eb05                 jmp 0x637ad5
// 00637ad0  b8d4c29d00           mov eax, 0x9dc2d4
// 00637ad5  6868f39d00           push 0x9df368
// 00637ada  8bc8                 mov ecx, eax
// 00637adc  ff15a4e98900         call dword ptr [0x89e9a4]
// 00637ae2  84c0                 test al, al
// 00637ae4  7407                 je 0x637aed
// 00637ae6  8b06                 mov eax, dword ptr [esi]
// 00637ae8  83c004               add eax, 4
// 00637aeb  7529                 jne 0x637b16
// 00637aed  6850d38a00           push 0x8ad350
// 00637af2  8d4c2408             lea ecx, [esp + 8]
// 00637af6  ff1570e98900         call dword ptr [0x89e970]
// 00637afc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00637b04  8d442404             lea eax, [esp + 4]
// 00637b08  50                   push eax
// 00637b09  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00637b11  e8aa27ddff           call 0x40a2c0
// 00637b16  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00637b1a  5e                   pop esi
// 00637b1b  64890d00000000       mov dword ptr fs:[0], ecx
// 00637b22  83c418               add esp, 0x18
// 00637b25  c3                   ret 
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
