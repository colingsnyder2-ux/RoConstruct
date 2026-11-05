// from server: 100% by nuck16
// roc 2009-12 00977800  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977800
//
// 00977800  6a00                 push 0
// 00977802  6a02                 push 2
// 00977804  689c020000           push 0x29c
// 00977809  68801b9d00           push 0x9d1b80
// 0097780e  68e4cc9d00           push 0x9dcce4
// 00977813  b9b449b900           mov ecx, 0xb949b4
// 00977818  e86306d8ff           call 0x6f7e80
// 0097781d  68e0709800           push 0x9870e0
// 00977822  e802d1e7ff           call 0x7f4929
// 00977827  59                   pop ecx
// 00977828  c3                   ret 

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

static Desc desc("Button2DownConnectionCount", "EventReplicator", 668, 2, 0);
