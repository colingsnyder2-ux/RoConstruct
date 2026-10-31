// from server: 100% by EspClaude
// roc 2009-06 00637640  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00637640
//
// 00637640  64a100000000         mov eax, dword ptr fs:[0]
// 00637646  6aff                 push -1
// 00637648  68789d8600           push 0x869d78
// 0063764d  50                   push eax
// 0063764e  64892500000000       mov dword ptr fs:[0], esp
// 00637655  83ec0c               sub esp, 0xc
// 00637658  56                   push esi
// 00637659  8b742420             mov esi, dword ptr [esp + 0x20]
// 0063765d  85f6                 test esi, esi
// 0063765f  742c                 je 0x63768d
// 00637661  8b0e                 mov ecx, dword ptr [esi]
// 00637663  85c9                 test ecx, ecx
// 00637665  7409                 je 0x637670
// 00637667  8b01                 mov eax, dword ptr [ecx]
// 00637669  8b5004               mov edx, dword ptr [eax + 4]
// 0063766c  ffd2                 call edx
// 0063766e  eb05                 jmp 0x637675
// 00637670  b8d4c29d00           mov eax, 0x9dc2d4
// 00637675  68c410a000           push 0xa010c4
// 0063767a  8bc8                 mov ecx, eax
// 0063767c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00637682  84c0                 test al, al
// 00637684  7407                 je 0x63768d
// 00637686  8b06                 mov eax, dword ptr [esi]
// 00637688  83c004               add eax, 4
// 0063768b  7529                 jne 0x6376b6
// 0063768d  6850d38a00           push 0x8ad350
// 00637692  8d4c2408             lea ecx, [esp + 8]
// 00637696  ff1570e98900         call dword ptr [0x89e970]
// 0063769c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006376a4  8d442404             lea eax, [esp + 4]
// 006376a8  50                   push eax
// 006376a9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006376b1  e80a2cddff           call 0x40a2c0
// 006376b6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006376ba  5e                   pop esi
// 006376bb  64890d00000000       mov dword ptr fs:[0], ecx
// 006376c2  83c418               add esp, 0x18
// 006376c5  c3                   ret 
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
