// from server: 100% by EspClaude
// roc 2009-06 00625a40  unit: RBX::BackpackItem  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00625a40
//
// 00625a40  6aff                 push -1
// 00625a42  6831808600           push 0x868031
// 00625a47  64a100000000         mov eax, dword ptr fs:[0]
// 00625a4d  50                   push eax
// 00625a4e  64892500000000       mov dword ptr fs:[0], esp
// 00625a55  83ec0c               sub esp, 0xc
// 00625a58  56                   push esi
// 00625a59  8bf1                 mov esi, ecx
// 00625a5b  c744240400000000     mov dword ptr [esp + 4], 0
// 00625a63  8b06                 mov eax, dword ptr [esi]
// 00625a65  8b4008               mov eax, dword ptr [eax + 8]
// 00625a68  57                   push edi
// 00625a69  50                   push eax
// 00625a6a  b998a6a000           mov ecx, 0xa0a698
// 00625a6f  ff15a4e98900         call dword ptr [0x89e9a4]
// 00625a75  84c0                 test al, al
// 00625a77  7436                 je 0x625aaf
// 00625a79  83c604               add esi, 4
// 00625a7c  56                   push esi
// 00625a7d  e86ef9ffff           call 0x6253f0
// 00625a82  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00625a86  83c404               add esp, 4
// 00625a89  8bf0                 mov esi, eax
// 00625a8b  56                   push esi
// 00625a8c  8bcf                 mov ecx, edi
// 00625a8e  ff15b8e48900         call dword ptr [0x89e4b8]
// 00625a94  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00625a97  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00625a9a  8bc7                 mov eax, edi
// 00625a9c  5f                   pop edi
// 00625a9d  5e                   pop esi
// 00625a9e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00625aa2  64890d00000000       mov dword ptr fs:[0], ecx
// 00625aa9  83c418               add esp, 0x18
// 00625aac  c20400               ret 4
// 00625aaf  8b4e04               mov ecx, dword ptr [esi + 4]
// 00625ab2  8b16                 mov edx, dword ptr [esi]
// 00625ab4  8954240c             mov dword ptr [esp + 0xc], edx
// 00625ab8  85c9                 test ecx, ecx
// 00625aba  7409                 je 0x625ac5
// 00625abc  8b01                 mov eax, dword ptr [ecx]
// 00625abe  8b5008               mov edx, dword ptr [eax + 8]
// 00625ac1  ffd2                 call edx
// 00625ac3  eb02                 jmp 0x625ac7
// 00625ac5  33c0                 xor eax, eax
// 00625ac7  89442410             mov dword ptr [esp + 0x10], eax
// 00625acb  8d4c240c             lea ecx, [esp + 0xc]
// 00625acf  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00625ad7  e8b44d0200           call 0x64a890
// 00625adc  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00625ae0  8bf0                 mov esi, eax
// 00625ae2  56                   push esi
// 00625ae3  8bcf                 mov ecx, edi
// 00625ae5  ff15b8e48900         call dword ptr [0x89e4b8]
// 00625aeb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00625aef  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00625af2  89471c               mov dword ptr [edi + 0x1c], eax
// 00625af5  c744240801000000     mov dword ptr [esp + 8], 1
// 00625afd  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00625b02  85c9                 test ecx, ecx
// 00625b04  7408                 je 0x625b0e
// 00625b06  8b11                 mov edx, dword ptr [ecx]
// 00625b08  8b02                 mov eax, dword ptr [edx]
// 00625b0a  6a01                 push 1
// 00625b0c  ffd0                 call eax
// 00625b0e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00625b12  8bc7                 mov eax, edi
// 00625b14  5f                   pop edi
// 00625b15  5e                   pop esi
// 00625b16  64890d00000000       mov dword ptr fs:[0], ecx
// 00625b1d  83c418               add esp, 0x18
// 00625b20  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000008@@QBE?AUContentId@2@XZ)

namespace ns_ROCX000008 {
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
