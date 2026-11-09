// from server: 100% by EspClaude
// roc 2009-06 00645670  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00645670
//
// 00645670  64a100000000         mov eax, dword ptr fs:[0]
// 00645676  6aff                 push -1
// 00645678  68789d8600           push 0x869d78
// 0064567d  50                   push eax
// 0064567e  64892500000000       mov dword ptr fs:[0], esp
// 00645685  83ec0c               sub esp, 0xc
// 00645688  56                   push esi
// 00645689  8b742420             mov esi, dword ptr [esp + 0x20]
// 0064568d  85f6                 test esi, esi
// 0064568f  742c                 je 0x6456bd
// 00645691  8b0e                 mov ecx, dword ptr [esi]
// 00645693  85c9                 test ecx, ecx
// 00645695  7409                 je 0x6456a0
// 00645697  8b01                 mov eax, dword ptr [ecx]
// 00645699  8b5004               mov edx, dword ptr [eax + 4]
// 0064569c  ffd2                 call edx
// 0064569e  eb05                 jmp 0x6456a5
// 006456a0  b8d4c29d00           mov eax, 0x9dc2d4
// 006456a5  6880daa000           push 0xa0da80
// 006456aa  8bc8                 mov ecx, eax
// 006456ac  ff15a4e98900         call dword ptr [0x89e9a4]
// 006456b2  84c0                 test al, al
// 006456b4  7407                 je 0x6456bd
// 006456b6  8b06                 mov eax, dword ptr [esi]
// 006456b8  83c004               add eax, 4
// 006456bb  7529                 jne 0x6456e6
// 006456bd  6850d38a00           push 0x8ad350
// 006456c2  8d4c2408             lea ecx, [esp + 8]
// 006456c6  ff1570e98900         call dword ptr [0x89e970]
// 006456cc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006456d4  8d442404             lea eax, [esp + 4]
// 006456d8  50                   push eax
// 006456d9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006456e1  e8da4bdcff           call 0x40a2c0
// 006456e6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006456ea  5e                   pop esi
// 006456eb  64890d00000000       mov dword ptr fs:[0], ecx
// 006456f2  83c418               add esp, 0x18
// 006456f5  c3                   ret 
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
