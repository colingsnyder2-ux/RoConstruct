// from server: 100% by Yeetserama
// roc 2010-06 004ed8c0  unit: RBX::Network::Replicator::NewInstanceItem  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed8c0
//
// 004ed8c0  64a100000000         mov eax, dword ptr fs:[0]
// 004ed8c6  6aff                 push -1
// 004ed8c8  68383c9900           push 0x993c38
// 004ed8cd  50                   push eax
// 004ed8ce  64892500000000       mov dword ptr fs:[0], esp
// 004ed8d5  83ec0c               sub esp, 0xc
// 004ed8d8  56                   push esi
// 004ed8d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ed8dd  85f6                 test esi, esi
// 004ed8df  742c                 je 0x4ed90d
// 004ed8e1  8b0e                 mov ecx, dword ptr [esi]
// 004ed8e3  85c9                 test ecx, ecx
// 004ed8e5  7409                 je 0x4ed8f0
// 004ed8e7  8b01                 mov eax, dword ptr [ecx]
// 004ed8e9  8b5004               mov edx, dword ptr [eax + 4]
// 004ed8ec  ffd2                 call edx
// 004ed8ee  eb05                 jmp 0x4ed8f5
// 004ed8f0  b80c93b700           mov eax, 0xb7930c
// 004ed8f5  685424b900           push 0xb92454
// 004ed8fa  8bc8                 mov ecx, eax
// 004ed8fc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004ed902  84c0                 test al, al
// 004ed904  7407                 je 0x4ed90d
// 004ed906  8b06                 mov eax, dword ptr [esi]
// 004ed908  83c004               add eax, 4
// 004ed90b  7529                 jne 0x4ed936
// 004ed90d  68540aa000           push 0xa00a54
// 004ed912  8d4c2408             lea ecx, [esp + 8]
// 004ed916  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ed91c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004ed924  8d442404             lea eax, [esp + 4]
// 004ed928  50                   push eax
// 004ed929  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004ed931  e8facbf1ff           call 0x40a530
// 004ed936  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ed93a  5e                   pop esi
// 004ed93b  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed942  83c418               add esp, 0x18
// 004ed945  c3                   ret 
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
