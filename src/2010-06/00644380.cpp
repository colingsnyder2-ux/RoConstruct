// from server: 100% by Yeetserama
// roc 2010-06 00644380  unit: RBX::VAnimationId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00644380
//
// 00644380  6aff                 push -1
// 00644382  68b1949900           push 0x9994b1
// 00644387  64a100000000         mov eax, dword ptr fs:[0]
// 0064438d  50                   push eax
// 0064438e  64892500000000       mov dword ptr fs:[0], esp
// 00644395  83ec0c               sub esp, 0xc
// 00644398  56                   push esi
// 00644399  8bf1                 mov esi, ecx
// 0064439b  c744240400000000     mov dword ptr [esp + 4], 0
// 006443a3  8b06                 mov eax, dword ptr [esi]
// 006443a5  8b4008               mov eax, dword ptr [eax + 8]
// 006443a8  57                   push edi
// 006443a9  50                   push eax
// 006443aa  b9f45dbb00           mov ecx, 0xbb5df4
// 006443af  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 006443b5  84c0                 test al, al
// 006443b7  7436                 je 0x6443ef
// 006443b9  83c604               add esi, 4
// 006443bc  56                   push esi
// 006443bd  e87efeffff           call 0x644240
// 006443c2  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006443c6  83c404               add esp, 4
// 006443c9  8bf0                 mov esi, eax
// 006443cb  56                   push esi
// 006443cc  8bcf                 mov ecx, edi
// 006443ce  ff150ca49e00         call dword ptr [0x9ea40c]
// 006443d4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006443d7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 006443da  8bc7                 mov eax, edi
// 006443dc  5f                   pop edi
// 006443dd  5e                   pop esi
// 006443de  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006443e2  64890d00000000       mov dword ptr fs:[0], ecx
// 006443e9  83c418               add esp, 0x18
// 006443ec  c20400               ret 4
// 006443ef  8b4e04               mov ecx, dword ptr [esi + 4]
// 006443f2  8b16                 mov edx, dword ptr [esi]
// 006443f4  8954240c             mov dword ptr [esp + 0xc], edx
// 006443f8  85c9                 test ecx, ecx
// 006443fa  7409                 je 0x644405
// 006443fc  8b01                 mov eax, dword ptr [ecx]
// 006443fe  8b5008               mov edx, dword ptr [eax + 8]
// 00644401  ffd2                 call edx
// 00644403  eb02                 jmp 0x644407
// 00644405  33c0                 xor eax, eax
// 00644407  89442410             mov dword ptr [esp + 0x10], eax
// 0064440b  8d4c240c             lea ecx, [esp + 0xc]
// 0064440f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00644417  e8145b0700           call 0x6b9f30
// 0064441c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00644420  8bf0                 mov esi, eax
// 00644422  56                   push esi
// 00644423  8bcf                 mov ecx, edi
// 00644425  ff150ca49e00         call dword ptr [0x9ea40c]
// 0064442b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064442f  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00644432  89471c               mov dword ptr [edi + 0x1c], eax
// 00644435  c744240801000000     mov dword ptr [esp + 8], 1
// 0064443d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00644442  85c9                 test ecx, ecx
// 00644444  7408                 je 0x64444e
// 00644446  8b11                 mov edx, dword ptr [ecx]
// 00644448  8b02                 mov eax, dword ptr [edx]
// 0064444a  6a01                 push 1
// 0064444c  ffd0                 call eax
// 0064444e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00644452  8bc7                 mov eax, edi
// 00644454  5f                   pop edi
// 00644455  5e                   pop esi
// 00644456  64890d00000000       mov dword ptr fs:[0], ecx
// 0064445d  83c418               add esp, 0x18
// 00644460  c20400               ret 4
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
