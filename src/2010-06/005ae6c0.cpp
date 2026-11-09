// from server: 100% by Yeetserama
// roc 2010-06 005ae6c0  unit: RBX::LegacyController::W4InputType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ae6c0
//
// 005ae6c0  64a100000000         mov eax, dword ptr fs:[0]
// 005ae6c6  6aff                 push -1
// 005ae6c8  68383c9900           push 0x993c38
// 005ae6cd  50                   push eax
// 005ae6ce  64892500000000       mov dword ptr fs:[0], esp
// 005ae6d5  83ec0c               sub esp, 0xc
// 005ae6d8  56                   push esi
// 005ae6d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ae6dd  85f6                 test esi, esi
// 005ae6df  742c                 je 0x5ae70d
// 005ae6e1  8b0e                 mov ecx, dword ptr [esi]
// 005ae6e3  85c9                 test ecx, ecx
// 005ae6e5  7409                 je 0x5ae6f0
// 005ae6e7  8b01                 mov eax, dword ptr [ecx]
// 005ae6e9  8b5004               mov edx, dword ptr [eax + 4]
// 005ae6ec  ffd2                 call edx
// 005ae6ee  eb05                 jmp 0x5ae6f5
// 005ae6f0  b80c93b700           mov eax, 0xb7930c
// 005ae6f5  68ec0cba00           push 0xba0cec
// 005ae6fa  8bc8                 mov ecx, eax
// 005ae6fc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005ae702  84c0                 test al, al
// 005ae704  7407                 je 0x5ae70d
// 005ae706  8b06                 mov eax, dword ptr [esi]
// 005ae708  83c004               add eax, 4
// 005ae70b  7529                 jne 0x5ae736
// 005ae70d  68540aa000           push 0xa00a54
// 005ae712  8d4c2408             lea ecx, [esp + 8]
// 005ae716  ff159ca89e00         call dword ptr [0x9ea89c]
// 005ae71c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005ae724  8d442404             lea eax, [esp + 4]
// 005ae728  50                   push eax
// 005ae729  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005ae731  e8fabde5ff           call 0x40a530
// 005ae736  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005ae73a  5e                   pop esi
// 005ae73b  64890d00000000       mov dword ptr fs:[0], ecx
// 005ae742  83c418               add esp, 0x18
// 005ae745  c3                   ret 
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
