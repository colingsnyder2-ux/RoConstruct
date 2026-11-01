// from server: 100% by Yeetserama
// roc 2010-06 005922d0  unit: RBX::EThrottle::W4EThrottleType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005922d0
//
// 005922d0  64a100000000         mov eax, dword ptr fs:[0]
// 005922d6  6aff                 push -1
// 005922d8  68383c9900           push 0x993c38
// 005922dd  50                   push eax
// 005922de  64892500000000       mov dword ptr fs:[0], esp
// 005922e5  83ec0c               sub esp, 0xc
// 005922e8  56                   push esi
// 005922e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005922ed  85f6                 test esi, esi
// 005922ef  742c                 je 0x59231d
// 005922f1  8b0e                 mov ecx, dword ptr [esi]
// 005922f3  85c9                 test ecx, ecx
// 005922f5  7409                 je 0x592300
// 005922f7  8b01                 mov eax, dword ptr [ecx]
// 005922f9  8b5004               mov edx, dword ptr [eax + 4]
// 005922fc  ffd2                 call edx
// 005922fe  eb05                 jmp 0x592305
// 00592300  b80c93b700           mov eax, 0xb7930c
// 00592305  68a8cfb900           push 0xb9cfa8
// 0059230a  8bc8                 mov ecx, eax
// 0059230c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00592312  84c0                 test al, al
// 00592314  7407                 je 0x59231d
// 00592316  8b06                 mov eax, dword ptr [esi]
// 00592318  83c004               add eax, 4
// 0059231b  7529                 jne 0x592346
// 0059231d  68540aa000           push 0xa00a54
// 00592322  8d4c2408             lea ecx, [esp + 8]
// 00592326  ff159ca89e00         call dword ptr [0x9ea89c]
// 0059232c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00592334  8d442404             lea eax, [esp + 4]
// 00592338  50                   push eax
// 00592339  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00592341  e8ea81e7ff           call 0x40a530
// 00592346  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0059234a  5e                   pop esi
// 0059234b  64890d00000000       mov dword ptr fs:[0], ecx
// 00592352  83c418               add esp, 0x18
// 00592355  c3                   ret 
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
