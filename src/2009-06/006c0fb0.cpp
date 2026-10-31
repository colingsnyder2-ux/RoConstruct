// from server: 100% by EspClaude
// roc 2009-06 006c0fb0  unit: VWaitScriptSlot::?$TGenericSlotWrapper  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c0fb0
//
// 006c0fb0  64a100000000         mov eax, dword ptr fs:[0]
// 006c0fb6  6aff                 push -1
// 006c0fb8  68789d8600           push 0x869d78
// 006c0fbd  50                   push eax
// 006c0fbe  64892500000000       mov dword ptr fs:[0], esp
// 006c0fc5  83ec0c               sub esp, 0xc
// 006c0fc8  56                   push esi
// 006c0fc9  8b742420             mov esi, dword ptr [esp + 0x20]
// 006c0fcd  85f6                 test esi, esi
// 006c0fcf  742c                 je 0x6c0ffd
// 006c0fd1  8b0e                 mov ecx, dword ptr [esi]
// 006c0fd3  85c9                 test ecx, ecx
// 006c0fd5  7409                 je 0x6c0fe0
// 006c0fd7  8b01                 mov eax, dword ptr [ecx]
// 006c0fd9  8b5004               mov edx, dword ptr [eax + 4]
// 006c0fdc  ffd2                 call edx
// 006c0fde  eb05                 jmp 0x6c0fe5
// 006c0fe0  b8d4c29d00           mov eax, 0x9dc2d4
// 006c0fe5  6880f0a000           push 0xa0f080
// 006c0fea  8bc8                 mov ecx, eax
// 006c0fec  ff15a4e98900         call dword ptr [0x89e9a4]
// 006c0ff2  84c0                 test al, al
// 006c0ff4  7407                 je 0x6c0ffd
// 006c0ff6  8b06                 mov eax, dword ptr [esi]
// 006c0ff8  83c004               add eax, 4
// 006c0ffb  7529                 jne 0x6c1026
// 006c0ffd  6850d38a00           push 0x8ad350
// 006c1002  8d4c2408             lea ecx, [esp + 8]
// 006c1006  ff1570e98900         call dword ptr [0x89e970]
// 006c100c  c744240448d38a00     mov dword ptr [esp + 4], 0x8ad348
// 006c1014  8d442404             lea eax, [esp + 4]
// 006c1018  50                   push eax
// 006c1019  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 006c1021  e89a92d4ff           call 0x40a2c0
// 006c1026  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c102a  5e                   pop esi
// 006c102b  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1032  83c418               add esp, 0x18
// 006c1035  c3                   ret 
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
