// from server: 100% by Yeetserama
// roc 2011-06 005907d0  unit: RBX::EThrottle::W4EThrottleType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005907d0
//
// 005907d0  64a100000000         mov eax, dword ptr fs:[0]
// 005907d6  6aff                 push -1
// 005907d8  68381e9d00           push 0x9d1e38
// 005907dd  50                   push eax
// 005907de  64892500000000       mov dword ptr fs:[0], esp
// 005907e5  83ec0c               sub esp, 0xc
// 005907e8  56                   push esi
// 005907e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005907ed  85f6                 test esi, esi
// 005907ef  742c                 je 0x59081d
// 005907f1  8b0e                 mov ecx, dword ptr [esi]
// 005907f3  85c9                 test ecx, ecx
// 005907f5  7409                 je 0x590800
// 005907f7  8b01                 mov eax, dword ptr [ecx]
// 005907f9  8b5004               mov edx, dword ptr [eax + 4]
// 005907fc  ffd2                 call edx
// 005907fe  eb05                 jmp 0x590805
// 00590800  b8447ac000           mov eax, 0xc07a44
// 00590805  684053c300           push 0xc35340
// 0059080a  8bc8                 mov ecx, eax
// 0059080c  ff15500aa400         call dword ptr [0xa40a50]
// 00590812  84c0                 test al, al
// 00590814  7407                 je 0x59081d
// 00590816  8b06                 mov eax, dword ptr [esi]
// 00590818  83c004               add eax, 4
// 0059081b  7529                 jne 0x590846
// 0059081d  680cc1a500           push 0xa5c10c
// 00590822  8d4c2408             lea ecx, [esp + 8]
// 00590826  ff15100aa400         call dword ptr [0xa40a10]
// 0059082c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 00590834  8d442404             lea eax, [esp + 4]
// 00590838  50                   push eax
// 00590839  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00590841  e88ad1e7ff           call 0x40d9d0
// 00590846  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0059084a  5e                   pop esi
// 0059084b  64890d00000000       mov dword ptr fs:[0], ecx
// 00590852  83c418               add esp, 0x18
// 00590855  c3                   ret 
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
