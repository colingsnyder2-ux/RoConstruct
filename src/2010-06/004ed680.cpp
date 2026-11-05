// from server: 100% by Yeetserama
// roc 2010-06 004ed680  unit: RBX::Network::Replicator::NewInstanceItem  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed680
//
// 004ed680  64a100000000         mov eax, dword ptr fs:[0]
// 004ed686  6aff                 push -1
// 004ed688  68383c9900           push 0x993c38
// 004ed68d  50                   push eax
// 004ed68e  64892500000000       mov dword ptr fs:[0], esp
// 004ed695  83ec0c               sub esp, 0xc
// 004ed698  56                   push esi
// 004ed699  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ed69d  85f6                 test esi, esi
// 004ed69f  742c                 je 0x4ed6cd
// 004ed6a1  8b0e                 mov ecx, dword ptr [esi]
// 004ed6a3  85c9                 test ecx, ecx
// 004ed6a5  7409                 je 0x4ed6b0
// 004ed6a7  8b01                 mov eax, dword ptr [ecx]
// 004ed6a9  8b5004               mov edx, dword ptr [eax + 4]
// 004ed6ac  ffd2                 call edx
// 004ed6ae  eb05                 jmp 0x4ed6b5
// 004ed6b0  b80c93b700           mov eax, 0xb7930c
// 004ed6b5  685023b900           push 0xb92350
// 004ed6ba  8bc8                 mov ecx, eax
// 004ed6bc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004ed6c2  84c0                 test al, al
// 004ed6c4  7407                 je 0x4ed6cd
// 004ed6c6  8b06                 mov eax, dword ptr [esi]
// 004ed6c8  83c004               add eax, 4
// 004ed6cb  7529                 jne 0x4ed6f6
// 004ed6cd  68540aa000           push 0xa00a54
// 004ed6d2  8d4c2408             lea ecx, [esp + 8]
// 004ed6d6  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ed6dc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004ed6e4  8d442404             lea eax, [esp + 4]
// 004ed6e8  50                   push eax
// 004ed6e9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004ed6f1  e83acef1ff           call 0x40a530
// 004ed6f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ed6fa  5e                   pop esi
// 004ed6fb  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed702  83c418               add esp, 0x18
// 004ed705  c3                   ret 
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
