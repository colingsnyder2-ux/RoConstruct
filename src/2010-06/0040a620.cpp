// from server: 100% by Yeetserama
// roc 2010-06 0040a620  unit: RBX::Reflection::ClassDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040a620
//
// 0040a620  64a100000000         mov eax, dword ptr fs:[0]
// 0040a626  6aff                 push -1
// 0040a628  68383c9900           push 0x993c38
// 0040a62d  50                   push eax
// 0040a62e  64892500000000       mov dword ptr fs:[0], esp
// 0040a635  83ec0c               sub esp, 0xc
// 0040a638  56                   push esi
// 0040a639  8b742420             mov esi, dword ptr [esp + 0x20]
// 0040a63d  85f6                 test esi, esi
// 0040a63f  742c                 je 0x40a66d
// 0040a641  8b0e                 mov ecx, dword ptr [esi]
// 0040a643  85c9                 test ecx, ecx
// 0040a645  7409                 je 0x40a650
// 0040a647  8b01                 mov eax, dword ptr [ecx]
// 0040a649  8b5004               mov edx, dword ptr [eax + 4]
// 0040a64c  ffd2                 call edx
// 0040a64e  eb05                 jmp 0x40a655
// 0040a650  b80c93b700           mov eax, 0xb7930c
// 0040a655  683c93b700           push 0xb7933c
// 0040a65a  8bc8                 mov ecx, eax
// 0040a65c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 0040a662  84c0                 test al, al
// 0040a664  7407                 je 0x40a66d
// 0040a666  8b06                 mov eax, dword ptr [esi]
// 0040a668  83c004               add eax, 4
// 0040a66b  7529                 jne 0x40a696
// 0040a66d  68540aa000           push 0xa00a54
// 0040a672  8d4c2408             lea ecx, [esp + 8]
// 0040a676  ff159ca89e00         call dword ptr [0x9ea89c]
// 0040a67c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 0040a684  8d442404             lea eax, [esp + 4]
// 0040a688  50                   push eax
// 0040a689  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0040a691  e89afeffff           call 0x40a530
// 0040a696  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040a69a  5e                   pop esi
// 0040a69b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a6a2  83c418               add esp, 0x18
// 0040a6a5  c3                   ret 
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
