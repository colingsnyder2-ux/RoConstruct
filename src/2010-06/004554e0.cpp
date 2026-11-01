// from server: 100% by Yeetserama
// roc 2010-06 004554e0  unit: RBX::PartInstance::W4Material::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004554e0
//
// 004554e0  64a100000000         mov eax, dword ptr fs:[0]
// 004554e6  6aff                 push -1
// 004554e8  68383c9900           push 0x993c38
// 004554ed  50                   push eax
// 004554ee  64892500000000       mov dword ptr fs:[0], esp
// 004554f5  83ec0c               sub esp, 0xc
// 004554f8  56                   push esi
// 004554f9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004554fd  85f6                 test esi, esi
// 004554ff  742c                 je 0x45552d
// 00455501  8b0e                 mov ecx, dword ptr [esi]
// 00455503  85c9                 test ecx, ecx
// 00455505  7409                 je 0x455510
// 00455507  8b01                 mov eax, dword ptr [ecx]
// 00455509  8b5004               mov edx, dword ptr [eax + 4]
// 0045550c  ffd2                 call edx
// 0045550e  eb05                 jmp 0x455515
// 00455510  b80c93b700           mov eax, 0xb7930c
// 00455515  681827b800           push 0xb82718
// 0045551a  8bc8                 mov ecx, eax
// 0045551c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00455522  84c0                 test al, al
// 00455524  7407                 je 0x45552d
// 00455526  8b06                 mov eax, dword ptr [esi]
// 00455528  83c004               add eax, 4
// 0045552b  7529                 jne 0x455556
// 0045552d  68540aa000           push 0xa00a54
// 00455532  8d4c2408             lea ecx, [esp + 8]
// 00455536  ff159ca89e00         call dword ptr [0x9ea89c]
// 0045553c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00455544  8d442404             lea eax, [esp + 4]
// 00455548  50                   push eax
// 00455549  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00455551  e8da4ffbff           call 0x40a530
// 00455556  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045555a  5e                   pop esi
// 0045555b  64890d00000000       mov dword ptr fs:[0], ecx
// 00455562  83c418               add esp, 0x18
// 00455565  c3                   ret 
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
