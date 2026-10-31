// from server: 100% by EspClaude
// roc 2009-06 00416540  unit: CopyVerb  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00416540
//
// 00416540  64a100000000         mov eax, dword ptr fs:[0]
// 00416546  6aff                 push -1
// 00416548  68789d8600           push 0x869d78
// 0041654d  50                   push eax
// 0041654e  64892500000000       mov dword ptr fs:[0], esp
// 00416555  83ec0c               sub esp, 0xc
// 00416558  56                   push esi
// 00416559  8b742420             mov esi, dword ptr [esp + 0x20]
// 0041655d  85f6                 test esi, esi
// 0041655f  742c                 je 0x41658d
// 00416561  8b0e                 mov ecx, dword ptr [esi]
// 00416563  85c9                 test ecx, ecx
// 00416565  7409                 je 0x416570
// 00416567  8b01                 mov eax, dword ptr [ecx]
// 00416569  8b5004               mov edx, dword ptr [eax + 4]
// 0041656c  ffd2                 call edx
// 0041656e  eb05                 jmp 0x416575
// 00416570  b8d4c29d00           mov eax, 0x9dc2d4
// 00416575  68c4f29d00           push 0x9df2c4
// 0041657a  8bc8                 mov ecx, eax
// 0041657c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00416582  84c0                 test al, al
// 00416584  7407                 je 0x41658d
// 00416586  8b06                 mov eax, dword ptr [esi]
// 00416588  83c004               add eax, 4
// 0041658b  7529                 jne 0x4165b6
// 0041658d  6850d38a00           push 0x8ad350
// 00416592  8d4c2408             lea ecx, [esp + 8]
// 00416596  ff1570e98900         call dword ptr [0x89e970]
// 0041659c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 004165a4  8d442404             lea eax, [esp + 4]
// 004165a8  50                   push eax
// 004165a9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004165b1  e80a3dffff           call 0x40a2c0
// 004165b6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004165ba  5e                   pop esi
// 004165bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004165c2  83c418               add esp, 0x18
// 004165c5  c3                   ret 
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
