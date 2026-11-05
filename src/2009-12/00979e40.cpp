// from server: 100% by nuck16
// roc 2009-12 00979e40  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979e40
//
// 00979e40  6a01                 push 1
// 00979e42  68a0b19b00           push 0x9bb1a0
// 00979e47  33c9                 xor ecx, ecx
// 00979e49  6858cc9d00           push 0x9dcc58
// 00979e4e  51                   push ecx
// 00979e4f  b8f0017400           mov eax, 0x7401f0
// 00979e54  50                   push eax
// 00979e55  b9986ab900           mov ecx, 0xb96a98
// 00979e5a  e84168dcff           call 0x7406a0
// 00979e5f  68e08c9800           push 0x988ce0
// 00979e64  e8c0aae7ff           call 0x7f4929
// 00979e69  59                   pop ecx
// 00979e6a  c3                   ret 

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

static Desc desc(&Owner::m0, "Button1Up", "position", 1);
