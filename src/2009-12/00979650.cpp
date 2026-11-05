// from server: 100% by nuck16
// roc 2009-12 00979650  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979650
//
// 00979650  6a00                 push 0
// 00979652  6a0f                 push 0xf
// 00979654  68a8010000           push 0x1a8
// 00979659  68141c9e00           push 0x9e1c14
// 0097965e  68901c9e00           push 0x9e1c90
// 00979663  b9d862b900           mov ecx, 0xb962d8
// 00979668  e8d3efdbff           call 0x738640
// 0097966d  6830869800           push 0x988630
// 00979672  e8b2b2e7ff           call 0x7f4929
// 00979677  59                   pop ecx
// 00979678  c3                   ret 

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

static Desc desc("CartoonFactor", "Goals", 424, 15, 0);
