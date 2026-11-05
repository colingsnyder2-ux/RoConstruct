// from server: 100% by nuck16
// roc 2009-12 0097a530  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097a530
//
// 0097a530  6a00                 push 0
// 0097a532  6a02                 push 2
// 0097a534  6844010000           push 0x144
// 0097a539  68801b9d00           push 0x9d1b80
// 0097a53e  68a43e9e00           push 0x9e3ea4
// 0097a543  b9646fb900           mov ecx, 0xb96f64
// 0097a548  e803eadcff           call 0x748f50
// 0097a54d  68508f9800           push 0x988f50
// 0097a552  e8d2a3e7ff           call 0x7f4929
// 0097a557  59                   pop ecx
// 0097a558  c3                   ret 

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
