// from server: 100% by Yeetserama
// roc 2010-06 00624a50  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00624a50
//
// 00624a50  6aff                 push -1
// 00624a52  68b1949900           push 0x9994b1
// 00624a57  64a100000000         mov eax, dword ptr fs:[0]
// 00624a5d  50                   push eax
// 00624a5e  64892500000000       mov dword ptr fs:[0], esp
// 00624a65  83ec0c               sub esp, 0xc
// 00624a68  56                   push esi
// 00624a69  8bf1                 mov esi, ecx
// 00624a6b  c744240400000000     mov dword ptr [esp + 4], 0
// 00624a73  8b06                 mov eax, dword ptr [esi]
// 00624a75  8b4008               mov eax, dword ptr [eax + 8]
// 00624a78  57                   push edi
// 00624a79  50                   push eax
// 00624a7a  b9100abb00           mov ecx, 0xbb0a10
// 00624a7f  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00624a85  84c0                 test al, al
// 00624a87  7436                 je 0x624abf
// 00624a89  83c604               add esi, 4
// 00624a8c  56                   push esi
// 00624a8d  e86eeeffff           call 0x623900
// 00624a92  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00624a96  83c404               add esp, 4
// 00624a99  8bf0                 mov esi, eax
// 00624a9b  56                   push esi
// 00624a9c  8bcf                 mov ecx, edi
// 00624a9e  ff150ca49e00         call dword ptr [0x9ea40c]
// 00624aa4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00624aa7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00624aaa  8bc7                 mov eax, edi
// 00624aac  5f                   pop edi
// 00624aad  5e                   pop esi
// 00624aae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00624ab2  64890d00000000       mov dword ptr fs:[0], ecx
// 00624ab9  83c418               add esp, 0x18
// 00624abc  c20400               ret 4
// 00624abf  8b4e04               mov ecx, dword ptr [esi + 4]
// 00624ac2  8b16                 mov edx, dword ptr [esi]
// 00624ac4  8954240c             mov dword ptr [esp + 0xc], edx
// 00624ac8  85c9                 test ecx, ecx
// 00624aca  7409                 je 0x624ad5
// 00624acc  8b01                 mov eax, dword ptr [ecx]
// 00624ace  8b5008               mov edx, dword ptr [eax + 8]
// 00624ad1  ffd2                 call edx
// 00624ad3  eb02                 jmp 0x624ad7
// 00624ad5  33c0                 xor eax, eax
// 00624ad7  89442410             mov dword ptr [esp + 0x10], eax
// 00624adb  8d4c240c             lea ecx, [esp + 0xc]
// 00624adf  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00624ae7  e8b4f3ffff           call 0x623ea0
// 00624aec  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00624af0  8bf0                 mov esi, eax
// 00624af2  56                   push esi
// 00624af3  8bcf                 mov ecx, edi
// 00624af5  ff150ca49e00         call dword ptr [0x9ea40c]
// 00624afb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00624aff  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00624b02  89471c               mov dword ptr [edi + 0x1c], eax
// 00624b05  c744240801000000     mov dword ptr [esp + 8], 1
// 00624b0d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00624b12  85c9                 test ecx, ecx
// 00624b14  7408                 je 0x624b1e
// 00624b16  8b11                 mov edx, dword ptr [ecx]
// 00624b18  8b02                 mov eax, dword ptr [edx]
// 00624b1a  6a01                 push 1
// 00624b1c  ffd0                 call eax
// 00624b1e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00624b22  8bc7                 mov eax, edi
// 00624b24  5f                   pop edi
// 00624b25  5e                   pop esi
// 00624b26  64890d00000000       mov dword ptr fs:[0], ecx
// 00624b2d  83c418               add esp, 0x18
// 00624b30  c20400               ret 4
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
