// from server: 100% by Yeetserama
// roc 2010-06 005b0250  unit: RBX::Humanoid::W4Status::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005b0250
//
// 005b0250  64a100000000         mov eax, dword ptr fs:[0]
// 005b0256  6aff                 push -1
// 005b0258  68383c9900           push 0x993c38
// 005b025d  50                   push eax
// 005b025e  64892500000000       mov dword ptr fs:[0], esp
// 005b0265  83ec0c               sub esp, 0xc
// 005b0268  56                   push esi
// 005b0269  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b026d  85f6                 test esi, esi
// 005b026f  742c                 je 0x5b029d
// 005b0271  8b0e                 mov ecx, dword ptr [esi]
// 005b0273  85c9                 test ecx, ecx
// 005b0275  7409                 je 0x5b0280
// 005b0277  8b01                 mov eax, dword ptr [ecx]
// 005b0279  8b5004               mov edx, dword ptr [eax + 4]
// 005b027c  ffd2                 call edx
// 005b027e  eb05                 jmp 0x5b0285
// 005b0280  b80c93b700           mov eax, 0xb7930c
// 005b0285  68e812ba00           push 0xba12e8
// 005b028a  8bc8                 mov ecx, eax
// 005b028c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005b0292  84c0                 test al, al
// 005b0294  7407                 je 0x5b029d
// 005b0296  8b06                 mov eax, dword ptr [esi]
// 005b0298  83c004               add eax, 4
// 005b029b  7529                 jne 0x5b02c6
// 005b029d  68540aa000           push 0xa00a54
// 005b02a2  8d4c2408             lea ecx, [esp + 8]
// 005b02a6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005b02ac  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005b02b4  8d442404             lea eax, [esp + 4]
// 005b02b8  50                   push eax
// 005b02b9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005b02c1  e86aa2e5ff           call 0x40a530
// 005b02c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b02ca  5e                   pop esi
// 005b02cb  64890d00000000       mov dword ptr fs:[0], ecx
// 005b02d2  83c418               add esp, 0x18
// 005b02d5  c3                   ret 
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
