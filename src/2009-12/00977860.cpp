// from server: 100% by nuck16
// roc 2009-12 00977860  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977860
//
// 00977860  6a00                 push 0
// 00977862  6a02                 push 2
// 00977864  68ec020000           push 0x2ec
// 00977869  68801b9d00           push 0x9d1b80
// 0097786e  681ccd9d00           push 0x9dcd1c
// 00977873  b9f846b900           mov ecx, 0xb946f8
// 00977878  e80306d8ff           call 0x6f7e80
// 0097787d  6820719800           push 0x987120
// 00977882  e8a2d0e7ff           call 0x7f4929
// 00977887  59                   pop ecx
// 00977888  c3                   ret 

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

static Desc desc("Button2UpConnectionCount", "EventReplicator", 748, 2, 0);
