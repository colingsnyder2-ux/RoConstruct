// from server: 100% by Yeetserama
// roc 2010-06 00590310  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00590310
//
// 00590310  64a100000000         mov eax, dword ptr fs:[0]
// 00590316  6aff                 push -1
// 00590318  68383c9900           push 0x993c38
// 0059031d  50                   push eax
// 0059031e  64892500000000       mov dword ptr fs:[0], esp
// 00590325  83ec0c               sub esp, 0xc
// 00590328  56                   push esi
// 00590329  8b742420             mov esi, dword ptr [esp + 0x20]
// 0059032d  85f6                 test esi, esi
// 0059032f  742c                 je 0x59035d
// 00590331  8b0e                 mov ecx, dword ptr [esi]
// 00590333  85c9                 test ecx, ecx
// 00590335  7409                 je 0x590340
// 00590337  8b01                 mov eax, dword ptr [ecx]
// 00590339  8b5004               mov edx, dword ptr [eax + 4]
// 0059033c  ffd2                 call edx
// 0059033e  eb05                 jmp 0x590345
// 00590340  b80c93b700           mov eax, 0xb7930c
// 00590345  6898c8b900           push 0xb9c898
// 0059034a  8bc8                 mov ecx, eax
// 0059034c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00590352  84c0                 test al, al
// 00590354  7407                 je 0x59035d
// 00590356  8b06                 mov eax, dword ptr [esi]
// 00590358  83c004               add eax, 4
// 0059035b  7529                 jne 0x590386
// 0059035d  68540aa000           push 0xa00a54
// 00590362  8d4c2408             lea ecx, [esp + 8]
// 00590366  ff159ca89e00         call dword ptr [0x9ea89c]
// 0059036c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00590374  8d442404             lea eax, [esp + 4]
// 00590378  50                   push eax
// 00590379  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00590381  e8aaa1e7ff           call 0x40a530
// 00590386  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0059038a  5e                   pop esi
// 0059038b  64890d00000000       mov dword ptr fs:[0], ecx
// 00590392  83c418               add esp, 0x18
// 00590395  c3                   ret 
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
