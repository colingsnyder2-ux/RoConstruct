// from server: 100% by nuck16
// roc 2009-12 00979e70  unit: seg_00970000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979e70
//
// 00979e70  6a01                 push 1
// 00979e72  68a0b19b00           push 0x9bb1a0
// 00979e77  33c9                 xor ecx, ecx
// 00979e79  68f8279e00           push 0x9e27f8
// 00979e7e  51                   push ecx
// 00979e7f  b860057400           mov eax, 0x740560
// 00979e84  50                   push eax
// 00979e85  b9006cb900           mov ecx, 0xb96c00
// 00979e8a  e81168dcff           call 0x7406a0
// 00979e8f  68f08c9800           push 0x988cf0
// 00979e94  e890aae7ff           call 0x7f4929
// 00979e99  59                   pop ecx
// 00979e9a  c3                   ret 

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

static Desc desc(&Owner::m0, "ClickButton2", "position", 1);
