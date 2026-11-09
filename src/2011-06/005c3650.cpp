// from server: 100% by Yeetserama
// roc 2011-06 005c3650  unit: RBX::TextService::W4FontSize::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c3650
//
// 005c3650  64a100000000         mov eax, dword ptr fs:[0]
// 005c3656  6aff                 push -1
// 005c3658  68381e9d00           push 0x9d1e38
// 005c365d  50                   push eax
// 005c365e  64892500000000       mov dword ptr fs:[0], esp
// 005c3665  83ec0c               sub esp, 0xc
// 005c3668  56                   push esi
// 005c3669  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c366d  85f6                 test esi, esi
// 005c366f  742c                 je 0x5c369d
// 005c3671  8b0e                 mov ecx, dword ptr [esi]
// 005c3673  85c9                 test ecx, ecx
// 005c3675  7409                 je 0x5c3680
// 005c3677  8b01                 mov eax, dword ptr [ecx]
// 005c3679  8b5004               mov edx, dword ptr [eax + 4]
// 005c367c  ffd2                 call edx
// 005c367e  eb05                 jmp 0x5c3685
// 005c3680  b8447ac000           mov eax, 0xc07a44
// 005c3685  68d8d6c300           push 0xc3d6d8
// 005c368a  8bc8                 mov ecx, eax
// 005c368c  ff15500aa400         call dword ptr [0xa40a50]
// 005c3692  84c0                 test al, al
// 005c3694  7407                 je 0x5c369d
// 005c3696  8b06                 mov eax, dword ptr [esi]
// 005c3698  83c004               add eax, 4
// 005c369b  7529                 jne 0x5c36c6
// 005c369d  680cc1a500           push 0xa5c10c
// 005c36a2  8d4c2408             lea ecx, [esp + 8]
// 005c36a6  ff15100aa400         call dword ptr [0xa40a10]
// 005c36ac  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c36b4  8d442404             lea eax, [esp + 4]
// 005c36b8  50                   push eax
// 005c36b9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c36c1  e80aa3e4ff           call 0x40d9d0
// 005c36c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c36ca  5e                   pop esi
// 005c36cb  64890d00000000       mov dword ptr fs:[0], ecx
// 005c36d2  83c418               add esp, 0x18
// 005c36d5  c3                   ret 
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
