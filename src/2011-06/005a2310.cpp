// from server: 100% by Yeetserama
// roc 2011-06 005a2310  unit: RBX::W4SoundType::?$EnumDesc  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005a2310
//
// 005a2310  6aff                 push -1
// 005a2312  6811b59e00           push 0x9eb511
// 005a2317  64a100000000         mov eax, dword ptr fs:[0]
// 005a231d  50                   push eax
// 005a231e  64892500000000       mov dword ptr fs:[0], esp
// 005a2325  83ec0c               sub esp, 0xc
// 005a2328  56                   push esi
// 005a2329  8bf1                 mov esi, ecx
// 005a232b  c744240400000000     mov dword ptr [esp + 4], 0
// 005a2333  8b06                 mov eax, dword ptr [esi]
// 005a2335  8b4008               mov eax, dword ptr [eax + 8]
// 005a2338  57                   push edi
// 005a2339  50                   push eax
// 005a233a  b9e07bc300           mov ecx, 0xc37be0
// 005a233f  ff15500aa400         call dword ptr [0xa40a50]
// 005a2345  84c0                 test al, al
// 005a2347  7436                 je 0x5a237f
// 005a2349  83c604               add esi, 4
// 005a234c  56                   push esi
// 005a234d  e80eeaffff           call 0x5a0d60
// 005a2352  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005a2356  83c404               add esp, 4
// 005a2359  8bf0                 mov esi, eax
// 005a235b  56                   push esi
// 005a235c  8bcf                 mov ecx, edi
// 005a235e  ff15c804a400         call dword ptr [0xa404c8]
// 005a2364  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005a2367  894f1c               mov dword ptr [edi + 0x1c], ecx
// 005a236a  8bc7                 mov eax, edi
// 005a236c  5f                   pop edi
// 005a236d  5e                   pop esi
// 005a236e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005a2372  64890d00000000       mov dword ptr fs:[0], ecx
// 005a2379  83c418               add esp, 0x18
// 005a237c  c20400               ret 4
// 005a237f  8b4e04               mov ecx, dword ptr [esi + 4]
// 005a2382  8b16                 mov edx, dword ptr [esi]
// 005a2384  8954240c             mov dword ptr [esp + 0xc], edx
// 005a2388  85c9                 test ecx, ecx
// 005a238a  7409                 je 0x5a2395
// 005a238c  8b01                 mov eax, dword ptr [ecx]
// 005a238e  8b5008               mov edx, dword ptr [eax + 8]
// 005a2391  ffd2                 call edx
// 005a2393  eb02                 jmp 0x5a2397
// 005a2395  33c0                 xor eax, eax
// 005a2397  89442410             mov dword ptr [esp + 0x10], eax
// 005a239b  8d4c240c             lea ecx, [esp + 0xc]
// 005a239f  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 005a23a7  e8c4efffff           call 0x5a1370
// 005a23ac  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005a23b0  8bf0                 mov esi, eax
// 005a23b2  56                   push esi
// 005a23b3  8bcf                 mov ecx, edi
// 005a23b5  ff15c804a400         call dword ptr [0xa404c8]
// 005a23bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005a23bf  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005a23c2  89471c               mov dword ptr [edi + 0x1c], eax
// 005a23c5  c744240801000000     mov dword ptr [esp + 8], 1
// 005a23cd  c644241c00           mov byte ptr [esp + 0x1c], 0
// 005a23d2  85c9                 test ecx, ecx
// 005a23d4  7408                 je 0x5a23de
// 005a23d6  8b11                 mov edx, dword ptr [ecx]
// 005a23d8  8b02                 mov eax, dword ptr [edx]
// 005a23da  6a01                 push 1
// 005a23dc  ffd0                 call eax
// 005a23de  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005a23e2  8bc7                 mov eax, edi
// 005a23e4  5f                   pop edi
// 005a23e5  5e                   pop esi
// 005a23e6  64890d00000000       mov dword ptr fs:[0], ecx
// 005a23ed  83c418               add esp, 0x18
// 005a23f0  c20400               ret 4
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
