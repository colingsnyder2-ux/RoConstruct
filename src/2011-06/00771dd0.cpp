// from server: 100% by Yeetserama
// roc 2011-06 00771dd0  unit: RBX::Lua::VFunctionScriptSlot::PAV?$TGenericSlotWrapper::?$sp_counted_impl_pd  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00771dd0
//
// 00771dd0  64a100000000         mov eax, dword ptr fs:[0]
// 00771dd6  6aff                 push -1
// 00771dd8  68381e9d00           push 0x9d1e38
// 00771ddd  50                   push eax
// 00771dde  64892500000000       mov dword ptr fs:[0], esp
// 00771de5  83ec0c               sub esp, 0xc
// 00771de8  56                   push esi
// 00771de9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00771ded  85f6                 test esi, esi
// 00771def  742c                 je 0x771e1d
// 00771df1  8b0e                 mov ecx, dword ptr [esi]
// 00771df3  85c9                 test ecx, ecx
// 00771df5  7409                 je 0x771e00
// 00771df7  8b01                 mov eax, dword ptr [ecx]
// 00771df9  8b5004               mov edx, dword ptr [eax + 4]
// 00771dfc  ffd2                 call edx
// 00771dfe  eb05                 jmp 0x771e05
// 00771e00  b8447ac000           mov eax, 0xc07a44
// 00771e05  68f0f3c800           push 0xc8f3f0
// 00771e0a  8bc8                 mov ecx, eax
// 00771e0c  ff15500aa400         call dword ptr [0xa40a50]
// 00771e12  84c0                 test al, al
// 00771e14  7407                 je 0x771e1d
// 00771e16  8b06                 mov eax, dword ptr [esi]
// 00771e18  83c004               add eax, 4
// 00771e1b  7529                 jne 0x771e46
// 00771e1d  680cc1a500           push 0xa5c10c
// 00771e22  8d4c2408             lea ecx, [esp + 8]
// 00771e26  ff15100aa400         call dword ptr [0xa40a10]
// 00771e2c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 00771e34  8d442404             lea eax, [esp + 4]
// 00771e38  50                   push eax
// 00771e39  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00771e41  e88abbc9ff           call 0x40d9d0
// 00771e46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00771e4a  5e                   pop esi
// 00771e4b  64890d00000000       mov dword ptr fs:[0], ecx
// 00771e52  83c418               add esp, 0x18
// 00771e55  c3                   ret 
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
