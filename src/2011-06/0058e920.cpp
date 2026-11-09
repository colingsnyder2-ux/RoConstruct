// from server: 100% by Yeetserama
// roc 2011-06 0058e920  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058e920
//
// 0058e920  64a100000000         mov eax, dword ptr fs:[0]
// 0058e926  6aff                 push -1
// 0058e928  68381e9d00           push 0x9d1e38
// 0058e92d  50                   push eax
// 0058e92e  64892500000000       mov dword ptr fs:[0], esp
// 0058e935  83ec0c               sub esp, 0xc
// 0058e938  56                   push esi
// 0058e939  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058e93d  85f6                 test esi, esi
// 0058e93f  742c                 je 0x58e96d
// 0058e941  8b0e                 mov ecx, dword ptr [esi]
// 0058e943  85c9                 test ecx, ecx
// 0058e945  7409                 je 0x58e950
// 0058e947  8b01                 mov eax, dword ptr [ecx]
// 0058e949  8b5004               mov edx, dword ptr [eax + 4]
// 0058e94c  ffd2                 call edx
// 0058e94e  eb05                 jmp 0x58e955
// 0058e950  b8447ac000           mov eax, 0xc07a44
// 0058e955  68b04ac300           push 0xc34ab0
// 0058e95a  8bc8                 mov ecx, eax
// 0058e95c  ff15500aa400         call dword ptr [0xa40a50]
// 0058e962  84c0                 test al, al
// 0058e964  7407                 je 0x58e96d
// 0058e966  8b06                 mov eax, dword ptr [esi]
// 0058e968  83c004               add eax, 4
// 0058e96b  7529                 jne 0x58e996
// 0058e96d  680cc1a500           push 0xa5c10c
// 0058e972  8d4c2408             lea ecx, [esp + 8]
// 0058e976  ff15100aa400         call dword ptr [0xa40a10]
// 0058e97c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0058e984  8d442404             lea eax, [esp + 4]
// 0058e988  50                   push eax
// 0058e989  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0058e991  e83af0e7ff           call 0x40d9d0
// 0058e996  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058e99a  5e                   pop esi
// 0058e99b  64890d00000000       mov dword ptr fs:[0], ecx
// 0058e9a2  83c418               add esp, 0x18
// 0058e9a5  c3                   ret 
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
