// from server: 100% by EspClaude
// roc 2009-06 00612480  unit: RBX::ModelInstance  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00612480
//
// 00612480  64a100000000         mov eax, dword ptr fs:[0]
// 00612486  6aff                 push -1
// 00612488  68789d8600           push 0x869d78
// 0061248d  50                   push eax
// 0061248e  64892500000000       mov dword ptr fs:[0], esp
// 00612495  83ec0c               sub esp, 0xc
// 00612498  56                   push esi
// 00612499  8b742420             mov esi, dword ptr [esp + 0x20]
// 0061249d  85f6                 test esi, esi
// 0061249f  742c                 je 0x6124cd
// 006124a1  8b0e                 mov ecx, dword ptr [esi]
// 006124a3  85c9                 test ecx, ecx
// 006124a5  7409                 je 0x6124b0
// 006124a7  8b01                 mov eax, dword ptr [ecx]
// 006124a9  8b5004               mov edx, dword ptr [eax + 4]
// 006124ac  ffd2                 call edx
// 006124ae  eb05                 jmp 0x6124b5
// 006124b0  b8d4c29d00           mov eax, 0x9dc2d4
// 006124b5  68e010a000           push 0xa010e0
// 006124ba  8bc8                 mov ecx, eax
// 006124bc  ff15a4e98900         call dword ptr [0x89e9a4]
// 006124c2  84c0                 test al, al
// 006124c4  7407                 je 0x6124cd
// 006124c6  8b06                 mov eax, dword ptr [esi]
// 006124c8  83c004               add eax, 4
// 006124cb  7529                 jne 0x6124f6
// 006124cd  6850d38a00           push 0x8ad350
// 006124d2  8d4c2408             lea ecx, [esp + 8]
// 006124d6  ff1570e98900         call dword ptr [0x89e970]
// 006124dc  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006124e4  8d442404             lea eax, [esp + 4]
// 006124e8  50                   push eax
// 006124e9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006124f1  e8ca7ddfff           call 0x40a2c0
// 006124f6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006124fa  5e                   pop esi
// 006124fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00612502  83c418               add esp, 0x18
// 00612505  c3                   ret 
// copied from an identical function in another client (function ?castValue@ns_ROCX000002@@YAPAXPBUAny@1@@Z)

namespace ns_ROCX000002 {
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
