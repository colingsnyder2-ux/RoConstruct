// from server: 100% by Yeetserama
// roc 2010-06 00590430  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00590430
//
// 00590430  64a100000000         mov eax, dword ptr fs:[0]
// 00590436  6aff                 push -1
// 00590438  68383c9900           push 0x993c38
// 0059043d  50                   push eax
// 0059043e  64892500000000       mov dword ptr fs:[0], esp
// 00590445  83ec0c               sub esp, 0xc
// 00590448  56                   push esi
// 00590449  8b742420             mov esi, dword ptr [esp + 0x20]
// 0059044d  85f6                 test esi, esi
// 0059044f  742c                 je 0x59047d
// 00590451  8b0e                 mov ecx, dword ptr [esi]
// 00590453  85c9                 test ecx, ecx
// 00590455  7409                 je 0x590460
// 00590457  8b01                 mov eax, dword ptr [ecx]
// 00590459  8b5004               mov edx, dword ptr [eax + 4]
// 0059045c  ffd2                 call edx
// 0059045e  eb05                 jmp 0x590465
// 00590460  b80c93b700           mov eax, 0xb7930c
// 00590465  6834cab900           push 0xb9ca34
// 0059046a  8bc8                 mov ecx, eax
// 0059046c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00590472  84c0                 test al, al
// 00590474  7407                 je 0x59047d
// 00590476  8b06                 mov eax, dword ptr [esi]
// 00590478  83c004               add eax, 4
// 0059047b  7529                 jne 0x5904a6
// 0059047d  68540aa000           push 0xa00a54
// 00590482  8d4c2408             lea ecx, [esp + 8]
// 00590486  ff159ca89e00         call dword ptr [0x9ea89c]
// 0059048c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00590494  8d442404             lea eax, [esp + 4]
// 00590498  50                   push eax
// 00590499  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005904a1  e88aa0e7ff           call 0x40a530
// 005904a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005904aa  5e                   pop esi
// 005904ab  64890d00000000       mov dword ptr fs:[0], ecx
// 005904b2  83c418               add esp, 0x18
// 005904b5  c3                   ret 
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
