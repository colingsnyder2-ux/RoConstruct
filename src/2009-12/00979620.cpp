// from server: 100% by nuck16
// roc 2009-12 00979620  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979620
//
// 00979620  6a00                 push 0
// 00979622  6a0f                 push 0xf
// 00979624  689c010000           push 0x19c
// 00979629  68741c9e00           push 0x9e1c74
// 0097962e  68841c9e00           push 0x9e1c84
// 00979633  b90064b900           mov ecx, 0xb96400
// 00979638  e8d3f0dbff           call 0x738710
// 0097963d  6850869800           push 0x988650
// 00979642  e8e2b2e7ff           call 0x7f4929
// 00979647  59                   pop ecx
// 00979648  c3                   ret 

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

static Desc desc("MaxTorque", "Turn", 412, 15, 0);
