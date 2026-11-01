// from server: 100% by Yeetserama
// roc 2011-06 00678bf0  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00678bf0
//
// 00678bf0  6aff                 push -1
// 00678bf2  6811b59e00           push 0x9eb511
// 00678bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00678bfd  50                   push eax
// 00678bfe  64892500000000       mov dword ptr fs:[0], esp
// 00678c05  83ec0c               sub esp, 0xc
// 00678c08  56                   push esi
// 00678c09  8bf1                 mov esi, ecx
// 00678c0b  c744240400000000     mov dword ptr [esp + 4], 0
// 00678c13  8b06                 mov eax, dword ptr [esi]
// 00678c15  8b4008               mov eax, dword ptr [eax + 8]
// 00678c18  57                   push edi
// 00678c19  50                   push eax
// 00678c1a  b910aac500           mov ecx, 0xc5aa10
// 00678c1f  ff15500aa400         call dword ptr [0xa40a50]
// 00678c25  84c0                 test al, al
// 00678c27  7436                 je 0x678c5f
// 00678c29  83c604               add esi, 4
// 00678c2c  56                   push esi
// 00678c2d  e82effffff           call 0x678b60
// 00678c32  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00678c36  83c404               add esp, 4
// 00678c39  8bf0                 mov esi, eax
// 00678c3b  56                   push esi
// 00678c3c  8bcf                 mov ecx, edi
// 00678c3e  ff15c804a400         call dword ptr [0xa404c8]
// 00678c44  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00678c47  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00678c4a  8bc7                 mov eax, edi
// 00678c4c  5f                   pop edi
// 00678c4d  5e                   pop esi
// 00678c4e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00678c52  64890d00000000       mov dword ptr fs:[0], ecx
// 00678c59  83c418               add esp, 0x18
// 00678c5c  c20400               ret 4
// 00678c5f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00678c62  8b16                 mov edx, dword ptr [esi]
// 00678c64  8954240c             mov dword ptr [esp + 0xc], edx
// 00678c68  85c9                 test ecx, ecx
// 00678c6a  7409                 je 0x678c75
// 00678c6c  8b01                 mov eax, dword ptr [ecx]
// 00678c6e  8b5008               mov edx, dword ptr [eax + 8]
// 00678c71  ffd2                 call edx
// 00678c73  eb02                 jmp 0x678c77
// 00678c75  33c0                 xor eax, eax
// 00678c77  89442410             mov dword ptr [esp + 0x10], eax
// 00678c7b  8d4c240c             lea ecx, [esp + 0xc]
// 00678c7f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00678c87  e8e45b0700           call 0x6ee870
// 00678c8c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00678c90  8bf0                 mov esi, eax
// 00678c92  56                   push esi
// 00678c93  8bcf                 mov ecx, edi
// 00678c95  ff15c804a400         call dword ptr [0xa404c8]
// 00678c9b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00678c9f  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00678ca2  89471c               mov dword ptr [edi + 0x1c], eax
// 00678ca5  c744240801000000     mov dword ptr [esp + 8], 1
// 00678cad  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00678cb2  85c9                 test ecx, ecx
// 00678cb4  7408                 je 0x678cbe
// 00678cb6  8b11                 mov edx, dword ptr [ecx]
// 00678cb8  8b02                 mov eax, dword ptr [edx]
// 00678cba  6a01                 push 1
// 00678cbc  ffd0                 call eax
// 00678cbe  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00678cc2  8bc7                 mov eax, edi
// 00678cc4  5f                   pop edi
// 00678cc5  5e                   pop esi
// 00678cc6  64890d00000000       mov dword ptr fs:[0], ecx
// 00678ccd  83c418               add esp, 0x18
// 00678cd0  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00001b@@QBE?AUContentId@2@XZ)

namespace ns_ROCX00001b {
// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

typedef String* (__thiscall *StringCopyProc)(String*, const String&);
extern StringCopyProc stringCopy;

namespace std {
    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::basic_string(
        const basic_string& other)
    {
        stringCopy(this, other);
    }
}

class type_info {
public:
    bool operator==(const type_info&) const;
};

typedef bool (__thiscall *TypeEqualProc)(const type_info*, const type_info&);
extern TypeEqualProc typeEqual;
extern const type_info contentType;

__forceinline bool type_info::operator==(const type_info& other) const
{
    return typeEqual(this, other);
}

struct ContentId {
    String text;
    unsigned int value;
};

struct TypeDescriptor {
    unsigned char prefix[8];
    const type_info* info;
};

struct Holder {
    virtual ~Holder();
    virtual void reserved();
    virtual Holder* clone() const;
};

extern const ContentId& __cdecl extractContentId(Holder* const*);

struct S {
    TypeDescriptor* type;
    Holder* object;

    S(const S&);
    ~S();
    const ContentId& convert() const;
    ContentId f() const;
};

__forceinline S::S(const S& other)
{
    Holder* source = other.object;
    type = other.type;
    Holder* copy = source ? source->clone() : 0;
    object = copy;
}

__forceinline S::~S()
{
    if (object)
        delete object;
}

ContentId S::f() const
{
    if (contentType == *type->info)
        return extractContentId(&object);

    S temporary(*this);
    return temporary.convert();
}
}
