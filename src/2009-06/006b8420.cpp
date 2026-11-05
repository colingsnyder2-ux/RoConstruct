// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00619de0  unit: RBX::ModelSetFrontTool  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00619de0
//
// 00619de0  6aff                 push -1
// 00619de2  6893ab7d00           push 0x7dab93
// 00619de7  64a100000000         mov eax, dword ptr fs:[0]
// 00619ded  50                   push eax
// 00619dee  64892500000000       mov dword ptr fs:[0], esp
// 00619df5  51                   push ecx
// 00619df6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00619dfa  56                   push esi
// 00619dfb  8bf1                 mov esi, ecx
// 00619dfd  50                   push eax
// 00619dfe  89742408             mov dword ptr [esp + 8], esi
// 00619e02  e8e9bbffff           call 0x6159f0
// 00619e07  33c0                 xor eax, eax
// 00619e09  c70604418400         mov dword ptr [esi], 0x844104
// 00619e0f  c74604ec408400       mov dword ptr [esi + 4], 0x8440ec
// 00619e16  89461c               mov dword ptr [esi + 0x1c], eax
// 00619e19  89442410             mov dword ptr [esp + 0x10], eax
// 00619e1d  894620               mov dword ptr [esi + 0x20], eax
// 00619e20  8d4e2c               lea ecx, [esi + 0x2c]
// 00619e23  c644241001           mov byte ptr [esp + 0x10], 1
// 00619e28  894624               mov dword ptr [esi + 0x24], eax
// 00619e2b  ff1560248000         call dword ptr [0x802460]
// 00619e31  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00619e35  8bc6                 mov eax, esi
// 00619e37  5e                   pop esi
// 00619e38  64890d00000000       mov dword ptr fs:[0], ecx
// 00619e3f  83c410               add esp, 0x10
// 00619e42  c20400               ret 4

extern void (__thiscall *stringConstruct)(void*);

namespace std {
template<class T> struct char_traits {};
template<class T> class allocator {};
template<class C, class T, class A> class basic_string {
    char storage[28];
public:
    basic_string();
    ~basic_string();
};

template<class C, class T, class A>
inline basic_string<C, T, A>::basic_string()
{
    stringConstruct(this);
}
}

extern int primaryTable[];
extern int secondaryTable[];

struct Base {
    int storage[7];
    int f(int);
    Base(int);
    ~Base();
};

inline Base::Base(int a)
{
    f(a);
    storage[0] = (int)primaryTable;
    storage[1] = (int)secondaryTable;
    ((int*)this)[7] = 0;
}

struct Pair {
    int first;
    int second;
    Pair(void*);
    ~Pair();
};

inline Pair::Pair(void*)
{
    second = 0;
}

struct S : Base {
    Pair pair;
    int value;
    int unused;
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > text;
    S(int);
};

S::S(int a) : Base(a), pair(this), value(0), text()
{
}
