// from server: 100% by Yeetserama
// roc 2011-06 005be6b0  unit: RBX::W4NormalId::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005be6b0
//
// 005be6b0  64a100000000         mov eax, dword ptr fs:[0]
// 005be6b6  6aff                 push -1
// 005be6b8  68381e9d00           push 0x9d1e38
// 005be6bd  50                   push eax
// 005be6be  64892500000000       mov dword ptr fs:[0], esp
// 005be6c5  83ec0c               sub esp, 0xc
// 005be6c8  56                   push esi
// 005be6c9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005be6cd  85f6                 test esi, esi
// 005be6cf  742c                 je 0x5be6fd
// 005be6d1  8b0e                 mov ecx, dword ptr [esi]
// 005be6d3  85c9                 test ecx, ecx
// 005be6d5  7409                 je 0x5be6e0
// 005be6d7  8b01                 mov eax, dword ptr [ecx]
// 005be6d9  8b5004               mov edx, dword ptr [eax + 4]
// 005be6dc  ffd2                 call edx
// 005be6de  eb05                 jmp 0x5be6e5
// 005be6e0  b8447ac000           mov eax, 0xc07a44
// 005be6e5  68c0c6c300           push 0xc3c6c0
// 005be6ea  8bc8                 mov ecx, eax
// 005be6ec  ff15500aa400         call dword ptr [0xa40a50]
// 005be6f2  84c0                 test al, al
// 005be6f4  7407                 je 0x5be6fd
// 005be6f6  8b06                 mov eax, dword ptr [esi]
// 005be6f8  83c004               add eax, 4
// 005be6fb  7529                 jne 0x5be726
// 005be6fd  680cc1a500           push 0xa5c10c
// 005be702  8d4c2408             lea ecx, [esp + 8]
// 005be706  ff15100aa400         call dword ptr [0xa40a10]
// 005be70c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005be714  8d442404             lea eax, [esp + 4]
// 005be718  50                   push eax
// 005be719  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005be721  e8aaf2e4ff           call 0x40d9d0
// 005be726  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005be72a  5e                   pop esi
// 005be72b  64890d00000000       mov dword ptr fs:[0], ecx
// 005be732  83c418               add esp, 0x18
// 005be735  c3                   ret 
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
