// from server: 100% by nuck16
// roc 2009-12 0096cf60  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096cf60
//
// 0096cf60  6a00                 push 0
// 0096cf62  6a0f                 push 0xf
// 0096cf64  68e0000000           push 0xe0
// 0096cf69  68b8c39b00           push 0x9bc3b8
// 0096cf6e  6828c59b00           push 0x9bc528
// 0096cf73  b9b8feb700           mov ecx, 0xb7feb8
// 0096cf78  e843c3bbff           call 0x5292c0
// 0096cf7d  6830039800           push 0x980330
// 0096cf82  e8a279e8ff           call 0x7f4929
// 0096cf87  59                   pop ecx
// 0096cf88  c3                   ret 

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

static Desc desc("BandwidthExceededThreshold", "Network", 224, 15, 0);
