// from server: 100% by nuck16
// roc 2009-12 009737e0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009737e0
//
// 009737e0  6a00                 push 0
// 009737e2  6a02                 push 2
// 009737e4  6848010000           push 0x148
// 009737e9  68801b9d00           push 0x9d1b80
// 009737ee  685c1b9d00           push 0x9d1b5c
// 009737f3  b9c011b900           mov ecx, 0xb911c0
// 009737f8  e803c2d1ff           call 0x68fa00
// 009737fd  6800509800           push 0x985000
// 00973802  e82211e8ff           call 0x7f4929
// 00973807  59                   pop ecx
// 00973808  c3                   ret 

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

static Desc desc("ReplicatedSelectedConnectionCount", "EventReplicator", 328, 2, 0);
