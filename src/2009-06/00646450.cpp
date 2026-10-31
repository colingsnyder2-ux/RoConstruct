// from server: 100% by EspClaude
// roc 2009-06 00646450  unit: RBX::Soundscape::SoundService  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00646450
//
// 00646450  6aff                 push -1
// 00646452  6831808600           push 0x868031
// 00646457  64a100000000         mov eax, dword ptr fs:[0]
// 0064645d  50                   push eax
// 0064645e  64892500000000       mov dword ptr fs:[0], esp
// 00646465  83ec0c               sub esp, 0xc
// 00646468  56                   push esi
// 00646469  8bf1                 mov esi, ecx
// 0064646b  c744240400000000     mov dword ptr [esp + 4], 0
// 00646473  8b06                 mov eax, dword ptr [esi]
// 00646475  8b4008               mov eax, dword ptr [eax + 8]
// 00646478  57                   push edi
// 00646479  50                   push eax
// 0064647a  b980daa000           mov ecx, 0xa0da80
// 0064647f  ff15a4e98900         call dword ptr [0x89e9a4]
// 00646485  84c0                 test al, al
// 00646487  7436                 je 0x6464bf
// 00646489  83c604               add esi, 4
// 0064648c  56                   push esi
// 0064648d  e8def1ffff           call 0x645670
// 00646492  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00646496  83c404               add esp, 4
// 00646499  8bf0                 mov esi, eax
// 0064649b  56                   push esi
// 0064649c  8bcf                 mov ecx, edi
// 0064649e  ff15b8e48900         call dword ptr [0x89e4b8]
// 006464a4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 006464a7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 006464aa  8bc7                 mov eax, edi
// 006464ac  5f                   pop edi
// 006464ad  5e                   pop esi
// 006464ae  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006464b2  64890d00000000       mov dword ptr fs:[0], ecx
// 006464b9  83c418               add esp, 0x18
// 006464bc  c20400               ret 4
// 006464bf  8b4e04               mov ecx, dword ptr [esi + 4]
// 006464c2  8b16                 mov edx, dword ptr [esi]
// 006464c4  8954240c             mov dword ptr [esp + 0xc], edx
// 006464c8  85c9                 test ecx, ecx
// 006464ca  7409                 je 0x6464d5
// 006464cc  8b01                 mov eax, dword ptr [ecx]
// 006464ce  8b5008               mov edx, dword ptr [eax + 8]
// 006464d1  ffd2                 call edx
// 006464d3  eb02                 jmp 0x6464d7
// 006464d5  33c0                 xor eax, eax
// 006464d7  89442410             mov dword ptr [esp + 0x10], eax
// 006464db  8d4c240c             lea ecx, [esp + 0xc]
// 006464df  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 006464e7  e8c4f4ffff           call 0x6459b0
// 006464ec  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006464f0  8bf0                 mov esi, eax
// 006464f2  56                   push esi
// 006464f3  8bcf                 mov ecx, edi
// 006464f5  ff15b8e48900         call dword ptr [0x89e4b8]
// 006464fb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006464ff  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00646502  89471c               mov dword ptr [edi + 0x1c], eax
// 00646505  c744240801000000     mov dword ptr [esp + 8], 1
// 0064650d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00646512  85c9                 test ecx, ecx
// 00646514  7408                 je 0x64651e
// 00646516  8b11                 mov edx, dword ptr [ecx]
// 00646518  8b02                 mov eax, dword ptr [edx]
// 0064651a  6a01                 push 1
// 0064651c  ffd0                 call eax
// 0064651e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00646522  8bc7                 mov eax, edi
// 00646524  5f                   pop edi
// 00646525  5e                   pop esi
// 00646526  64890d00000000       mov dword ptr fs:[0], ecx
// 0064652d  83c418               add esp, 0x18
// 00646530  c20400               ret 4
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
