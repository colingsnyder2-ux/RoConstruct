// roc 2012-06 00692a40  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00692a40
//
// 00692a40  64a100000000         mov eax, dword ptr fs:[0]
// 00692a46  6aff                 push -1
// 00692a48  68a869ab00           push 0xab69a8
// 00692a4d  50                   push eax
// 00692a4e  64892500000000       mov dword ptr fs:[0], esp
// 00692a55  56                   push esi
// 00692a56  57                   push edi
// 00692a57  8bf1                 mov esi, ecx
// 00692a59  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00692a5d  33c0                 xor eax, eax
// 00692a5f  8d54241c             lea edx, [esp + 0x1c]
// 00692a63  894e04               mov dword ptr [esi + 4], ecx
// 00692a66  8d7e0c               lea edi, [esi + 0xc]
// 00692a69  52                   push edx
// 00692a6a  8bcf                 mov ecx, edi
// 00692a6c  89442414             mov dword ptr [esp + 0x14], eax
// 00692a70  8906                 mov dword ptr [esi], eax
// 00692a72  894608               mov dword ptr [esi + 8], eax
// 00692a75  ff154426b200         call dword ptr [0xb22644]
// 00692a7b  8b442438             mov eax, dword ptr [esp + 0x38]
// 00692a7f  8a4c243c             mov cl, byte ptr [esp + 0x3c]
// 00692a83  89471c               mov dword ptr [edi + 0x1c], eax
// 00692a86  884e2c               mov byte ptr [esi + 0x2c], cl
// 00692a89  8d4c241c             lea ecx, [esp + 0x1c]
// 00692a8d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00692a95  ff153c26b200         call dword ptr [0xb2263c]
// 00692a9b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00692a9f  5f                   pop edi
// 00692aa0  8bc6                 mov eax, esi
// 00692aa2  64890d00000000       mov dword ptr fs:[0], ecx
// 00692aa9  5e                   pop esi
// 00692aaa  83c40c               add esp, 0xc
// 00692aad  c22800               ret 0x28
// copied from an identical function in another client (function ??0FactoryProduct@@QAE@PAXV?$basic_string@DU?$char_traits@D@std@@U?$allocator@D@2@@std@@H_N@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace std
{
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string
    {
        char storage[28];

    public:
        basic_string(const basic_string&);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern String* (__thiscall *stringCopy)(String*, const String&);
extern void (__thiscall *stringDestroy)(String*);

namespace std
{
    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(
        const basic_string& other)
    {
        stringCopy(this, other);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string()
    {
        stringDestroy(this);
    }
}

struct NamedValue
{
    String name;
    int value;

    NamedValue(const String& text, int number);
};

inline NamedValue::NamedValue(const String& text, int number)
    : name(text), value(number)
{
}

struct FactoryProduct
{
    int field0;
    void* field4;
    int field8;
    NamedValue named;
    bool flag;

    FactoryProduct(void* arg, String text, int number, bool enabled);
};

FactoryProduct::FactoryProduct(void* arg, String text, int number, bool enabled)
    : field0(0),
      field4(arg),
      field8(0),
      named(text, number),
      flag(enabled)
{
}