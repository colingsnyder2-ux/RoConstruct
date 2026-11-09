// from server: 100% by nuck16
// roc 2009-12 0097a800  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a800
//
// 0097a800  6a00                 push 0
// 0097a802  6a02                 push 2
// 0097a804  6894010000           push 0x194
// 0097a809  68801b9d00           push 0x9d1b80
// 0097a80e  68e03e9e00           push 0x9e3ee0
// 0097a813  b93072b900           mov ecx, 0xb97230
// 0097a818  e83325ddff           call 0x74cd50
// 0097a81d  6890919800           push 0x989190
// 0097a822  e802a1e7ff           call 0x7f4929
// 0097a827  59                   pop ecx
// 0097a828  c3                   ret 

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

static Desc desc("MouseButton1UpConnectionCount", "EventReplicator", 404, 2, 0);
