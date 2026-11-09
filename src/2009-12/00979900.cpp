// from server: 100% by nuck16
// roc 2009-12 00979900  unit: seg_00970000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00979900
//
// 00979900  6a00                 push 0
// 00979902  6a0f                 push 0xf
// 00979904  6858010000           push 0x158
// 00979909  68141c9e00           push 0x9e1c14
// 0097990e  68c01c9e00           push 0x9e1cc0
// 00979913  b9c063b900           mov ecx, 0xb963c0
// 00979918  e8d3f2dbff           call 0x738bf0
// 0097991d  6890879800           push 0x988790
// 00979922  e802b0e7ff           call 0x7f4929
// 00979927  59                   pop ecx
// 00979928  c3                   ret 

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

static Desc desc("P", "Goals", 344, 15, 0);
