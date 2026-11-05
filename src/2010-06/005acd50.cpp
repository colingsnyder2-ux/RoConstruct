// from server: 100% by Yeetserama
// roc 2010-06 005acd50  unit: RBX::Action::W4ActionType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005acd50
//
// 005acd50  64a100000000         mov eax, dword ptr fs:[0]
// 005acd56  6aff                 push -1
// 005acd58  68383c9900           push 0x993c38
// 005acd5d  50                   push eax
// 005acd5e  64892500000000       mov dword ptr fs:[0], esp
// 005acd65  83ec0c               sub esp, 0xc
// 005acd68  56                   push esi
// 005acd69  8b742420             mov esi, dword ptr [esp + 0x20]
// 005acd6d  85f6                 test esi, esi
// 005acd6f  742c                 je 0x5acd9d
// 005acd71  8b0e                 mov ecx, dword ptr [esi]
// 005acd73  85c9                 test ecx, ecx
// 005acd75  7409                 je 0x5acd80
// 005acd77  8b01                 mov eax, dword ptr [ecx]
// 005acd79  8b5004               mov edx, dword ptr [eax + 4]
// 005acd7c  ffd2                 call edx
// 005acd7e  eb05                 jmp 0x5acd85
// 005acd80  b80c93b700           mov eax, 0xb7930c
// 005acd85  689407ba00           push 0xba0794
// 005acd8a  8bc8                 mov ecx, eax
// 005acd8c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005acd92  84c0                 test al, al
// 005acd94  7407                 je 0x5acd9d
// 005acd96  8b06                 mov eax, dword ptr [esi]
// 005acd98  83c004               add eax, 4
// 005acd9b  7529                 jne 0x5acdc6
// 005acd9d  68540aa000           push 0xa00a54
// 005acda2  8d4c2408             lea ecx, [esp + 8]
// 005acda6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005acdac  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005acdb4  8d442404             lea eax, [esp + 4]
// 005acdb8  50                   push eax
// 005acdb9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005acdc1  e86ad7e5ff           call 0x40a530
// 005acdc6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005acdca  5e                   pop esi
// 005acdcb  64890d00000000       mov dword ptr fs:[0], ecx
// 005acdd2  83c418               add esp, 0x18
// 005acdd5  c3                   ret 
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
