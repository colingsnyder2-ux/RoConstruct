// from server: 100% by EspClaude
// roc 2009-06 006375b0  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006375b0
//
// 006375b0  64a100000000         mov eax, dword ptr fs:[0]
// 006375b6  6aff                 push -1
// 006375b8  68789d8600           push 0x869d78
// 006375bd  50                   push eax
// 006375be  64892500000000       mov dword ptr fs:[0], esp
// 006375c5  83ec0c               sub esp, 0xc
// 006375c8  56                   push esi
// 006375c9  8b742420             mov esi, dword ptr [esp + 0x20]
// 006375cd  85f6                 test esi, esi
// 006375cf  742c                 je 0x6375fd
// 006375d1  8b0e                 mov ecx, dword ptr [esi]
// 006375d3  85c9                 test ecx, ecx
// 006375d5  7409                 je 0x6375e0
// 006375d7  8b01                 mov eax, dword ptr [ecx]
// 006375d9  8b5004               mov edx, dword ptr [eax + 4]
// 006375dc  ffd2                 call edx
// 006375de  eb05                 jmp 0x6375e5
// 006375e0  b8d4c29d00           mov eax, 0x9dc2d4
// 006375e5  68a810a000           push 0xa010a8
// 006375ea  8bc8                 mov ecx, eax
// 006375ec  ff15a4e98900         call dword ptr [0x89e9a4]
// 006375f2  84c0                 test al, al
// 006375f4  7407                 je 0x6375fd
// 006375f6  8b06                 mov eax, dword ptr [esi]
// 006375f8  83c004               add eax, 4
// 006375fb  7529                 jne 0x637626
// 006375fd  6850d38a00           push 0x8ad350
// 00637602  8d4c2408             lea ecx, [esp + 8]
// 00637606  ff1570e98900         call dword ptr [0x89e970]
// 0063760c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00637614  8d442404             lea eax, [esp + 4]
// 00637618  50                   push eax
// 00637619  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00637621  e89a2cddff           call 0x40a2c0
// 00637626  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063762a  5e                   pop esi
// 0063762b  64890d00000000       mov dword ptr fs:[0], ecx
// 00637632  83c418               add esp, 0x18
// 00637635  c3                   ret 
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
