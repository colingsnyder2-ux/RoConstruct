// from server: 100% by nuck16
// roc 2009-12 00977770  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00977770
//
// 00977770  6a00                 push 0
// 00977772  6a02                 push 2
// 00977774  6824020000           push 0x224
// 00977779  68801b9d00           push 0x9d1b80
// 0097777e  68a0cc9d00           push 0x9dcca0
// 00977783  b95047b900           mov ecx, 0xb94750
// 00977788  e8f306d8ff           call 0x6f7e80
// 0097778d  6820729800           push 0x987220
// 00977792  e892d1e7ff           call 0x7f4929
// 00977797  59                   pop ecx
// 00977798  c3                   ret 

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

static Desc desc("MoveConnectionCount", "EventReplicator", 548, 2, 0);
