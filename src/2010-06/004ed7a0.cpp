// from server: 100% by Yeetserama
// roc 2010-06 004ed7a0  unit: RBX::Network::Replicator::NewInstanceItem  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed7a0
//
// 004ed7a0  64a100000000         mov eax, dword ptr fs:[0]
// 004ed7a6  6aff                 push -1
// 004ed7a8  68383c9900           push 0x993c38
// 004ed7ad  50                   push eax
// 004ed7ae  64892500000000       mov dword ptr fs:[0], esp
// 004ed7b5  83ec0c               sub esp, 0xc
// 004ed7b8  56                   push esi
// 004ed7b9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ed7bd  85f6                 test esi, esi
// 004ed7bf  742c                 je 0x4ed7ed
// 004ed7c1  8b0e                 mov ecx, dword ptr [esi]
// 004ed7c3  85c9                 test ecx, ecx
// 004ed7c5  7409                 je 0x4ed7d0
// 004ed7c7  8b01                 mov eax, dword ptr [ecx]
// 004ed7c9  8b5004               mov edx, dword ptr [eax + 4]
// 004ed7cc  ffd2                 call edx
// 004ed7ce  eb05                 jmp 0x4ed7d5
// 004ed7d0  b80c93b700           mov eax, 0xb7930c
// 004ed7d5  687c1cb900           push 0xb91c7c
// 004ed7da  8bc8                 mov ecx, eax
// 004ed7dc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004ed7e2  84c0                 test al, al
// 004ed7e4  7407                 je 0x4ed7ed
// 004ed7e6  8b06                 mov eax, dword ptr [esi]
// 004ed7e8  83c004               add eax, 4
// 004ed7eb  7529                 jne 0x4ed816
// 004ed7ed  68540aa000           push 0xa00a54
// 004ed7f2  8d4c2408             lea ecx, [esp + 8]
// 004ed7f6  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ed7fc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004ed804  8d442404             lea eax, [esp + 4]
// 004ed808  50                   push eax
// 004ed809  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004ed811  e81acdf1ff           call 0x40a530
// 004ed816  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ed81a  5e                   pop esi
// 004ed81b  64890d00000000       mov dword ptr fs:[0], ecx
// 004ed822  83c418               add esp, 0x18
// 004ed825  c3                   ret 
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
