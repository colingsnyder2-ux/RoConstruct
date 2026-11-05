// from server: 100% by nuck16
// roc 2009-12 00979e10  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979e10
//
// 00979e10  6a01                 push 1
// 00979e12  68a0b19b00           push 0x9bb1a0
// 00979e17  33c9                 xor ecx, ecx
// 00979e19  6840cc9d00           push 0x9dcc40
// 00979e1e  51                   push ecx
// 00979e1f  b8c0017400           mov eax, 0x7401c0
// 00979e24  50                   push eax
// 00979e25  b9086ab900           mov ecx, 0xb96a08
// 00979e2a  e87168dcff           call 0x7406a0
// 00979e2f  68d08c9800           push 0x988cd0
// 00979e34  e8f0aae7ff           call 0x7f4929
// 00979e39  59                   pop ecx
// 00979e3a  c3                   ret 

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

static Desc desc(&Owner::m0, "Button1Down", "position", 1);
