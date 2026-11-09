// from server: 100% by Yeetserama
// roc 2010-06 005af570  unit: RBX::Joint::W4JointType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005af570
//
// 005af570  64a100000000         mov eax, dword ptr fs:[0]
// 005af576  6aff                 push -1
// 005af578  68383c9900           push 0x993c38
// 005af57d  50                   push eax
// 005af57e  64892500000000       mov dword ptr fs:[0], esp
// 005af585  83ec0c               sub esp, 0xc
// 005af588  56                   push esi
// 005af589  8b742420             mov esi, dword ptr [esp + 0x20]
// 005af58d  85f6                 test esi, esi
// 005af58f  742c                 je 0x5af5bd
// 005af591  8b0e                 mov ecx, dword ptr [esi]
// 005af593  85c9                 test ecx, ecx
// 005af595  7409                 je 0x5af5a0
// 005af597  8b01                 mov eax, dword ptr [ecx]
// 005af599  8b5004               mov edx, dword ptr [eax + 4]
// 005af59c  ffd2                 call edx
// 005af59e  eb05                 jmp 0x5af5a5
// 005af5a0  b80c93b700           mov eax, 0xb7930c
// 005af5a5  684810ba00           push 0xba1048
// 005af5aa  8bc8                 mov ecx, eax
// 005af5ac  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005af5b2  84c0                 test al, al
// 005af5b4  7407                 je 0x5af5bd
// 005af5b6  8b06                 mov eax, dword ptr [esi]
// 005af5b8  83c004               add eax, 4
// 005af5bb  7529                 jne 0x5af5e6
// 005af5bd  68540aa000           push 0xa00a54
// 005af5c2  8d4c2408             lea ecx, [esp + 8]
// 005af5c6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005af5cc  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005af5d4  8d442404             lea eax, [esp + 4]
// 005af5d8  50                   push eax
// 005af5d9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005af5e1  e84aafe5ff           call 0x40a530
// 005af5e6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005af5ea  5e                   pop esi
// 005af5eb  64890d00000000       mov dword ptr fs:[0], ecx
// 005af5f2  83c418               add esp, 0x18
// 005af5f5  c3                   ret 
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
