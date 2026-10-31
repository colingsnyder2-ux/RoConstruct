// from server: 100% by EspClaude
// roc 2009-06 004165d0  unit: CopyVerb  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004165d0
//
// 004165d0  64a100000000         mov eax, dword ptr fs:[0]
// 004165d6  6aff                 push -1
// 004165d8  68789d8600           push 0x869d78
// 004165dd  50                   push eax
// 004165de  64892500000000       mov dword ptr fs:[0], esp
// 004165e5  83ec0c               sub esp, 0xc
// 004165e8  56                   push esi
// 004165e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004165ed  85f6                 test esi, esi
// 004165ef  742c                 je 0x41661d
// 004165f1  8b0e                 mov ecx, dword ptr [esi]
// 004165f3  85c9                 test ecx, ecx
// 004165f5  7409                 je 0x416600
// 004165f7  8b01                 mov eax, dword ptr [ecx]
// 004165f9  8b5004               mov edx, dword ptr [eax + 4]
// 004165fc  ffd2                 call edx
// 004165fe  eb05                 jmp 0x416605
// 00416600  b8d4c29d00           mov eax, 0x9dc2d4
// 00416605  68d0f29d00           push 0x9df2d0
// 0041660a  8bc8                 mov ecx, eax
// 0041660c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00416612  84c0                 test al, al
// 00416614  7407                 je 0x41661d
// 00416616  8b06                 mov eax, dword ptr [esi]
// 00416618  83c004               add eax, 4
// 0041661b  7529                 jne 0x416646
// 0041661d  6850d38a00           push 0x8ad350
// 00416622  8d4c2408             lea ecx, [esp + 8]
// 00416626  ff1570e98900         call dword ptr [0x89e970]
// 0041662c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00416634  8d442404             lea eax, [esp + 4]
// 00416638  50                   push eax
// 00416639  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00416641  e87a3cffff           call 0x40a2c0
// 00416646  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041664a  5e                   pop esi
// 0041664b  64890d00000000       mov dword ptr fs:[0], ecx
// 00416652  83c418               add esp, 0x18
// 00416655  c3                   ret 
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
