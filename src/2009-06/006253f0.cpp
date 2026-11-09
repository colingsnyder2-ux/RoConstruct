// from server: 100% by EspClaude
// roc 2009-06 006253f0  unit: RBX::VTextureId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006253f0
//
// 006253f0  64a100000000         mov eax, dword ptr fs:[0]
// 006253f6  6aff                 push -1
// 006253f8  68789d8600           push 0x869d78
// 006253fd  50                   push eax
// 006253fe  64892500000000       mov dword ptr fs:[0], esp
// 00625405  83ec0c               sub esp, 0xc
// 00625408  56                   push esi
// 00625409  8b742420             mov esi, dword ptr [esp + 0x20]
// 0062540d  85f6                 test esi, esi
// 0062540f  742c                 je 0x62543d
// 00625411  8b0e                 mov ecx, dword ptr [esi]
// 00625413  85c9                 test ecx, ecx
// 00625415  7409                 je 0x625420
// 00625417  8b01                 mov eax, dword ptr [ecx]
// 00625419  8b5004               mov edx, dword ptr [eax + 4]
// 0062541c  ffd2                 call edx
// 0062541e  eb05                 jmp 0x625425
// 00625420  b8d4c29d00           mov eax, 0x9dc2d4
// 00625425  6898a6a000           push 0xa0a698
// 0062542a  8bc8                 mov ecx, eax
// 0062542c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00625432  84c0                 test al, al
// 00625434  7407                 je 0x62543d
// 00625436  8b06                 mov eax, dword ptr [esi]
// 00625438  83c004               add eax, 4
// 0062543b  7529                 jne 0x625466
// 0062543d  6850d38a00           push 0x8ad350
// 00625442  8d4c2408             lea ecx, [esp + 8]
// 00625446  ff1570e98900         call dword ptr [0x89e970]
// 0062544c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00625454  8d442404             lea eax, [esp + 4]
// 00625458  50                   push eax
// 00625459  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00625461  e85a4edeff           call 0x40a2c0
// 00625466  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062546a  5e                   pop esi
// 0062546b  64890d00000000       mov dword ptr fs:[0], ecx
// 00625472  83c418               add esp, 0x18
// 00625475  c3                   ret 
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
