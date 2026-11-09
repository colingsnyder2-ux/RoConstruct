// from server: 100% by Yeetserama
// roc 2011-06 0058e890  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058e890
//
// 0058e890  64a100000000         mov eax, dword ptr fs:[0]
// 0058e896  6aff                 push -1
// 0058e898  68381e9d00           push 0x9d1e38
// 0058e89d  50                   push eax
// 0058e89e  64892500000000       mov dword ptr fs:[0], esp
// 0058e8a5  83ec0c               sub esp, 0xc
// 0058e8a8  56                   push esi
// 0058e8a9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058e8ad  85f6                 test esi, esi
// 0058e8af  742c                 je 0x58e8dd
// 0058e8b1  8b0e                 mov ecx, dword ptr [esi]
// 0058e8b3  85c9                 test ecx, ecx
// 0058e8b5  7409                 je 0x58e8c0
// 0058e8b7  8b01                 mov eax, dword ptr [ecx]
// 0058e8b9  8b5004               mov edx, dword ptr [eax + 4]
// 0058e8bc  ffd2                 call edx
// 0058e8be  eb05                 jmp 0x58e8c5
// 0058e8c0  b8447ac000           mov eax, 0xc07a44
// 0058e8c5  68d449c300           push 0xc349d4
// 0058e8ca  8bc8                 mov ecx, eax
// 0058e8cc  ff15500aa400         call dword ptr [0xa40a50]
// 0058e8d2  84c0                 test al, al
// 0058e8d4  7407                 je 0x58e8dd
// 0058e8d6  8b06                 mov eax, dword ptr [esi]
// 0058e8d8  83c004               add eax, 4
// 0058e8db  7529                 jne 0x58e906
// 0058e8dd  680cc1a500           push 0xa5c10c
// 0058e8e2  8d4c2408             lea ecx, [esp + 8]
// 0058e8e6  ff15100aa400         call dword ptr [0xa40a10]
// 0058e8ec  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0058e8f4  8d442404             lea eax, [esp + 4]
// 0058e8f8  50                   push eax
// 0058e8f9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0058e901  e8caf0e7ff           call 0x40d9d0
// 0058e906  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058e90a  5e                   pop esi
// 0058e90b  64890d00000000       mov dword ptr fs:[0], ecx
// 0058e912  83c418               add esp, 0x18
// 0058e915  c3                   ret 
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
