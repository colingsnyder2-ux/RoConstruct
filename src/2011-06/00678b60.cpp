// from server: 100% by Yeetserama
// roc 2011-06 00678b60  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00678b60
//
// 00678b60  64a100000000         mov eax, dword ptr fs:[0]
// 00678b66  6aff                 push -1
// 00678b68  68381e9d00           push 0x9d1e38
// 00678b6d  50                   push eax
// 00678b6e  64892500000000       mov dword ptr fs:[0], esp
// 00678b75  83ec0c               sub esp, 0xc
// 00678b78  56                   push esi
// 00678b79  8b742420             mov esi, dword ptr [esp + 0x20]
// 00678b7d  85f6                 test esi, esi
// 00678b7f  742c                 je 0x678bad
// 00678b81  8b0e                 mov ecx, dword ptr [esi]
// 00678b83  85c9                 test ecx, ecx
// 00678b85  7409                 je 0x678b90
// 00678b87  8b01                 mov eax, dword ptr [ecx]
// 00678b89  8b5004               mov edx, dword ptr [eax + 4]
// 00678b8c  ffd2                 call edx
// 00678b8e  eb05                 jmp 0x678b95
// 00678b90  b8447ac000           mov eax, 0xc07a44
// 00678b95  6810aac500           push 0xc5aa10
// 00678b9a  8bc8                 mov ecx, eax
// 00678b9c  ff15500aa400         call dword ptr [0xa40a50]
// 00678ba2  84c0                 test al, al
// 00678ba4  7407                 je 0x678bad
// 00678ba6  8b06                 mov eax, dword ptr [esi]
// 00678ba8  83c004               add eax, 4
// 00678bab  7529                 jne 0x678bd6
// 00678bad  680cc1a500           push 0xa5c10c
// 00678bb2  8d4c2408             lea ecx, [esp + 8]
// 00678bb6  ff15100aa400         call dword ptr [0xa40a10]
// 00678bbc  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 00678bc4  8d442404             lea eax, [esp + 4]
// 00678bc8  50                   push eax
// 00678bc9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00678bd1  e8fa4dd9ff           call 0x40d9d0
// 00678bd6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00678bda  5e                   pop esi
// 00678bdb  64890d00000000       mov dword ptr fs:[0], ecx
// 00678be2  83c418               add esp, 0x18
// 00678be5  c3                   ret 
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
