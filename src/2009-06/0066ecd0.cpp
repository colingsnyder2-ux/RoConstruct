// from server: 100% by EspClaude
// roc 2009-06 0066ecd0  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0066ecd0
//
// 0066ecd0  6aff                 push -1
// 0066ecd2  6831808600           push 0x868031
// 0066ecd7  64a100000000         mov eax, dword ptr fs:[0]
// 0066ecdd  50                   push eax
// 0066ecde  64892500000000       mov dword ptr fs:[0], esp
// 0066ece5  83ec0c               sub esp, 0xc
// 0066ece8  56                   push esi
// 0066ece9  8bf1                 mov esi, ecx
// 0066eceb  c744240400000000     mov dword ptr [esp + 4], 0
// 0066ecf3  8b06                 mov eax, dword ptr [esi]
// 0066ecf5  8b4008               mov eax, dword ptr [eax + 8]
// 0066ecf8  57                   push edi
// 0066ecf9  50                   push eax
// 0066ecfa  b98064a100           mov ecx, 0xa16480
// 0066ecff  ff15a4e98900         call dword ptr [0x89e9a4]
// 0066ed05  84c0                 test al, al
// 0066ed07  7436                 je 0x66ed3f
// 0066ed09  83c604               add esi, 4
// 0066ed0c  56                   push esi
// 0066ed0d  e8eefdffff           call 0x66eb00
// 0066ed12  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0066ed16  83c404               add esp, 4
// 0066ed19  8bf0                 mov esi, eax
// 0066ed1b  56                   push esi
// 0066ed1c  8bcf                 mov ecx, edi
// 0066ed1e  ff15b8e48900         call dword ptr [0x89e4b8]
// 0066ed24  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0066ed27  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0066ed2a  8bc7                 mov eax, edi
// 0066ed2c  5f                   pop edi
// 0066ed2d  5e                   pop esi
// 0066ed2e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066ed32  64890d00000000       mov dword ptr fs:[0], ecx
// 0066ed39  83c418               add esp, 0x18
// 0066ed3c  c20400               ret 4
// 0066ed3f  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066ed42  8b16                 mov edx, dword ptr [esi]
// 0066ed44  8954240c             mov dword ptr [esp + 0xc], edx
// 0066ed48  85c9                 test ecx, ecx
// 0066ed4a  7409                 je 0x66ed55
// 0066ed4c  8b01                 mov eax, dword ptr [ecx]
// 0066ed4e  8b5008               mov edx, dword ptr [eax + 8]
// 0066ed51  ffd2                 call edx
// 0066ed53  eb02                 jmp 0x66ed57
// 0066ed55  33c0                 xor eax, eax
// 0066ed57  89442410             mov dword ptr [esp + 0x10], eax
// 0066ed5b  8d4c240c             lea ecx, [esp + 0xc]
// 0066ed5f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 0066ed67  e884630200           call 0x6950f0
// 0066ed6c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0066ed70  8bf0                 mov esi, eax
// 0066ed72  56                   push esi
// 0066ed73  8bcf                 mov ecx, edi
// 0066ed75  ff15b8e48900         call dword ptr [0x89e4b8]
// 0066ed7b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066ed7f  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0066ed82  89471c               mov dword ptr [edi + 0x1c], eax
// 0066ed85  c744240801000000     mov dword ptr [esp + 8], 1
// 0066ed8d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0066ed92  85c9                 test ecx, ecx
// 0066ed94  7408                 je 0x66ed9e
// 0066ed96  8b11                 mov edx, dword ptr [ecx]
// 0066ed98  8b02                 mov eax, dword ptr [edx]
// 0066ed9a  6a01                 push 1
// 0066ed9c  ffd0                 call eax
// 0066ed9e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0066eda2  8bc7                 mov eax, edi
// 0066eda4  5f                   pop edi
// 0066eda5  5e                   pop esi
// 0066eda6  64890d00000000       mov dword ptr fs:[0], ecx
// 0066edad  83c418               add esp, 0x18
// 0066edb0  c20400               ret 4
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
