// from server: 100% by Yeetserama
// roc 2010-06 005904c0  unit: RBX::Time::W4SampleMethod::?$EnumDesc  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005904c0
//
// 005904c0  64a100000000         mov eax, dword ptr fs:[0]
// 005904c6  6aff                 push -1
// 005904c8  68383c9900           push 0x993c38
// 005904cd  50                   push eax
// 005904ce  64892500000000       mov dword ptr fs:[0], esp
// 005904d5  83ec0c               sub esp, 0xc
// 005904d8  56                   push esi
// 005904d9  8b742420             mov esi, dword ptr [esp + 0x20]
// 005904dd  85f6                 test esi, esi
// 005904df  742c                 je 0x59050d
// 005904e1  8b0e                 mov ecx, dword ptr [esi]
// 005904e3  85c9                 test ecx, ecx
// 005904e5  7409                 je 0x5904f0
// 005904e7  8b01                 mov eax, dword ptr [ecx]
// 005904e9  8b5004               mov edx, dword ptr [eax + 4]
// 005904ec  ffd2                 call edx
// 005904ee  eb05                 jmp 0x5904f5
// 005904f0  b80c93b700           mov eax, 0xb7930c
// 005904f5  6810cbb900           push 0xb9cb10
// 005904fa  8bc8                 mov ecx, eax
// 005904fc  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00590502  84c0                 test al, al
// 00590504  7407                 je 0x59050d
// 00590506  8b06                 mov eax, dword ptr [esi]
// 00590508  83c004               add eax, 4
// 0059050b  7529                 jne 0x590536
// 0059050d  68540aa000           push 0xa00a54
// 00590512  8d4c2408             lea ecx, [esp + 8]
// 00590516  ff159ca89e00         call dword ptr [0x9ea89c]
// 0059051c  c74424044c0aa000     mov dword ptr [esp + 4], 0xa00a4c
// 00590524  8d442404             lea eax, [esp + 4]
// 00590528  50                   push eax
// 00590529  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00590531  e8fa9fe7ff           call 0x40a530
// 00590536  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0059053a  5e                   pop esi
// 0059053b  64890d00000000       mov dword ptr fs:[0], ecx
// 00590542  83c418               add esp, 0x18
// 00590545  c3                   ret 
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
