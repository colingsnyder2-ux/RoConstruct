// from server: 100% by nuck16
// roc 2009-12 0097a7a0  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a7a0
//
// 0097a7a0  6a00                 push 0
// 0097a7a2  6a02                 push 2
// 0097a7a4  6844010000           push 0x144
// 0097a7a9  68801b9d00           push 0x9d1b80
// 0097a7ae  68a43e9e00           push 0x9e3ea4
// 0097a7b3  b98071b900           mov ecx, 0xb97180
// 0097a7b8  e89325ddff           call 0x74cd50
// 0097a7bd  6850919800           push 0x989150
// 0097a7c2  e862a1e7ff           call 0x7f4929
// 0097a7c7  59                   pop ecx
// 0097a7c8  c3                   ret 

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

static Desc desc("MouseDragConnectionCount", "EventReplicator", 324, 2, 0);
