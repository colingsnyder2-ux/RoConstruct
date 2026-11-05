// from server: 100% by nuck16
// roc 2009-12 00979750  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979750
//
// 00979750  6a00                 push 0
// 00979752  6a0f                 push 0xf
// 00979754  685c010000           push 0x15c
// 00979759  68141c9e00           push 0x9e1c14
// 0097975e  6850f69900           push 0x99f650
// 00979763  b9e063b900           mov ecx, 0xb963e0
// 00979768  e873f0dbff           call 0x7387e0
// 0097976d  6870869800           push 0x988670
// 00979772  e8b2b1e7ff           call 0x7f4929
// 00979777  59                   pop ecx
// 00979778  c3                   ret 

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

static Desc desc("D", "Goals", 348, 15, 0);
