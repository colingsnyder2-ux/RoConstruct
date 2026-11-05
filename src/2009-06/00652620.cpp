// from server: 100% by EspClaude
// roc 2009-06 00652620  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00652620
//
// 00652620  6aff                 push -1
// 00652622  6801b48600           push 0x86b401
// 00652627  64a100000000         mov eax, dword ptr fs:[0]
// 0065262d  50                   push eax
// 0065262e  64892500000000       mov dword ptr fs:[0], esp
// 00652635  83ec20               sub esp, 0x20
// 00652638  56                   push esi
// 00652639  8bf1                 mov esi, ecx
// 0065263b  6848898b00           push 0x8b8948
// 00652640  8d4c240c             lea ecx, [esp + 0xc]
// 00652644  89742408             mov dword ptr [esp + 8], esi
// 00652648  ff15b4e48900         call dword ptr [0x89e4b4]
// 0065264e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00652652  50                   push eax
// 00652653  83ec1c               sub esp, 0x1c
// 00652656  8d542428             lea edx, [esp + 0x28]
// 0065265a  8bcc                 mov ecx, esp
// 0065265c  89642454             mov dword ptr [esp + 0x54], esp
// 00652660  52                   push edx
// 00652661  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00652669  ff15b8e48900         call dword ptr [0x89e4b8]
// 0065266f  8bce                 mov ecx, esi
// 00652671  e8aaaafbff           call 0x60d120
// 00652676  d905e4a38c00         fld dword ptr [0x8ca3e4]
// 0065267c  d95e24               fstp dword ptr [esi + 0x24]
// 0065267f  c706a0fb8d00         mov dword ptr [esi], 0x8dfba0
// 00652685  8d4c2408             lea ecx, [esp + 8]
// 00652689  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0065268e  ff15c4e48900         call dword ptr [0x89e4c4]
// 00652694  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00652698  c706b8fb8d00         mov dword ptr [esi], 0x8dfbb8
// 0065269e  8bc6                 mov eax, esi
// 006526a0  64890d00000000       mov dword ptr fs:[0], ecx
// 006526a7  5e                   pop esi
// 006526a8  83c42c               add esp, 0x2c
// 006526ab  c20400               ret 4
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
    : Base(std::string("SelectionUpPlate"), argument)
{
}