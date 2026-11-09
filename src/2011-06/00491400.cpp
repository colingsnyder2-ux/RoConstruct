// from server: 100% by Yeetserama
// roc 2011-06 00491400  unit: CRobloxScriptReviewPaneView  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00491400
//
// 00491400  64a100000000         mov eax, dword ptr fs:[0]
// 00491406  6aff                 push -1
// 00491408  68381e9d00           push 0x9d1e38
// 0049140d  50                   push eax
// 0049140e  64892500000000       mov dword ptr fs:[0], esp
// 00491415  83ec0c               sub esp, 0xc
// 00491418  56                   push esi
// 00491419  8b742420             mov esi, dword ptr [esp + 0x20]
// 0049141d  85f6                 test esi, esi
// 0049141f  742c                 je 0x49144d
// 00491421  8b0e                 mov ecx, dword ptr [esi]
// 00491423  85c9                 test ecx, ecx
// 00491425  7409                 je 0x491430
// 00491427  8b01                 mov eax, dword ptr [ecx]
// 00491429  8b5004               mov edx, dword ptr [eax + 4]
// 0049142c  ffd2                 call edx
// 0049142e  eb05                 jmp 0x491435
// 00491430  b8447ac000           mov eax, 0xc07a44
// 00491435  686c92c100           push 0xc1926c
// 0049143a  8bc8                 mov ecx, eax
// 0049143c  ff15500aa400         call dword ptr [0xa40a50]
// 00491442  84c0                 test al, al
// 00491444  7407                 je 0x49144d
// 00491446  8b06                 mov eax, dword ptr [esi]
// 00491448  83c004               add eax, 4
// 0049144b  7529                 jne 0x491476
// 0049144d  680cc1a500           push 0xa5c10c
// 00491452  8d4c2408             lea ecx, [esp + 8]
// 00491456  ff15100aa400         call dword ptr [0xa40a10]
// 0049145c  c744240404c1a500     mov dword ptr [esp + 4], 0xa5c104
// 00491464  8d442404             lea eax, [esp + 4]
// 00491468  50                   push eax
// 00491469  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00491471  e85ac5f7ff           call 0x40d9d0
// 00491476  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049147a  5e                   pop esi
// 0049147b  64890d00000000       mov dword ptr fs:[0], ecx
// 00491482  83c418               add esp, 0x18
// 00491485  c3                   ret 
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
