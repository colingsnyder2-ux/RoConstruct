// from server: 100% by Yeetserama
// roc 2011-06 005c4670  unit: RBX::Feature::W4LeftRight::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c4670
//
// 005c4670  64a100000000         mov eax, dword ptr fs:[0]
// 005c4676  6aff                 push -1
// 005c4678  68381e9d00           push 0x9d1e38
// 005c467d  50                   push eax
// 005c467e  64892500000000       mov dword ptr fs:[0], esp
// 005c4685  83ec0c               sub esp, 0xc
// 005c4688  56                   push esi
// 005c4689  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c468d  85f6                 test esi, esi
// 005c468f  742c                 je 0x5c46bd
// 005c4691  8b0e                 mov ecx, dword ptr [esi]
// 005c4693  85c9                 test ecx, ecx
// 005c4695  7409                 je 0x5c46a0
// 005c4697  8b01                 mov eax, dword ptr [ecx]
// 005c4699  8b5004               mov edx, dword ptr [eax + 4]
// 005c469c  ffd2                 call edx
// 005c469e  eb05                 jmp 0x5c46a5
// 005c46a0  b8447ac000           mov eax, 0xc07a44
// 005c46a5  68ecdac300           push 0xc3daec
// 005c46aa  8bc8                 mov ecx, eax
// 005c46ac  ff15500aa400         call dword ptr [0xa40a50]
// 005c46b2  84c0                 test al, al
// 005c46b4  7407                 je 0x5c46bd
// 005c46b6  8b06                 mov eax, dword ptr [esi]
// 005c46b8  83c004               add eax, 4
// 005c46bb  7529                 jne 0x5c46e6
// 005c46bd  680cc1a500           push 0xa5c10c
// 005c46c2  8d4c2408             lea ecx, [esp + 8]
// 005c46c6  ff15100aa400         call dword ptr [0xa40a10]
// 005c46cc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c46d4  8d442404             lea eax, [esp + 4]
// 005c46d8  50                   push eax
// 005c46d9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c46e1  e8ea92e4ff           call 0x40d9d0
// 005c46e6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c46ea  5e                   pop esi
// 005c46eb  64890d00000000       mov dword ptr fs:[0], ecx
// 005c46f2  83c418               add esp, 0x18
// 005c46f5  c3                   ret 
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
