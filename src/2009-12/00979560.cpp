// from server: 100% by nuck16
// roc 2009-12 00979560  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979560
//
// 00979560  6a00                 push 0
// 00979562  6a0f                 push 0xf
// 00979564  6888010000           push 0x188
// 00979569  68481c9e00           push 0x9e1c48
// 0097956e  685c1c9e00           push 0x9e1c5c
// 00979573  b93865b900           mov ecx, 0xb96538
// 00979578  e8c3f0dbff           call 0x738640
// 0097957d  68b0859800           push 0x9885b0
// 00979582  e8a2b3e7ff           call 0x7f4929
// 00979587  59                   pop ecx
// 00979588  c3                   ret 

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

static Desc desc("ThrustP", "Thrust", 392, 15, 0);
