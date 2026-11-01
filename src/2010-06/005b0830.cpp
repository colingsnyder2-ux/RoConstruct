// from server: 100% by Yeetserama
// roc 2010-06 005b0830  unit: RBX::KeyframeSequence::W4Priority::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005b0830
//
// 005b0830  64a100000000         mov eax, dword ptr fs:[0]
// 005b0836  6aff                 push -1
// 005b0838  68383c9900           push 0x993c38
// 005b083d  50                   push eax
// 005b083e  64892500000000       mov dword ptr fs:[0], esp
// 005b0845  83ec0c               sub esp, 0xc
// 005b0848  56                   push esi
// 005b0849  8b742420             mov esi, dword ptr [esp + 0x20]
// 005b084d  85f6                 test esi, esi
// 005b084f  742c                 je 0x5b087d
// 005b0851  8b0e                 mov ecx, dword ptr [esi]
// 005b0853  85c9                 test ecx, ecx
// 005b0855  7409                 je 0x5b0860
// 005b0857  8b01                 mov eax, dword ptr [ecx]
// 005b0859  8b5004               mov edx, dword ptr [eax + 4]
// 005b085c  ffd2                 call edx
// 005b085e  eb05                 jmp 0x5b0865
// 005b0860  b80c93b700           mov eax, 0xb7930c
// 005b0865  686c14ba00           push 0xba146c
// 005b086a  8bc8                 mov ecx, eax
// 005b086c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005b0872  84c0                 test al, al
// 005b0874  7407                 je 0x5b087d
// 005b0876  8b06                 mov eax, dword ptr [esi]
// 005b0878  83c004               add eax, 4
// 005b087b  7529                 jne 0x5b08a6
// 005b087d  68540aa000           push 0xa00a54
// 005b0882  8d4c2408             lea ecx, [esp + 8]
// 005b0886  ff159ca89e00         call dword ptr [0x9ea89c]
// 005b088c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005b0894  8d442404             lea eax, [esp + 4]
// 005b0898  50                   push eax
// 005b0899  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005b08a1  e88a9ce5ff           call 0x40a530
// 005b08a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b08aa  5e                   pop esi
// 005b08ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005b08b2  83c418               add esp, 0x18
// 005b08b5  c3                   ret 
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
