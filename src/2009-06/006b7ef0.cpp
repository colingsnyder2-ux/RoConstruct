// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00618160  unit: RBX::NullTool  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00618160
//
// 00618160  6aff                 push -1
// 00618162  68f8a97d00           push 0x7da9f8
// 00618167  64a100000000         mov eax, dword ptr fs:[0]
// 0061816d  50                   push eax
// 0061816e  64892500000000       mov dword ptr fs:[0], esp
// 00618175  51                   push ecx
// 00618176  8b442414             mov eax, dword ptr [esp + 0x14]
// 0061817a  56                   push esi
// 0061817b  8bf1                 mov esi, ecx
// 0061817d  50                   push eax
// 0061817e  89742408             mov dword ptr [esp + 8], esi
// 00618182  e869d8ffff           call 0x6159f0
// 00618187  6850388300           push 0x833850
// 0061818c  8d4e1c               lea ecx, [esi + 0x1c]
// 0061818f  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00618197  c706443c8400         mov dword ptr [esi], 0x843c44
// 0061819d  c74604283c8400       mov dword ptr [esi + 4], 0x843c28
// 006181a4  ff1558248000         call dword ptr [0x802458]
// 006181aa  d9ee                 fldz 
// 006181ac  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006181b0  c6463800             mov byte ptr [esi + 0x38], 0
// 006181b4  d9563c               fst dword ptr [esi + 0x3c]
// 006181b7  d95640               fst dword ptr [esi + 0x40]
// 006181ba  8bc6                 mov eax, esi
// 006181bc  d95e44               fstp dword ptr [esi + 0x44]
// 006181bf  5e                   pop esi
// 006181c0  64890d00000000       mov dword ptr fs:[0], ecx
// 006181c7  83c410               add esp, 0x10
// 006181ca  c20400               ret 4

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor stringConstructor;

namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class T, class Traits, class Alloc>
class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
{
    stringConstructor(this, text);
}
}

extern const int table0[];
extern const int table1[];

struct S_func_006159f0 {
    char storage[28];
    int f(int a1);
    S_func_006159f0(int a1);
    ~S_func_006159f0();
};

__forceinline S_func_006159f0::S_func_006159f0(int a1)
{
    f(a1);
}

struct S : S_func_006159f0 {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > cursor;
    volatile bool flag;
    volatile float x;
    volatile float y;
    volatile float z;
    S(int a1);
};

S::S(int a1)
    : S_func_006159f0(a1),
      cursor((*(const int**)this = table0,
              *((const int**)this + 1) = table1,
              "ArrowCursor"))
{
    flag = false;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
