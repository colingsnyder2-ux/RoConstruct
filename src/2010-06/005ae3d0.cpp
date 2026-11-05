// from server: 100% by Yeetserama
// roc 2010-06 005ae3d0  unit: RBX::PlayerCamera::W4CameraType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ae3d0
//
// 005ae3d0  64a100000000         mov eax, dword ptr fs:[0]
// 005ae3d6  6aff                 push -1
// 005ae3d8  68383c9900           push 0x993c38
// 005ae3dd  50                   push eax
// 005ae3de  64892500000000       mov dword ptr fs:[0], esp
// 005ae3e5  83ec0c               sub esp, 0xc
// 005ae3e8  56                   push esi
// 005ae3e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ae3ed  85f6                 test esi, esi
// 005ae3ef  742c                 je 0x5ae41d
// 005ae3f1  8b0e                 mov ecx, dword ptr [esi]
// 005ae3f3  85c9                 test ecx, ecx
// 005ae3f5  7409                 je 0x5ae400
// 005ae3f7  8b01                 mov eax, dword ptr [ecx]
// 005ae3f9  8b5004               mov edx, dword ptr [eax + 4]
// 005ae3fc  ffd2                 call edx
// 005ae3fe  eb05                 jmp 0x5ae405
// 005ae400  b80c93b700           mov eax, 0xb7930c
// 005ae405  68280cba00           push 0xba0c28
// 005ae40a  8bc8                 mov ecx, eax
// 005ae40c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005ae412  84c0                 test al, al
// 005ae414  7407                 je 0x5ae41d
// 005ae416  8b06                 mov eax, dword ptr [esi]
// 005ae418  83c004               add eax, 4
// 005ae41b  7529                 jne 0x5ae446
// 005ae41d  68540aa000           push 0xa00a54
// 005ae422  8d4c2408             lea ecx, [esp + 8]
// 005ae426  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ae42c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005ae434  8d442404             lea eax, [esp + 4]
// 005ae438  50                   push eax
// 005ae439  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005ae441  e8eac0e5ff           call 0x40a530
// 005ae446  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ae44a  5e                   pop esi
// 005ae44b  64890d00000000       mov dword ptr fs:[0], ecx
// 005ae452  83c418               add esp, 0x18
// 005ae455  c3                   ret 
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
