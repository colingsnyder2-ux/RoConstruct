// from server: 100% by nuck16
// roc 2009-12 00979de0  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979de0
//
// 00979de0  6a01                 push 1
// 00979de2  68a0b19b00           push 0x9bb1a0
// 00979de7  33c9                 xor ecx, ecx
// 00979de9  68e8279e00           push 0x9e27e8
// 00979dee  51                   push ecx
// 00979def  b810057400           mov eax, 0x740510
// 00979df4  50                   push eax
// 00979df5  b9286bb900           mov ecx, 0xb96b28
// 00979dfa  e8a168dcff           call 0x7406a0
// 00979dff  68408d9800           push 0x988d40
// 00979e04  e820abe7ff           call 0x7f4929
// 00979e09  59                   pop ecx
// 00979e0a  c3                   ret 

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

static Desc desc(&Owner::m0, "ClickButton1", "position", 1);
