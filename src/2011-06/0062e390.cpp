// from server: 100% by Yeetserama
// roc 2011-06 0062e390  unit: RBX::VTextureId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0062e390
//
// 0062e390  6aff                 push -1
// 0062e392  6811b59e00           push 0x9eb511
// 0062e397  64a100000000         mov eax, dword ptr fs:[0]
// 0062e39d  50                   push eax
// 0062e39e  64892500000000       mov dword ptr fs:[0], esp
// 0062e3a5  83ec0c               sub esp, 0xc
// 0062e3a8  56                   push esi
// 0062e3a9  8bf1                 mov esi, ecx
// 0062e3ab  c744240400000000     mov dword ptr [esp + 4], 0
// 0062e3b3  8b06                 mov eax, dword ptr [esi]
// 0062e3b5  8b4008               mov eax, dword ptr [eax + 8]
// 0062e3b8  57                   push edi
// 0062e3b9  50                   push eax
// 0062e3ba  b9c0dec400           mov ecx, 0xc4dec0
// 0062e3bf  ff15500aa400         call dword ptr [0xa40a50]
// 0062e3c5  84c0                 test al, al
// 0062e3c7  7436                 je 0x62e3ff
// 0062e3c9  83c604               add esi, 4
// 0062e3cc  56                   push esi
// 0062e3cd  e89efaffff           call 0x62de70
// 0062e3d2  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0062e3d6  83c404               add esp, 4
// 0062e3d9  8bf0                 mov esi, eax
// 0062e3db  56                   push esi
// 0062e3dc  8bcf                 mov ecx, edi
// 0062e3de  ff15c804a400         call dword ptr [0xa404c8]
// 0062e3e4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0062e3e7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0062e3ea  8bc7                 mov eax, edi
// 0062e3ec  5f                   pop edi
// 0062e3ed  5e                   pop esi
// 0062e3ee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0062e3f2  64890d00000000       mov dword ptr fs:[0], ecx
// 0062e3f9  83c418               add esp, 0x18
// 0062e3fc  c20400               ret 4
// 0062e3ff  8b4e04               mov ecx, dword ptr [esi + 4]
// 0062e402  8b16                 mov edx, dword ptr [esi]
// 0062e404  8954240c             mov dword ptr [esp + 0xc], edx
// 0062e408  85c9                 test ecx, ecx
// 0062e40a  7409                 je 0x62e415
// 0062e40c  8b01                 mov eax, dword ptr [ecx]
// 0062e40e  8b5008               mov edx, dword ptr [eax + 8]
// 0062e411  ffd2                 call edx
// 0062e413  eb02                 jmp 0x62e417
// 0062e415  33c0                 xor eax, eax
// 0062e417  89442410             mov dword ptr [esp + 0x10], eax
// 0062e41b  8d4c240c             lea ecx, [esp + 0xc]
// 0062e41f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0062e427  e8c4470200           call 0x652bf0
// 0062e42c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0062e430  8bf0                 mov esi, eax
// 0062e432  56                   push esi
// 0062e433  8bcf                 mov ecx, edi
// 0062e435  ff15c804a400         call dword ptr [0xa404c8]
// 0062e43b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0062e43f  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0062e442  89471c               mov dword ptr [edi + 0x1c], eax
// 0062e445  c744240801000000     mov dword ptr [esp + 8], 1
// 0062e44d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0062e452  85c9                 test ecx, ecx
// 0062e454  7408                 je 0x62e45e
// 0062e456  8b11                 mov edx, dword ptr [ecx]
// 0062e458  8b02                 mov eax, dword ptr [edx]
// 0062e45a  6a01                 push 1
// 0062e45c  ffd0                 call eax
// 0062e45e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0062e462  8bc7                 mov eax, edi
// 0062e464  5f                   pop edi
// 0062e465  5e                   pop esi
// 0062e466  64890d00000000       mov dword ptr fs:[0], ecx
// 0062e46d  83c418               add esp, 0x18
// 0062e470  c20400               ret 4
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
