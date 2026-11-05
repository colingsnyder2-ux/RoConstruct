// from server: 100% by EspClaude
// roc 2009-06 006639c0  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006639c0
//
// 006639c0  64a100000000         mov eax, dword ptr fs:[0]
// 006639c6  6aff                 push -1
// 006639c8  68789d8600           push 0x869d78
// 006639cd  50                   push eax
// 006639ce  64892500000000       mov dword ptr fs:[0], esp
// 006639d5  83ec0c               sub esp, 0xc
// 006639d8  56                   push esi
// 006639d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 006639dd  85f6                 test esi, esi
// 006639df  742c                 je 0x663a0d
// 006639e1  8b0e                 mov ecx, dword ptr [esi]
// 006639e3  85c9                 test ecx, ecx
// 006639e5  7409                 je 0x6639f0
// 006639e7  8b01                 mov eax, dword ptr [ecx]
// 006639e9  8b5004               mov edx, dword ptr [eax + 4]
// 006639ec  ffd2                 call edx
// 006639ee  eb05                 jmp 0x6639f5
// 006639f0  b8d4c29d00           mov eax, 0x9dc2d4
// 006639f5  68243ca100           push 0xa13c24
// 006639fa  8bc8                 mov ecx, eax
// 006639fc  ff15a4e98900         call dword ptr [0x89e9a4]
// 00663a02  84c0                 test al, al
// 00663a04  7407                 je 0x663a0d
// 00663a06  8b06                 mov eax, dword ptr [esi]
// 00663a08  83c004               add eax, 4
// 00663a0b  7529                 jne 0x663a36
// 00663a0d  6850d38a00           push 0x8ad350
// 00663a12  8d4c2408             lea ecx, [esp + 8]
// 00663a16  ff1570e98900         call dword ptr [0x89e970]
// 00663a1c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00663a24  8d442404             lea eax, [esp + 4]
// 00663a28  50                   push eax
// 00663a29  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00663a31  e88a68daff           call 0x40a2c0
// 00663a36  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00663a3a  5e                   pop esi
// 00663a3b  64890d00000000       mov dword ptr fs:[0], ecx
// 00663a42  83c418               add esp, 0x18
// 00663a45  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000002@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000002 {
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
