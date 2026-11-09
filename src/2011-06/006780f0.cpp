// from server: 100% by Yeetserama
// roc 2011-06 006780f0  unit: RBX::VAnimationId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006780f0
//
// 006780f0  64a100000000         mov eax, dword ptr fs:[0]
// 006780f6  6aff                 push -1
// 006780f8  68381e9d00           push 0x9d1e38
// 006780fd  50                   push eax
// 006780fe  64892500000000       mov dword ptr fs:[0], esp
// 00678105  83ec0c               sub esp, 0xc
// 00678108  56                   push esi
// 00678109  8b742420             mov esi, dword ptr [esp + 0x20]
// 0067810d  85f6                 test esi, esi
// 0067810f  742c                 je 0x67813d
// 00678111  8b0e                 mov ecx, dword ptr [esi]
// 00678113  85c9                 test ecx, ecx
// 00678115  7409                 je 0x678120
// 00678117  8b01                 mov eax, dword ptr [ecx]
// 00678119  8b5004               mov edx, dword ptr [eax + 4]
// 0067811c  ffd2                 call edx
// 0067811e  eb05                 jmp 0x678125
// 00678120  b8447ac000           mov eax, 0xc07a44
// 00678125  68bca6c500           push 0xc5a6bc
// 0067812a  8bc8                 mov ecx, eax
// 0067812c  ff15500aa400         call dword ptr [0xa40a50]
// 00678132  84c0                 test al, al
// 00678134  7407                 je 0x67813d
// 00678136  8b06                 mov eax, dword ptr [esi]
// 00678138  83c004               add eax, 4
// 0067813b  7529                 jne 0x678166
// 0067813d  680cc1a500           push 0xa5c10c
// 00678142  8d4c2408             lea ecx, [esp + 8]
// 00678146  ff15100aa400         call dword ptr [0xa40a10]
// 0067814c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 00678154  8d442404             lea eax, [esp + 4]
// 00678158  50                   push eax
// 00678159  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00678161  e86a58d9ff           call 0x40d9d0
// 00678166  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067816a  5e                   pop esi
// 0067816b  64890d00000000       mov dword ptr fs:[0], ecx
// 00678172  83c418               add esp, 0x18
// 00678175  c3                   ret 
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
