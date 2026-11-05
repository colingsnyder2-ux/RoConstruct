// from server: 100% by Yeetserama
// roc 2011-06 0058e9b0  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0058e9b0
//
// 0058e9b0  64a100000000         mov eax, dword ptr fs:[0]
// 0058e9b6  6aff                 push -1
// 0058e9b8  68381e9d00           push 0x9d1e38
// 0058e9bd  50                   push eax
// 0058e9be  64892500000000       mov dword ptr fs:[0], esp
// 0058e9c5  83ec0c               sub esp, 0xc
// 0058e9c8  56                   push esi
// 0058e9c9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058e9cd  85f6                 test esi, esi
// 0058e9cf  742c                 je 0x58e9fd
// 0058e9d1  8b0e                 mov ecx, dword ptr [esi]
// 0058e9d3  85c9                 test ecx, ecx
// 0058e9d5  7409                 je 0x58e9e0
// 0058e9d7  8b01                 mov eax, dword ptr [ecx]
// 0058e9d9  8b5004               mov edx, dword ptr [eax + 4]
// 0058e9dc  ffd2                 call edx
// 0058e9de  eb05                 jmp 0x58e9e5
// 0058e9e0  b8447ac000           mov eax, 0xc07a44
// 0058e9e5  686c4bc300           push 0xc34b6c
// 0058e9ea  8bc8                 mov ecx, eax
// 0058e9ec  ff15500aa400         call dword ptr [0xa40a50]
// 0058e9f2  84c0                 test al, al
// 0058e9f4  7407                 je 0x58e9fd
// 0058e9f6  8b06                 mov eax, dword ptr [esi]
// 0058e9f8  83c004               add eax, 4
// 0058e9fb  7529                 jne 0x58ea26
// 0058e9fd  680cc1a500           push 0xa5c10c
// 0058ea02  8d4c2408             lea ecx, [esp + 8]
// 0058ea06  ff15100aa400         call dword ptr [0xa40a10]
// 0058ea0c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0058ea14  8d442404             lea eax, [esp + 4]
// 0058ea18  50                   push eax
// 0058ea19  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0058ea21  e8aaefe7ff           call 0x40d9d0
// 0058ea26  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058ea2a  5e                   pop esi
// 0058ea2b  64890d00000000       mov dword ptr fs:[0], ecx
// 0058ea32  83c418               add esp, 0x18
// 0058ea35  c3                   ret 
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
