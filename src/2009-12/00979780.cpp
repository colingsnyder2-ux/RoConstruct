// from server: 100% by nuck16
// roc 2009-12 00979780  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979780
//
// 00979780  6a00                 push 0
// 00979782  6a0f                 push 0xf
// 00979784  6860010000           push 0x160
// 00979789  68141c9e00           push 0x9e1c14
// 0097978e  68c41c9e00           push 0x9e1cc4
// 00979793  b9a063b900           mov ecx, 0xb963a0
// 00979798  e813f1dbff           call 0x7388b0
// 0097979d  68b0869800           push 0x9886b0
// 009797a2  e882b1e7ff           call 0x7f4929
// 009797a7  59                   pop ecx
// 009797a8  c3                   ret 

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

static Desc desc("maxTorque", "Goals", 352, 15, 0);
