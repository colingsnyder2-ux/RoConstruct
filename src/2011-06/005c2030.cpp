// from server: 100% by Yeetserama
// roc 2011-06 005c2030  unit: RBX::Controller::W4Button::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005c2030
//
// 005c2030  64a100000000         mov eax, dword ptr fs:[0]
// 005c2036  6aff                 push -1
// 005c2038  68381e9d00           push 0x9d1e38
// 005c203d  50                   push eax
// 005c203e  64892500000000       mov dword ptr fs:[0], esp
// 005c2045  83ec0c               sub esp, 0xc
// 005c2048  56                   push esi
// 005c2049  8b742420             mov esi, dword ptr [esp + 0x20]
// 005c204d  85f6                 test esi, esi
// 005c204f  742c                 je 0x5c207d
// 005c2051  8b0e                 mov ecx, dword ptr [esi]
// 005c2053  85c9                 test ecx, ecx
// 005c2055  7409                 je 0x5c2060
// 005c2057  8b01                 mov eax, dword ptr [ecx]
// 005c2059  8b5004               mov edx, dword ptr [eax + 4]
// 005c205c  ffd2                 call edx
// 005c205e  eb05                 jmp 0x5c2065
// 005c2060  b8447ac000           mov eax, 0xc07a44
// 005c2065  6804d1c300           push 0xc3d104
// 005c206a  8bc8                 mov ecx, eax
// 005c206c  ff15500aa400         call dword ptr [0xa40a50]
// 005c2072  84c0                 test al, al
// 005c2074  7407                 je 0x5c207d
// 005c2076  8b06                 mov eax, dword ptr [esi]
// 005c2078  83c004               add eax, 4
// 005c207b  7529                 jne 0x5c20a6
// 005c207d  680cc1a500           push 0xa5c10c
// 005c2082  8d4c2408             lea ecx, [esp + 8]
// 005c2086  ff15100aa400         call dword ptr [0xa40a10]
// 005c208c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 005c2094  8d442404             lea eax, [esp + 4]
// 005c2098  50                   push eax
// 005c2099  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005c20a1  e82ab9e4ff           call 0x40d9d0
// 005c20a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c20aa  5e                   pop esi
// 005c20ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005c20b2  83c418               add esp, 0x18
// 005c20b5  c3                   ret 
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
