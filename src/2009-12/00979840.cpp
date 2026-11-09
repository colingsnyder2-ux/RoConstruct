// from server: 100% by nuck16
// roc 2009-12 00979840  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979840
//
// 00979840  6a00                 push 0
// 00979842  6a0f                 push 0xf
// 00979844  6860010000           push 0x160
// 00979849  68141c9e00           push 0x9e1c14
// 0097984e  68d81c9e00           push 0x9e1cd8
// 00979853  b9dc66b900           mov ecx, 0xb966dc
// 00979858  e8c3f2dbff           call 0x738b20
// 0097985d  6830879800           push 0x988730
// 00979862  e8c2b0e7ff           call 0x7f4929
// 00979867  59                   pop ecx
// 00979868  c3                   ret 

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

static Desc desc("maxForce", "Goals", 352, 15, 0);
