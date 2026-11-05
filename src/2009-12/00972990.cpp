// from server: 100% by nuck16
// roc 2009-12 00972990  unit: seg_00970000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00972990
//
// 00972990  6a01                 push 1
// 00972992  33c9                 xor ecx, ecx
// 00972994  68001f9c00           push 0x9c1f00
// 00972999  51                   push ecx
// 0097299a  b8b0566600           mov eax, 0x6656b0
// 0097299f  50                   push eax
// 009729a0  b94808b900           mov ecx, 0xb90848
// 009729a5  e8e6bfcfff           call 0x66e990
// 009729aa  6870499800           push 0x984970
// 009729af  e8751fe8ff           call 0x7f4929
// 009729b4  59                   pop ecx
// 009729b5  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Shutdown", 1);
