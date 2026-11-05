// from server: 100% by nuck16
// roc 2009-12 00977830  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977830
//
// 00977830  6a00                 push 0
// 00977832  6a02                 push 2
// 00977834  68c4020000           push 0x2c4
// 00977839  68801b9d00           push 0x9d1b80
// 0097783e  6800cd9d00           push 0x9dcd00
// 00977843  b9644ab900           mov ecx, 0xb94a64
// 00977848  e83306d8ff           call 0x6f7e80
// 0097784d  6800719800           push 0x987100
// 00977852  e8d2d0e7ff           call 0x7f4929
// 00977857  59                   pop ecx
// 00977858  c3                   ret 

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

static Desc desc("Button1UpConnectionCount", "EventReplicator", 708, 2, 0);
