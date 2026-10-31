// from server: 100% by EspClaude
// roc 2009-06 00441ad0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00441ad0
//
// 00441ad0  64a100000000         mov eax, dword ptr fs:[0]
// 00441ad6  6aff                 push -1
// 00441ad8  68789d8600           push 0x869d78
// 00441add  50                   push eax
// 00441ade  64892500000000       mov dword ptr fs:[0], esp
// 00441ae5  83ec0c               sub esp, 0xc
// 00441ae8  56                   push esi
// 00441ae9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00441aed  85f6                 test esi, esi
// 00441aef  742c                 je 0x441b1d
// 00441af1  8b0e                 mov ecx, dword ptr [esi]
// 00441af3  85c9                 test ecx, ecx
// 00441af5  7409                 je 0x441b00
// 00441af7  8b01                 mov eax, dword ptr [ecx]
// 00441af9  8b5004               mov edx, dword ptr [eax + 4]
// 00441afc  ffd2                 call edx
// 00441afe  eb05                 jmp 0x441b05
// 00441b00  b8d4c29d00           mov eax, 0x9dc2d4
// 00441b05  680c3b9e00           push 0x9e3b0c
// 00441b0a  8bc8                 mov ecx, eax
// 00441b0c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00441b12  84c0                 test al, al
// 00441b14  7407                 je 0x441b1d
// 00441b16  8b06                 mov eax, dword ptr [esi]
// 00441b18  83c004               add eax, 4
// 00441b1b  7529                 jne 0x441b46
// 00441b1d  6850d38a00           push 0x8ad350
// 00441b22  8d4c2408             lea ecx, [esp + 8]
// 00441b26  ff1570e98900         call dword ptr [0x89e970]
// 00441b2c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00441b34  8d442404             lea eax, [esp + 4]
// 00441b38  50                   push eax
// 00441b39  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00441b41  e87a87fcff           call 0x40a2c0
// 00441b46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00441b4a  5e                   pop esi
// 00441b4b  64890d00000000       mov dword ptr fs:[0], ecx
// 00441b52  83c418               add esp, 0x18
// 00441b55  c3                   ret 
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
