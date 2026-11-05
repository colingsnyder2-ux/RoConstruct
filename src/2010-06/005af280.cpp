// from server: 100% by Yeetserama
// roc 2010-06 005af280  unit: RBX::Feature::W4TopBottom::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005af280
//
// 005af280  64a100000000         mov eax, dword ptr fs:[0]
// 005af286  6aff                 push -1
// 005af288  68383c9900           push 0x993c38
// 005af28d  50                   push eax
// 005af28e  64892500000000       mov dword ptr fs:[0], esp
// 005af295  83ec0c               sub esp, 0xc
// 005af298  56                   push esi
// 005af299  8b742420             mov esi, dword ptr [esp + 0x20]
// 005af29d  85f6                 test esi, esi
// 005af29f  742c                 je 0x5af2cd
// 005af2a1  8b0e                 mov ecx, dword ptr [esi]
// 005af2a3  85c9                 test ecx, ecx
// 005af2a5  7409                 je 0x5af2b0
// 005af2a7  8b01                 mov eax, dword ptr [ecx]
// 005af2a9  8b5004               mov edx, dword ptr [eax + 4]
// 005af2ac  ffd2                 call edx
// 005af2ae  eb05                 jmp 0x5af2b5
// 005af2b0  b80c93b700           mov eax, 0xb7930c
// 005af2b5  68a40fba00           push 0xba0fa4
// 005af2ba  8bc8                 mov ecx, eax
// 005af2bc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005af2c2  84c0                 test al, al
// 005af2c4  7407                 je 0x5af2cd
// 005af2c6  8b06                 mov eax, dword ptr [esi]
// 005af2c8  83c004               add eax, 4
// 005af2cb  7529                 jne 0x5af2f6
// 005af2cd  68540aa000           push 0xa00a54
// 005af2d2  8d4c2408             lea ecx, [esp + 8]
// 005af2d6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005af2dc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005af2e4  8d442404             lea eax, [esp + 4]
// 005af2e8  50                   push eax
// 005af2e9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005af2f1  e83ab2e5ff           call 0x40a530
// 005af2f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005af2fa  5e                   pop esi
// 005af2fb  64890d00000000       mov dword ptr fs:[0], ecx
// 005af302  83c418               add esp, 0x18
// 005af305  c3                   ret 
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
