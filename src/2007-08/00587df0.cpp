// from server: 100% by colin
// roc 2007-08 00587df0  unit: RBX::VSoundChannel::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587df0
//
// 00587df0  64a100000000         mov eax, dword ptr fs:[0]
// 00587df6  6aff                 push -1
// 00587df8  68985f7500           push 0x755f98
// 00587dfd  50                   push eax
// 00587dfe  64892500000000       mov dword ptr fs:[0], esp
// 00587e05  56                   push esi
// 00587e06  57                   push edi
// 00587e07  8bf1                 mov esi, ecx
// 00587e09  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00587e0d  33c0                 xor eax, eax
// 00587e0f  8d54241c             lea edx, [esp + 0x1c]
// 00587e13  894e04               mov dword ptr [esi + 4], ecx
// 00587e16  8d7e0c               lea edi, [esi + 0xc]
// 00587e19  52                   push edx
// 00587e1a  8bcf                 mov ecx, edi
// 00587e1c  89442414             mov dword ptr [esp + 0x14], eax
// 00587e20  8906                 mov dword ptr [esi], eax
// 00587e22  894608               mov dword ptr [esi + 8], eax
// 00587e25  ff159ce67700         call dword ptr [0x77e69c]
// 00587e2b  8b442438             mov eax, dword ptr [esp + 0x38]
// 00587e2f  8a4c243c             mov cl, byte ptr [esp + 0x3c]
// 00587e33  89471c               mov dword ptr [edi + 0x1c], eax
// 00587e36  884e2c               mov byte ptr [esi + 0x2c], cl
// 00587e39  8d4c241c             lea ecx, [esp + 0x1c]
// 00587e3d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00587e45  ff15ace67700         call dword ptr [0x77e6ac]
// 00587e4b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00587e4f  5f                   pop edi
// 00587e50  8bc6                 mov eax, esi
// 00587e52  64890d00000000       mov dword ptr fs:[0], ecx
// 00587e59  5e                   pop esi
// 00587e5a  83c40c               add esp, 0xc
// 00587e5d  c22800               ret 0x28
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