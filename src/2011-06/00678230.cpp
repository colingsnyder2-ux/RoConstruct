// from server: 100% by Yeetserama
// roc 2011-06 00678230  unit: RBX::VAnimationId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00678230
//
// 00678230  6aff                 push -1
// 00678232  6811b59e00           push 0x9eb511
// 00678237  64a100000000         mov eax, dword ptr fs:[0]
// 0067823d  50                   push eax
// 0067823e  64892500000000       mov dword ptr fs:[0], esp
// 00678245  83ec0c               sub esp, 0xc
// 00678248  56                   push esi
// 00678249  8bf1                 mov esi, ecx
// 0067824b  c744240400000000     mov dword ptr [esp + 4], 0
// 00678253  8b06                 mov eax, dword ptr [esi]
// 00678255  8b4008               mov eax, dword ptr [eax + 8]
// 00678258  57                   push edi
// 00678259  50                   push eax
// 0067825a  b9bca6c500           mov ecx, 0xc5a6bc
// 0067825f  ff15500aa400         call dword ptr [0xa40a50]
// 00678265  84c0                 test al, al
// 00678267  7436                 je 0x67829f
// 00678269  83c604               add esi, 4
// 0067826c  56                   push esi
// 0067826d  e87efeffff           call 0x6780f0
// 00678272  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00678276  83c404               add esp, 4
// 00678279  8bf0                 mov esi, eax
// 0067827b  56                   push esi
// 0067827c  8bcf                 mov ecx, edi
// 0067827e  ff15c804a400         call dword ptr [0xa404c8]
// 00678284  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00678287  894f1c               mov dword ptr [edi + 0x1c], ecx
// 0067828a  8bc7                 mov eax, edi
// 0067828c  5f                   pop edi
// 0067828d  5e                   pop esi
// 0067828e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00678292  64890d00000000       mov dword ptr fs:[0], ecx
// 00678299  83c418               add esp, 0x18
// 0067829c  c20400               ret 4
// 0067829f  8b4e04               mov ecx, dword ptr [esi + 4]
// 006782a2  8b16                 mov edx, dword ptr [esi]
// 006782a4  8954240c             mov dword ptr [esp + 0xc], edx
// 006782a8  85c9                 test ecx, ecx
// 006782aa  7409                 je 0x6782b5
// 006782ac  8b01                 mov eax, dword ptr [ecx]
// 006782ae  8b5008               mov edx, dword ptr [eax + 8]
// 006782b1  ffd2                 call edx
// 006782b3  eb02                 jmp 0x6782b7
// 006782b5  33c0                 xor eax, eax
// 006782b7  89442410             mov dword ptr [esp + 0x10], eax
// 006782bb  8d4c240c             lea ecx, [esp + 0xc]
// 006782bf  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 006782c7  e894690700           call 0x6eec60
// 006782cc  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006782d0  8bf0                 mov esi, eax
// 006782d2  56                   push esi
// 006782d3  8bcf                 mov ecx, edi
// 006782d5  ff15c804a400         call dword ptr [0xa404c8]
// 006782db  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006782df  8b461c               mov eax, dword ptr [esi + 0x1c]
// 006782e2  89471c               mov dword ptr [edi + 0x1c], eax
// 006782e5  c744240801000000     mov dword ptr [esp + 8], 1
// 006782ed  c644241c00           mov byte ptr [esp + 0x1c], 0
// 006782f2  85c9                 test ecx, ecx
// 006782f4  7408                 je 0x6782fe
// 006782f6  8b11                 mov edx, dword ptr [ecx]
// 006782f8  8b02                 mov eax, dword ptr [edx]
// 006782fa  6a01                 push 1
// 006782fc  ffd0                 call eax
// 006782fe  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00678302  8bc7                 mov eax, edi
// 00678304  5f                   pop edi
// 00678305  5e                   pop esi
// 00678306  64890d00000000       mov dword ptr fs:[0], ecx
// 0067830d  83c418               add esp, 0x18
// 00678310  c20400               ret 4
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
