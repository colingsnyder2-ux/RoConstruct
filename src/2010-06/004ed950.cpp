// from server: 100% by Yeetserama
// roc 2010-06 004ed950  unit: RBX::Network::Replicator::NewInstanceItem  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed950
//
// 004ed950  64a100000000         mov eax, dword ptr fs:[0]
// 004ed956  6aff                 push -1
// 004ed958  68383c9900           push 0x993c38
// 004ed95d  50                   push eax
// 004ed95e  64892500000000       mov dword ptr fs:[0], esp
// 004ed965  83ec0c               sub esp, 0xc
// 004ed968  56                   push esi
// 004ed969  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ed96d  85f6                 test esi, esi
// 004ed96f  742c                 je 0x4ed99d
// 004ed971  8b0e                 mov ecx, dword ptr [esi]
// 004ed973  85c9                 test ecx, ecx
// 004ed975  7409                 je 0x4ed980
// 004ed977  8b01                 mov eax, dword ptr [ecx]
// 004ed979  8b5004               mov edx, dword ptr [eax + 4]
// 004ed97c  ffd2                 call edx
// 004ed97e  eb05                 jmp 0x4ed985
// 004ed980  b80c93b700           mov eax, 0xb7930c
// 004ed985  689c24b900           push 0xb9249c
// 004ed98a  8bc8                 mov ecx, eax
// 004ed98c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004ed992  84c0                 test al, al
// 004ed994  7407                 je 0x4ed99d
// 004ed996  8b06                 mov eax, dword ptr [esi]
// 004ed998  83c004               add eax, 4
// 004ed99b  7529                 jne 0x4ed9c6
// 004ed99d  68540aa000           push 0xa00a54
// 004ed9a2  8d4c2408             lea ecx, [esp + 8]
// 004ed9a6  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ed9ac  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004ed9b4  8d442404             lea eax, [esp + 4]
// 004ed9b8  50                   push eax
// 004ed9b9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004ed9c1  e86acbf1ff           call 0x40a530
// 004ed9c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ed9ca  5e                   pop esi
// 004ed9cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed9d2  83c418               add esp, 0x18
// 004ed9d5  c3                   ret 
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
