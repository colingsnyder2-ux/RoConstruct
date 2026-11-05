// from server: 100% by EspClaude
// roc 2009-06 00637760  unit: RBX::VScriptContext::?$FactoryProduct  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00637760
//
// 00637760  64a100000000         mov eax, dword ptr fs:[0]
// 00637766  6aff                 push -1
// 00637768  68789d8600           push 0x869d78
// 0063776d  50                   push eax
// 0063776e  64892500000000       mov dword ptr fs:[0], esp
// 00637775  83ec0c               sub esp, 0xc
// 00637778  56                   push esi
// 00637779  8b742420             mov esi, dword ptr [esp + 0x20]
// 0063777d  85f6                 test esi, esi
// 0063777f  742c                 je 0x6377ad
// 00637781  8b0e                 mov ecx, dword ptr [esi]
// 00637783  85c9                 test ecx, ecx
// 00637785  7409                 je 0x637790
// 00637787  8b01                 mov eax, dword ptr [ecx]
// 00637789  8b5004               mov edx, dword ptr [eax + 4]
// 0063778c  ffd2                 call edx
// 0063778e  eb05                 jmp 0x637795
// 00637790  b8d4c29d00           mov eax, 0x9dc2d4
// 00637795  68b0e29f00           push 0x9fe2b0
// 0063779a  8bc8                 mov ecx, eax
// 0063779c  ff15a4e98900         call dword ptr [0x89e9a4]
// 006377a2  84c0                 test al, al
// 006377a4  7407                 je 0x6377ad
// 006377a6  8b06                 mov eax, dword ptr [esi]
// 006377a8  83c004               add eax, 4
// 006377ab  7529                 jne 0x6377d6
// 006377ad  6850d38a00           push 0x8ad350
// 006377b2  8d4c2408             lea ecx, [esp + 8]
// 006377b6  ff1570e98900         call dword ptr [0x89e970]
// 006377bc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006377c4  8d442404             lea eax, [esp + 4]
// 006377c8  50                   push eax
// 006377c9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006377d1  e8ea2addff           call 0x40a2c0
// 006377d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006377da  5e                   pop esi
// 006377db  64890d00000000       mov dword ptr fs:[0], ecx
// 006377e2  83c418               add esp, 0x18
// 006377e5  c3                   ret 
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
