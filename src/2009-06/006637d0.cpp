// from server: 100% by EspClaude
// roc 2009-06 006637d0  unit: RBX::$01::?$SurfaceDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006637d0
//
// 006637d0  64a100000000         mov eax, dword ptr fs:[0]
// 006637d6  6aff                 push -1
// 006637d8  68789d8600           push 0x869d78
// 006637dd  50                   push eax
// 006637de  64892500000000       mov dword ptr fs:[0], esp
// 006637e5  83ec0c               sub esp, 0xc
// 006637e8  56                   push esi
// 006637e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 006637ed  85f6                 test esi, esi
// 006637ef  742c                 je 0x66381d
// 006637f1  8b0e                 mov ecx, dword ptr [esi]
// 006637f3  85c9                 test ecx, ecx
// 006637f5  7409                 je 0x663800
// 006637f7  8b01                 mov eax, dword ptr [ecx]
// 006637f9  8b5004               mov edx, dword ptr [eax + 4]
// 006637fc  ffd2                 call edx
// 006637fe  eb05                 jmp 0x663805
// 00663800  b8d4c29d00           mov eax, 0x9dc2d4
// 00663805  68043ca100           push 0xa13c04
// 0066380a  8bc8                 mov ecx, eax
// 0066380c  ff15a4e98900         call dword ptr [0x89e9a4]
// 00663812  84c0                 test al, al
// 00663814  7407                 je 0x66381d
// 00663816  8b06                 mov eax, dword ptr [esi]
// 00663818  83c004               add eax, 4
// 0066381b  7529                 jne 0x663846
// 0066381d  6850d38a00           push 0x8ad350
// 00663822  8d4c2408             lea ecx, [esp + 8]
// 00663826  ff1570e98900         call dword ptr [0x89e970]
// 0066382c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 00663834  8d442404             lea eax, [esp + 4]
// 00663838  50                   push eax
// 00663839  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00663841  e87a6adaff           call 0x40a2c0
// 00663846  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066384a  5e                   pop esi
// 0066384b  64890d00000000       mov dword ptr fs:[0], ecx
// 00663852  83c418               add esp, 0x18
// 00663855  c3                   ret 
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
