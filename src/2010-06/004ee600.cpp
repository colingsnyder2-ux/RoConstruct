// from server: 100% by Yeetserama
// roc 2010-06 004ee600  unit: RBX::Network::Replicator::NewInstanceItem  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ee600
//
// 004ee600  64a100000000         mov eax, dword ptr fs:[0]
// 004ee606  6aff                 push -1
// 004ee608  68383c9900           push 0x993c38
// 004ee60d  50                   push eax
// 004ee60e  64892500000000       mov dword ptr fs:[0], esp
// 004ee615  83ec0c               sub esp, 0xc
// 004ee618  56                   push esi
// 004ee619  8b742420             mov esi, dword ptr [esp + 0x20]
// 004ee61d  85f6                 test esi, esi
// 004ee61f  742c                 je 0x4ee64d
// 004ee621  8b0e                 mov ecx, dword ptr [esi]
// 004ee623  85c9                 test ecx, ecx
// 004ee625  7409                 je 0x4ee630
// 004ee627  8b01                 mov eax, dword ptr [ecx]
// 004ee629  8b5004               mov edx, dword ptr [eax + 4]
// 004ee62c  ffd2                 call edx
// 004ee62e  eb05                 jmp 0x4ee635
// 004ee630  b80c93b700           mov eax, 0xb7930c
// 004ee635  685020b900           push 0xb92050
// 004ee63a  8bc8                 mov ecx, eax
// 004ee63c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 004ee642  84c0                 test al, al
// 004ee644  7407                 je 0x4ee64d
// 004ee646  8b06                 mov eax, dword ptr [esi]
// 004ee648  83c004               add eax, 4
// 004ee64b  7529                 jne 0x4ee676
// 004ee64d  68540aa000           push 0xa00a54
// 004ee652  8d4c2408             lea ecx, [esp + 8]
// 004ee656  ff159ca89e00         call dword ptr [0x9ea89c]
// 004ee65c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 004ee664  8d442404             lea eax, [esp + 4]
// 004ee668  50                   push eax
// 004ee669  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004ee671  e8babef1ff           call 0x40a530
// 004ee676  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ee67a  5e                   pop esi
// 004ee67b  64890d00000000       mov dword ptr fs:[0], ecx
// 004ee682  83c418               add esp, 0x18
// 004ee685  c3                   ret 
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
