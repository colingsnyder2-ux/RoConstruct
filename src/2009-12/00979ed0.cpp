// from server: 100% by nuck16
// roc 2009-12 00979ed0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979ed0
//
// 00979ed0  6a01                 push 1
// 00979ed2  68a0b19b00           push 0x9bb1a0
// 00979ed7  33c9                 xor ecx, ecx
// 00979ed9  6864cc9d00           push 0x9dcc64
// 00979ede  51                   push ecx
// 00979edf  b850027400           mov eax, 0x740250
// 00979ee4  50                   push eax
// 00979ee5  b97869b900           mov ecx, 0xb96978
// 00979eea  e8b167dcff           call 0x7406a0
// 00979eef  68108d9800           push 0x988d10
// 00979ef4  e830aae7ff           call 0x7f4929
// 00979ef9  59                   pop ecx
// 00979efa  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Button2Up", "position", 1);
