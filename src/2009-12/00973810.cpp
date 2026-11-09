// from server: 100% by nuck16
// roc 2009-12 00973810  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973810
//
// 00973810  6a00                 push 0
// 00973812  6a02                 push 2
// 00973814  6870010000           push 0x170
// 00973819  68801b9d00           push 0x9d1b80
// 0097381e  68901b9d00           push 0x9d1b90
// 00973823  b9d410b900           mov ecx, 0xb910d4
// 00973828  e8d3c1d1ff           call 0x68fa00
// 0097382d  68a04f9800           push 0x984fa0
// 00973832  e8f210e8ff           call 0x7f4929
// 00973837  59                   pop ecx
// 00973838  c3                   ret 

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

static Desc desc("DeselectedConnectionCount", "EventReplicator", 368, 2, 0);
