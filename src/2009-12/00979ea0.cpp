// from server: 100% by nuck16
// roc 2009-12 00979ea0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979ea0
//
// 00979ea0  6a01                 push 1
// 00979ea2  68a0b19b00           push 0x9bb1a0
// 00979ea7  33c9                 xor ecx, ecx
// 00979ea9  684ccc9d00           push 0x9dcc4c
// 00979eae  51                   push ecx
// 00979eaf  b820027400           mov eax, 0x740220
// 00979eb4  50                   push eax
// 00979eb5  b9c069b900           mov ecx, 0xb969c0
// 00979eba  e8e167dcff           call 0x7406a0
// 00979ebf  68008d9800           push 0x988d00
// 00979ec4  e860aae7ff           call 0x7f4929
// 00979ec9  59                   pop ecx
// 00979eca  c3                   ret 

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

static Desc desc(&Owner::m0, "Button2Down", "position", 1);
