// from server: 100% by Yeetserama
// roc 2010-06 005aef90  unit: RBX::Feature::W4LeftRight::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005aef90
//
// 005aef90  64a100000000         mov eax, dword ptr fs:[0]
// 005aef96  6aff                 push -1
// 005aef98  68383c9900           push 0x993c38
// 005aef9d  50                   push eax
// 005aef9e  64892500000000       mov dword ptr fs:[0], esp
// 005aefa5  83ec0c               sub esp, 0xc
// 005aefa8  56                   push esi
// 005aefa9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005aefad  85f6                 test esi, esi
// 005aefaf  742c                 je 0x5aefdd
// 005aefb1  8b0e                 mov ecx, dword ptr [esi]
// 005aefb3  85c9                 test ecx, ecx
// 005aefb5  7409                 je 0x5aefc0
// 005aefb7  8b01                 mov eax, dword ptr [ecx]
// 005aefb9  8b5004               mov edx, dword ptr [eax + 4]
// 005aefbc  ffd2                 call edx
// 005aefbe  eb05                 jmp 0x5aefc5
// 005aefc0  b80c93b700           mov eax, 0xb7930c
// 005aefc5  68fc0eba00           push 0xba0efc
// 005aefca  8bc8                 mov ecx, eax
// 005aefcc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005aefd2  84c0                 test al, al
// 005aefd4  7407                 je 0x5aefdd
// 005aefd6  8b06                 mov eax, dword ptr [esi]
// 005aefd8  83c004               add eax, 4
// 005aefdb  7529                 jne 0x5af006
// 005aefdd  68540aa000           push 0xa00a54
// 005aefe2  8d4c2408             lea ecx, [esp + 8]
// 005aefe6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005aefec  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005aeff4  8d442404             lea eax, [esp + 4]
// 005aeff8  50                   push eax
// 005aeff9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005af001  e82ab5e5ff           call 0x40a530
// 005af006  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005af00a  5e                   pop esi
// 005af00b  64890d00000000       mov dword ptr fs:[0], ecx
// 005af012  83c418               add esp, 0x18
// 005af015  c3                   ret 
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
