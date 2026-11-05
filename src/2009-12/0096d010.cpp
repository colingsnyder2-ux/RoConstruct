// from server: 100% by nuck16
// roc 2009-12 0096d010  unit: seg_00960000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096d010
//
// 0096d010  6a00                 push 0
// 0096d012  6a0f                 push 0xf
// 0096d014  68f4000000           push 0xf4
// 0096d019  68b8c39b00           push 0x9bc3b8
// 0096d01e  6868c59b00           push 0x9bc568
// 0096d023  b998feb700           mov ecx, 0xb7fe98
// 0096d028  e843c0bbff           call 0x529070
// 0096d02d  6870019800           push 0x980170
// 0096d032  e8f278e8ff           call 0x7f4929
// 0096d037  59                   pop ecx
// 0096d038  c3                   ret 

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

static Desc desc("WaitingForCharacterLogRate", "Network", 244, 15, 0);
