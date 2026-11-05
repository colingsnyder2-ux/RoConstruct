// from server: 100% by nuck16
// roc 2009-12 0096d1f0  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d1f0
//
// 0096d1f0  6a00                 push 0
// 0096d1f2  6a0f                 push 0xf
// 0096d1f4  68c8000000           push 0xc8
// 0096d1f9  680cc69b00           push 0x9bc60c
// 0096d1fe  6824c69b00           push 0x9bc624
// 0096d203  b968ffb700           mov ecx, 0xb7ff68
// 0096d208  e8e3c2bbff           call 0x5294f0
// 0096d20d  68f0019800           push 0x9801f0
// 0096d212  e81277e8ff           call 0x7f4929
// 0096d217  59                   pop ecx
// 0096d218  c3                   ret 

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

static Desc desc("ExperimentalPhysicsEnabled", "Physics", 200, 15, 0);
