// from server: 100% by Yeetserama
// roc 2011-06 0058ee20  unit: RBX::DataModelArbiter::W4ConcurrencyModel::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058ee20
//
// 0058ee20  64a100000000         mov eax, dword ptr fs:[0]
// 0058ee26  6aff                 push -1
// 0058ee28  68381e9d00           push 0x9d1e38
// 0058ee2d  50                   push eax
// 0058ee2e  64892500000000       mov dword ptr fs:[0], esp
// 0058ee35  83ec0c               sub esp, 0xc
// 0058ee38  56                   push esi
// 0058ee39  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058ee3d  85f6                 test esi, esi
// 0058ee3f  742c                 je 0x58ee6d
// 0058ee41  8b0e                 mov ecx, dword ptr [esi]
// 0058ee43  85c9                 test ecx, ecx
// 0058ee45  7409                 je 0x58ee50
// 0058ee47  8b01                 mov eax, dword ptr [ecx]
// 0058ee49  8b5004               mov edx, dword ptr [eax + 4]
// 0058ee4c  ffd2                 call edx
// 0058ee4e  eb05                 jmp 0x58ee55
// 0058ee50  b8447ac000           mov eax, 0xc07a44
// 0058ee55  68244cc300           push 0xc34c24
// 0058ee5a  8bc8                 mov ecx, eax
// 0058ee5c  ff15500aa400         call dword ptr [0xa40a50]
// 0058ee62  84c0                 test al, al
// 0058ee64  7407                 je 0x58ee6d
// 0058ee66  8b06                 mov eax, dword ptr [esi]
// 0058ee68  83c004               add eax, 4
// 0058ee6b  7529                 jne 0x58ee96
// 0058ee6d  680cc1a500           push 0xa5c10c
// 0058ee72  8d4c2408             lea ecx, [esp + 8]
// 0058ee76  ff15100aa400         call dword ptr [0xa40a10]
// 0058ee7c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0058ee84  8d442404             lea eax, [esp + 4]
// 0058ee88  50                   push eax
// 0058ee89  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0058ee91  e83aebe7ff           call 0x40d9d0
// 0058ee96  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058ee9a  5e                   pop esi
// 0058ee9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0058eea2  83c418               add esp, 0x18
// 0058eea5  c3                   ret 
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
