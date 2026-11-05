// from server: 100% by Yeetserama
// roc 2010-06 005ae9b0  unit: RBX::DataModelMesh::W4LODType::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ae9b0
//
// 005ae9b0  64a100000000         mov eax, dword ptr fs:[0]
// 005ae9b6  6aff                 push -1
// 005ae9b8  68383c9900           push 0x993c38
// 005ae9bd  50                   push eax
// 005ae9be  64892500000000       mov dword ptr fs:[0], esp
// 005ae9c5  83ec0c               sub esp, 0xc
// 005ae9c8  56                   push esi
// 005ae9c9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ae9cd  85f6                 test esi, esi
// 005ae9cf  742c                 je 0x5ae9fd
// 005ae9d1  8b0e                 mov ecx, dword ptr [esi]
// 005ae9d3  85c9                 test ecx, ecx
// 005ae9d5  7409                 je 0x5ae9e0
// 005ae9d7  8b01                 mov eax, dword ptr [ecx]
// 005ae9d9  8b5004               mov edx, dword ptr [eax + 4]
// 005ae9dc  ffd2                 call edx
// 005ae9de  eb05                 jmp 0x5ae9e5
// 005ae9e0  b80c93b700           mov eax, 0xb7930c
// 005ae9e5  68b00dba00           push 0xba0db0
// 005ae9ea  8bc8                 mov ecx, eax
// 005ae9ec  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 005ae9f2  84c0                 test al, al
// 005ae9f4  7407                 je 0x5ae9fd
// 005ae9f6  8b06                 mov eax, dword ptr [esi]
// 005ae9f8  83c004               add eax, 4
// 005ae9fb  7529                 jne 0x5aea26
// 005ae9fd  68540aa000           push 0xa00a54
// 005aea02  8d4c2408             lea ecx, [esp + 8]
// 005aea06  ff159ca89e00         call dword ptr [0x9ea89c]
// 005aea0c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 005aea14  8d442404             lea eax, [esp + 4]
// 005aea18  50                   push eax
// 005aea19  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005aea21  e80abbe5ff           call 0x40a530
// 005aea26  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005aea2a  5e                   pop esi
// 005aea2b  64890d00000000       mov dword ptr fs:[0], ecx
// 005aea32  83c418               add esp, 0x18
// 005aea35  c3                   ret 
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
