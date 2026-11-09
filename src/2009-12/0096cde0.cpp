// from server: 100% by nuck16
// roc 2009-12 0096cde0  unit: seg_00960000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096cde0
//
// 0096cde0  6a01                 push 1
// 0096cde2  681cbf9b00           push 0x9bbf1c
// 0096cde7  6830bf9b00           push 0x9bbf30
// 0096cdec  6848010000           push 0x148
// 0096cdf1  b9a8fdb700           mov ecx, 0xb7fda8
// 0096cdf6  e8d5abbbff           call 0x5279d0
// 0096cdfb  6850009800           push 0x980050
// 0096ce00  e8247be8ff           call 0x7f4929
// 0096ce05  59                   pop ecx
// 0096ce06  c3                   ret 

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
    Desc(int, const char *, const char *, int);
    ~Desc();
};

static Desc desc(328, "ConnectionRejected", "peer", 1);
