// from server: 100% by Yeetserama
// roc 2011-06 0062de70  unit: RBX::VTextureId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0062de70
//
// 0062de70  64a100000000         mov eax, dword ptr fs:[0]
// 0062de76  6aff                 push -1
// 0062de78  68381e9d00           push 0x9d1e38
// 0062de7d  50                   push eax
// 0062de7e  64892500000000       mov dword ptr fs:[0], esp
// 0062de85  83ec0c               sub esp, 0xc
// 0062de88  56                   push esi
// 0062de89  8b742420             mov esi, dword ptr [esp + 0x20]
// 0062de8d  85f6                 test esi, esi
// 0062de8f  742c                 je 0x62debd
// 0062de91  8b0e                 mov ecx, dword ptr [esi]
// 0062de93  85c9                 test ecx, ecx
// 0062de95  7409                 je 0x62dea0
// 0062de97  8b01                 mov eax, dword ptr [ecx]
// 0062de99  8b5004               mov edx, dword ptr [eax + 4]
// 0062de9c  ffd2                 call edx
// 0062de9e  eb05                 jmp 0x62dea5
// 0062dea0  b8447ac000           mov eax, 0xc07a44
// 0062dea5  68c0dec400           push 0xc4dec0
// 0062deaa  8bc8                 mov ecx, eax
// 0062deac  ff15500aa400         call dword ptr [0xa40a50]
// 0062deb2  84c0                 test al, al
// 0062deb4  7407                 je 0x62debd
// 0062deb6  8b06                 mov eax, dword ptr [esi]
// 0062deb8  83c004               add eax, 4
// 0062debb  7529                 jne 0x62dee6
// 0062debd  680cc1a500           push 0xa5c10c
// 0062dec2  8d4c2408             lea ecx, [esp + 8]
// 0062dec6  ff15100aa400         call dword ptr [0xa40a10]
// 0062decc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 0062ded4  8d442404             lea eax, [esp + 4]
// 0062ded8  50                   push eax
// 0062ded9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0062dee1  e8eafaddff           call 0x40d9d0
// 0062dee6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062deea  5e                   pop esi
// 0062deeb  64890d00000000       mov dword ptr fs:[0], ecx
// 0062def2  83c418               add esp, 0x18
// 0062def5  c3                   ret 
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
