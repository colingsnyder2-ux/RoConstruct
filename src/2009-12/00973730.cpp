// from server: 100% by nuck16
// roc 2009-12 00973730  unit: seg_00970000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973730
//
// 00973730  6a01                 push 1
// 00973732  68341b9d00           push 0x9d1b34
// 00973737  68281b9d00           push 0x9d1b28
// 0097373c  6838010000           push 0x138
// 00973741  b9e011b900           mov ecx, 0xb911e0
// 00973746  e8a5ced1ff           call 0x6905f0
// 0097374b  6860509800           push 0x985060
// 00973750  e8d411e8ff           call 0x7f4929
// 00973755  59                   pop ecx
// 00973756  c3                   ret 

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

static Desc desc(312, "Selected", "mouse", 1);
