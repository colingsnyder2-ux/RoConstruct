// from server: 100% by nuck16
// roc 2009-12 0096cd10  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096cd10
//
// 0096cd10  6a00                 push 0
// 0096cd12  6a0f                 push 0xf
// 0096cd14  6824010000           push 0x124
// 0096cd19  68a4be9b00           push 0x9bbea4
// 0096cd1e  689cbe9b00           push 0x9bbe9c
// 0096cd23  b9e0fdb700           mov ecx, 0xb7fde0
// 0096cd28  e8d394bbff           call 0x526200
// 0096cd2d  6820009800           push 0x980020
// 0096cd32  e8f27be8ff           call 0x7f4929
// 0096cd37  59                   pop ecx
// 0096cd38  c3                   ret 

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

static Desc desc("Ticket", "Authentication", 292, 15, 0);
