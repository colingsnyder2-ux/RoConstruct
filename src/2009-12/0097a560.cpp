// from server: 100% by nuck16
// roc 2009-12 0097a560  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a560
//
// 0097a560  6a00                 push 0
// 0097a562  6a02                 push 2
// 0097a564  686c010000           push 0x16c
// 0097a569  68801b9d00           push 0x9d1b80
// 0097a56e  68c03e9e00           push 0x9e3ec0
// 0097a573  b9846fb900           mov ecx, 0xb96f84
// 0097a578  e8d3e9dcff           call 0x748f50
// 0097a57d  68708f9800           push 0x988f70
// 0097a582  e8a2a3e7ff           call 0x7f4929
// 0097a587  59                   pop ecx
// 0097a588  c3                   ret 

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

static Desc desc("MouseButton1DownConnectionCount", "EventReplicator", 364, 2, 0);
