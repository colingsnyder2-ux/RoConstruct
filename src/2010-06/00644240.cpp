// from server: 100% by Yeetserama
// roc 2010-06 00644240  unit: RBX::VAnimationId::?$TypedPropertyDescriptor  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00644240
//
// 00644240  64a100000000         mov eax, dword ptr fs:[0]
// 00644246  6aff                 push -1
// 00644248  68383c9900           push 0x993c38
// 0064424d  50                   push eax
// 0064424e  64892500000000       mov dword ptr fs:[0], esp
// 00644255  83ec0c               sub esp, 0xc
// 00644258  56                   push esi
// 00644259  8b742420             mov esi, dword ptr [esp + 0x20]
// 0064425d  85f6                 test esi, esi
// 0064425f  742c                 je 0x64428d
// 00644261  8b0e                 mov ecx, dword ptr [esi]
// 00644263  85c9                 test ecx, ecx
// 00644265  7409                 je 0x644270
// 00644267  8b01                 mov eax, dword ptr [ecx]
// 00644269  8b5004               mov edx, dword ptr [eax + 4]
// 0064426c  ffd2                 call edx
// 0064426e  eb05                 jmp 0x644275
// 00644270  b80c93b700           mov eax, 0xb7930c
// 00644275  68f45dbb00           push 0xbb5df4
// 0064427a  8bc8                 mov ecx, eax
// 0064427c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00644282  84c0                 test al, al
// 00644284  7407                 je 0x64428d
// 00644286  8b06                 mov eax, dword ptr [esi]
// 00644288  83c004               add eax, 4
// 0064428b  7529                 jne 0x6442b6
// 0064428d  68540aa000           push 0xa00a54
// 00644292  8d4c2408             lea ecx, [esp + 8]
// 00644296  ff159ca89e00         call dword ptr [0x9ea89c]
// 0064429c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 006442a4  8d442404             lea eax, [esp + 4]
// 006442a8  50                   push eax
// 006442a9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006442b1  e87a62dcff           call 0x40a530
// 006442b6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006442ba  5e                   pop esi
// 006442bb  64890d00000000       mov dword ptr fs:[0], ecx
// 006442c2  83c418               add esp, 0x18
// 006442c5  c3                   ret 
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
