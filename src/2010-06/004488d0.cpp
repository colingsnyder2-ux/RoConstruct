// from server: 100% by Yeetserama
// roc 2010-06 004488d0  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004488d0
//
// 004488d0  64a100000000         mov eax, dword ptr fs:[0]
// 004488d6  6aff                 push -1
// 004488d8  68383c9900           push 0x993c38
// 004488dd  50                   push eax
// 004488de  64892500000000       mov dword ptr fs:[0], esp
// 004488e5  83ec0c               sub esp, 0xc
// 004488e8  56                   push esi
// 004488e9  8b742420             mov esi, dword ptr [esp + 0x20]
// 004488ed  85f6                 test esi, esi
// 004488ef  742c                 je 0x44891d
// 004488f1  8b0e                 mov ecx, dword ptr [esi]
// 004488f3  85c9                 test ecx, ecx
// 004488f5  7409                 je 0x448900
// 004488f7  8b01                 mov eax, dword ptr [ecx]
// 004488f9  8b5004               mov edx, dword ptr [eax + 4]
// 004488fc  ffd2                 call edx
// 004488fe  eb05                 jmp 0x448905
// 00448900  b80c93b700           mov eax, 0xb7930c
// 00448905  68b012b800           push 0xb812b0
// 0044890a  8bc8                 mov ecx, eax
// 0044890c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00448912  84c0                 test al, al
// 00448914  7407                 je 0x44891d
// 00448916  8b06                 mov eax, dword ptr [esi]
// 00448918  83c004               add eax, 4
// 0044891b  7529                 jne 0x448946
// 0044891d  68540aa000           push 0xa00a54
// 00448922  8d4c2408             lea ecx, [esp + 8]
// 00448926  ff159ca89e00         call dword ptr [0x9ea89c]
// 0044892c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00448934  8d442404             lea eax, [esp + 4]
// 00448938  50                   push eax
// 00448939  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00448941  e8ea1bfcff           call 0x40a530
// 00448946  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044894a  5e                   pop esi
// 0044894b  64890d00000000       mov dword ptr fs:[0], ecx
// 00448952  83c418               add esp, 0x18
// 00448955  c3                   ret 
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
