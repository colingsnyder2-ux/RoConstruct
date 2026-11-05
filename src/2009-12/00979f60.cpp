// from server: 100% by nuck16
// roc 2009-12 00979f60  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979f60
//
// 00979f60  6a01                 push 1
// 00979f62  68d8e19d00           push 0x9de1d8
// 00979f67  33c9                 xor ecx, ecx
// 00979f69  681c289e00           push 0x9e281c
// 00979f6e  51                   push ecx
// 00979f6f  b880027400           mov eax, 0x740280
// 00979f74  50                   push eax
// 00979f75  b9706bb900           mov ecx, 0xb96b70
// 00979f7a  e8b168dcff           call 0x740830
// 00979f7f  68b08c9800           push 0x988cb0
// 00979f84  e8a0a9e7ff           call 0x7f4929
// 00979f89  59                   pop ecx
// 00979f8a  c3                   ret 

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

static Desc desc(&Owner::m0, "SetKeyDown", "key", 1);
