// from server: 100% by nuck16
// roc 2009-12 00979d20  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979d20
//
// 00979d20  6a00                 push 0
// 00979d22  6a0f                 push 0xf
// 00979d24  68a8000000           push 0xa8
// 00979d29  6884b09b00           push 0x9bb084
// 00979d2e  6868249e00           push 0x9e2468
// 00979d33  b96068b900           mov ecx, 0xb96860
// 00979d38  e8b33fdcff           call 0x73dcf0
// 00979d3d  68a08b9800           push 0x988ba0
// 00979d42  e8e2abe7ff           call 0x7f4929
// 00979d47  59                   pop ecx
// 00979d48  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:

};


struct Desc
{
    Desc(const char *, const char *, int, int, int);
    ~Desc();
};

static Desc desc("MaxActivationDistance", "Data", 168, 15, 0);
