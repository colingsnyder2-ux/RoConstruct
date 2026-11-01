// from server: 100% by Yeetserama
// roc 2011-06 005c22e0  unit: RBX::HopperBin::W4BinType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c22e0
//
// 005c22e0  64a100000000         mov eax, dword ptr fs:[0]
// 005c22e6  6aff                 push -1
// 005c22e8  68381e9d00           push 0x9d1e38
// 005c22ed  50                   push eax
// 005c22ee  64892500000000       mov dword ptr fs:[0], esp
// 005c22f5  83ec0c               sub esp, 0xc
// 005c22f8  56                   push esi
// 005c22f9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c22fd  85f6                 test esi, esi
// 005c22ff  742c                 je 0x5c232d
// 005c2301  8b0e                 mov ecx, dword ptr [esi]
// 005c2303  85c9                 test ecx, ecx
// 005c2305  7409                 je 0x5c2310
// 005c2307  8b01                 mov eax, dword ptr [ecx]
// 005c2309  8b5004               mov edx, dword ptr [eax + 4]
// 005c230c  ffd2                 call edx
// 005c230e  eb05                 jmp 0x5c2315
// 005c2310  b8447ac000           mov eax, 0xc07a44
// 005c2315  68acd1c300           push 0xc3d1ac
// 005c231a  8bc8                 mov ecx, eax
// 005c231c  ff15500aa400         call dword ptr [0xa40a50]
// 005c2322  84c0                 test al, al
// 005c2324  7407                 je 0x5c232d
// 005c2326  8b06                 mov eax, dword ptr [esi]
// 005c2328  83c004               add eax, 4
// 005c232b  7529                 jne 0x5c2356
// 005c232d  680cc1a500           push 0xa5c10c
// 005c2332  8d4c2408             lea ecx, [esp + 8]
// 005c2336  ff15100aa400         call dword ptr [0xa40a10]
// 005c233c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c2344  8d442404             lea eax, [esp + 4]
// 005c2348  50                   push eax
// 005c2349  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c2351  e87ab6e4ff           call 0x40d9d0
// 005c2356  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c235a  5e                   pop esi
// 005c235b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c2362  83c418               add esp, 0x18
// 005c2365  c3                   ret 
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
