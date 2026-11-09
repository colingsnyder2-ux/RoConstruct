// from server: 100% by nuck16
// roc 2009-12 009777d0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009777d0
//
// 009777d0  6a00                 push 0
// 009777d2  6a02                 push 2
// 009777d4  6874020000           push 0x274
// 009777d9  68801b9d00           push 0x9d1b80
// 009777de  68c8cc9d00           push 0x9dccc8
// 009777e3  b99047b900           mov ecx, 0xb94790
// 009777e8  e89306d8ff           call 0x6f7e80
// 009777ed  68c0709800           push 0x9870c0
// 009777f2  e832d1e7ff           call 0x7f4929
// 009777f7  59                   pop ecx
// 009777f8  c3                   ret 

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

static Desc desc("Button1DownConnectionCount", "EventReplicator", 628, 2, 0);
