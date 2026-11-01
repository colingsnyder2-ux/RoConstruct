// from server: 100% by Yeetserama
// roc 2010-06 00644d70  unit: RBX::VMeshId::?$TypedPropertyDescriptor  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00644d70
//
// 00644d70  6aff                 push -1
// 00644d72  68b1949900           push 0x9994b1
// 00644d77  64a100000000         mov eax, dword ptr fs:[0]
// 00644d7d  50                   push eax
// 00644d7e  64892500000000       mov dword ptr fs:[0], esp
// 00644d85  83ec0c               sub esp, 0xc
// 00644d88  56                   push esi
// 00644d89  8bf1                 mov esi, ecx
// 00644d8b  c744240400000000     mov dword ptr [esp + 4], 0
// 00644d93  8b06                 mov eax, dword ptr [esi]
// 00644d95  8b4008               mov eax, dword ptr [eax + 8]
// 00644d98  57                   push edi
// 00644d99  50                   push eax
// 00644d9a  b96861bb00           mov ecx, 0xbb6168
// 00644d9f  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 00644da5  84c0                 test al, al
// 00644da7  7436                 je 0x644ddf
// 00644da9  83c604               add esi, 4
// 00644dac  56                   push esi
// 00644dad  e82effffff           call 0x644ce0
// 00644db2  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00644db6  83c404               add esp, 4
// 00644db9  8bf0                 mov esi, eax
// 00644dbb  56                   push esi
// 00644dbc  8bcf                 mov ecx, edi
// 00644dbe  ff150ca49e00         call dword ptr [0x9ea40c]
// 00644dc4  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00644dc7  894f1c               mov dword ptr [edi + 0x1c], ecx
// 00644dca  8bc7                 mov eax, edi
// 00644dcc  5f                   pop edi
// 00644dcd  5e                   pop esi
// 00644dce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00644dd2  64890d00000000       mov dword ptr fs:[0], ecx
// 00644dd9  83c418               add esp, 0x18
// 00644ddc  c20400               ret 4
// 00644ddf  8b4e04               mov ecx, dword ptr [esi + 4]
// 00644de2  8b16                 mov edx, dword ptr [esi]
// 00644de4  8954240c             mov dword ptr [esp + 0xc], edx
// 00644de8  85c9                 test ecx, ecx
// 00644dea  7409                 je 0x644df5
// 00644dec  8b01                 mov eax, dword ptr [ecx]
// 00644dee  8b5008               mov edx, dword ptr [eax + 8]
// 00644df1  ffd2                 call edx
// 00644df3  eb02                 jmp 0x644df7
// 00644df5  33c0                 xor eax, eax
// 00644df7  89442410             mov dword ptr [esp + 0x10], eax
// 00644dfb  8d4c240c             lea ecx, [esp + 0xc]
// 00644dff  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00644e07  e8c44d0700           call 0x6b9bd0
// 00644e0c  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00644e10  8bf0                 mov esi, eax
// 00644e12  56                   push esi
// 00644e13  8bcf                 mov ecx, edi
// 00644e15  ff150ca49e00         call dword ptr [0x9ea40c]
// 00644e1b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00644e1f  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00644e22  89471c               mov dword ptr [edi + 0x1c], eax
// 00644e25  c744240801000000     mov dword ptr [esp + 8], 1
// 00644e2d  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00644e32  85c9                 test ecx, ecx
// 00644e34  7408                 je 0x644e3e
// 00644e36  8b11                 mov edx, dword ptr [ecx]
// 00644e38  8b02                 mov eax, dword ptr [edx]
// 00644e3a  6a01                 push 1
// 00644e3c  ffd0                 call eax
// 00644e3e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00644e42  8bc7                 mov eax, edi
// 00644e44  5f                   pop edi
// 00644e45  5e                   pop esi
// 00644e46  64890d00000000       mov dword ptr fs:[0], ecx
// 00644e4d  83c418               add esp, 0x18
// 00644e50  c20400               ret 4
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
