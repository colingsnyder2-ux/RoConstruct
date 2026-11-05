// from server: 100% by nuck16
// roc 2009-12 0096d420  unit: seg_00960000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d420
//
// 0096d420  6a01                 push 1
// 0096d422  6824bf9b00           push 0x9bbf24
// 0096d427  681cbf9b00           push 0x9bbf1c
// 0096d42c  68f0cb9b00           push 0x9bcbf0
// 0096d431  6878010000           push 0x178
// 0096d436  b98003b800           mov ecx, 0xb80380
// 0096d43b  e87005bcff           call 0x52d9b0
// 0096d440  6820059800           push 0x980520
// 0096d445  e8df74e8ff           call 0x7f4929
// 0096d44a  59                   pop ecx
// 0096d44b  c3                   ret 

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
    Desc(int, const char *, const char *, const char *, int);
    ~Desc();
};

static Desc desc(376, "IncommingConnection", "peer", "replicator", 1);
