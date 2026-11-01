// from server: 100% by Yeetserama
// roc 2011-06 005c43c0  unit: RBX::Feature::W4InOut::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c43c0
//
// 005c43c0  64a100000000         mov eax, dword ptr fs:[0]
// 005c43c6  6aff                 push -1
// 005c43c8  68381e9d00           push 0x9d1e38
// 005c43cd  50                   push eax
// 005c43ce  64892500000000       mov dword ptr fs:[0], esp
// 005c43d5  83ec0c               sub esp, 0xc
// 005c43d8  56                   push esi
// 005c43d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c43dd  85f6                 test esi, esi
// 005c43df  742c                 je 0x5c440d
// 005c43e1  8b0e                 mov ecx, dword ptr [esi]
// 005c43e3  85c9                 test ecx, ecx
// 005c43e5  7409                 je 0x5c43f0
// 005c43e7  8b01                 mov eax, dword ptr [ecx]
// 005c43e9  8b5004               mov edx, dword ptr [eax + 4]
// 005c43ec  ffd2                 call edx
// 005c43ee  eb05                 jmp 0x5c43f5
// 005c43f0  b8447ac000           mov eax, 0xc07a44
// 005c43f5  684cdac300           push 0xc3da4c
// 005c43fa  8bc8                 mov ecx, eax
// 005c43fc  ff15500aa400         call dword ptr [0xa40a50]
// 005c4402  84c0                 test al, al
// 005c4404  7407                 je 0x5c440d
// 005c4406  8b06                 mov eax, dword ptr [esi]
// 005c4408  83c004               add eax, 4
// 005c440b  7529                 jne 0x5c4436
// 005c440d  680cc1a500           push 0xa5c10c
// 005c4412  8d4c2408             lea ecx, [esp + 8]
// 005c4416  ff15100aa400         call dword ptr [0xa40a10]
// 005c441c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c4424  8d442404             lea eax, [esp + 4]
// 005c4428  50                   push eax
// 005c4429  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c4431  e89a95e4ff           call 0x40d9d0
// 005c4436  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c443a  5e                   pop esi
// 005c443b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c4442  83c418               add esp, 0x18
// 005c4445  c3                   ret 
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
