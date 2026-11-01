// from server: 100% by Yeetserama
// roc 2010-06 00590550  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00590550
//
// 00590550  64a100000000         mov eax, dword ptr fs:[0]
// 00590556  6aff                 push -1
// 00590558  68383c9900           push 0x993c38
// 0059055d  50                   push eax
// 0059055e  64892500000000       mov dword ptr fs:[0], esp
// 00590565  83ec0c               sub esp, 0xc
// 00590568  56                   push esi
// 00590569  8b742420             mov esi, dword ptr [esp + 0x20]
// 0059056d  85f6                 test esi, esi
// 0059056f  742c                 je 0x59059d
// 00590571  8b0e                 mov ecx, dword ptr [esi]
// 00590573  85c9                 test ecx, ecx
// 00590575  7409                 je 0x590580
// 00590577  8b01                 mov eax, dword ptr [ecx]
// 00590579  8b5004               mov edx, dword ptr [eax + 4]
// 0059057c  ffd2                 call edx
// 0059057e  eb05                 jmp 0x590585
// 00590580  b80c93b700           mov eax, 0xb7930c
// 00590585  68cccbb900           push 0xb9cbcc
// 0059058a  8bc8                 mov ecx, eax
// 0059058c  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00590592  84c0                 test al, al
// 00590594  7407                 je 0x59059d
// 00590596  8b06                 mov eax, dword ptr [esi]
// 00590598  83c004               add eax, 4
// 0059059b  7529                 jne 0x5905c6
// 0059059d  68540aa000           push 0xa00a54
// 005905a2  8d4c2408             lea ecx, [esp + 8]
// 005905a6  ff159ca89e00         call dword ptr [0x9ea89c]
// 005905ac  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005905b4  8d442404             lea eax, [esp + 4]
// 005905b8  50                   push eax
// 005905b9  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005905c1  e86a9fe7ff           call 0x40a530
// 005905c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005905ca  5e                   pop esi
// 005905cb  64890d00000000       mov dword ptr fs:[0], ecx
// 005905d2  83c418               add esp, 0x18
// 005905d5  c3                   ret 
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
