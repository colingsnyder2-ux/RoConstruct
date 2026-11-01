// from server: 100% by Yeetserama
// roc 2011-06 0063ade0  unit: RBX::VProtectedString::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0063ade0
//
// 0063ade0  64a100000000         mov eax, dword ptr fs:[0]
// 0063ade6  6aff                 push -1
// 0063ade8  68381e9d00           push 0x9d1e38
// 0063aded  50                   push eax
// 0063adee  64892500000000       mov dword ptr fs:[0], esp
// 0063adf5  83ec0c               sub esp, 0xc
// 0063adf8  56                   push esi
// 0063adf9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0063adfd  85f6                 test esi, esi
// 0063adff  742c                 je 0x63ae2d
// 0063ae01  8b0e                 mov ecx, dword ptr [esi]
// 0063ae03  85c9                 test ecx, ecx
// 0063ae05  7409                 je 0x63ae10
// 0063ae07  8b01                 mov eax, dword ptr [ecx]
// 0063ae09  8b5004               mov edx, dword ptr [eax + 4]
// 0063ae0c  ffd2                 call edx
// 0063ae0e  eb05                 jmp 0x63ae15
// 0063ae10  b8447ac000           mov eax, 0xc07a44
// 0063ae15  6890a7c200           push 0xc2a790
// 0063ae1a  8bc8                 mov ecx, eax
// 0063ae1c  ff15500aa400         call dword ptr [0xa40a50]
// 0063ae22  84c0                 test al, al
// 0063ae24  7407                 je 0x63ae2d
// 0063ae26  8b06                 mov eax, dword ptr [esi]
// 0063ae28  83c004               add eax, 4
// 0063ae2b  7529                 jne 0x63ae56
// 0063ae2d  680cc1a500           push 0xa5c10c
// 0063ae32  8d4c2408             lea ecx, [esp + 8]
// 0063ae36  ff15100aa400         call dword ptr [0xa40a10]
// 0063ae3c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0063ae44  8d442404             lea eax, [esp + 4]
// 0063ae48  50                   push eax
// 0063ae49  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0063ae51  e87a2bddff           call 0x40d9d0
// 0063ae56  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063ae5a  5e                   pop esi
// 0063ae5b  64890d00000000       mov dword ptr fs:[0], ecx
// 0063ae62  83c418               add esp, 0x18
// 0063ae65  c3                   ret 
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
