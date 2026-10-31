// from server: 100% by EspClaude
// roc 2009-06 006526b0  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006526b0
//
// 006526b0  6aff                 push -1
// 006526b2  6801b48600           push 0x86b401
// 006526b7  64a100000000         mov eax, dword ptr fs:[0]
// 006526bd  50                   push eax
// 006526be  64892500000000       mov dword ptr fs:[0], esp
// 006526c5  83ec20               sub esp, 0x20
// 006526c8  56                   push esi
// 006526c9  8bf1                 mov esi, ecx
// 006526cb  685c898b00           push 0x8b895c
// 006526d0  8d4c240c             lea ecx, [esp + 0xc]
// 006526d4  89742408             mov dword ptr [esp + 8], esi
// 006526d8  ff15b4e48900         call dword ptr [0x89e4b4]
// 006526de  8b442434             mov eax, dword ptr [esp + 0x34]
// 006526e2  50                   push eax
// 006526e3  83ec1c               sub esp, 0x1c
// 006526e6  8d542428             lea edx, [esp + 0x28]
// 006526ea  8bcc                 mov ecx, esp
// 006526ec  89642454             mov dword ptr [esp + 0x54], esp
// 006526f0  52                   push edx
// 006526f1  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006526f9  ff15b8e48900         call dword ptr [0x89e4b8]
// 006526ff  8bce                 mov ecx, esi
// 00652701  e81aaafbff           call 0x60d120
// 00652706  d90508a88c00         fld dword ptr [0x8ca808]
// 0065270c  d95e24               fstp dword ptr [esi + 0x24]
// 0065270f  c706a0fb8d00         mov dword ptr [esi], 0x8dfba0
// 00652715  8d4c2408             lea ecx, [esp + 8]
// 00652719  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0065271e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00652724  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00652728  c706d0fb8d00         mov dword ptr [esi], 0x8dfbd0
// 0065272e  8bc6                 mov eax, esi
// 00652730  64890d00000000       mov dword ptr fs:[0], ecx
// 00652737  5e                   pop esi
// 00652738  83c42c               add esp, 0x2c
// 0065273b  c20400               ret 4
// copied from an identical function in another client (function ??0S@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class C, class T, class A>
class basic_string {
    unsigned char storage[28];
public:
    basic_string(const C*);
    __declspec(dllimport) basic_string(const basic_string&);
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

extern void (__thiscall *constructString)(void*, const char*);
extern void (__thiscall *copyString)(void*, const void*);
extern void (__thiscall *destroyString)(void*);

template<class C, class T, class A>
inline std::basic_string<C, T, A>::basic_string(const C* text)
{
    constructString(this, text);
}



template<class C, class T, class A>
inline std::basic_string<C, T, A>::~basic_string()
{
    destroyString(this);
}

extern const float initialValue;

struct Root {
    unsigned char storage[32];
    Root(std::string, int);
    virtual ~Root();
};

struct __declspec(novtable) ValueBase : Root {
    float value;
    ValueBase(const std::string&, int);
};

struct Base : ValueBase {
    Base(const std::string&, int);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

inline ValueBase::ValueBase(const std::string& name, int argument)
    : Root(name, argument), value(initialValue)
{
}

inline Base::Base(const std::string& name, int argument)
    : ValueBase(name, argument)
{
}

S::S(int argument)
    : Base(std::string("SelectionUpBrick"), argument)
{
}