// from server: 100% by nuck16
// roc 2009-12 0096eba0  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0096eba0
//
// 0096eba0  33c9                 xor ecx, ecx
// 0096eba2  51                   push ecx
// 0096eba3  680cc09c00           push 0x9cc00c
// 0096eba8  68fcbf9c00           push 0x9cbffc
// 0096ebad  51                   push ecx
// 0096ebae  b830296300           mov eax, 0x632930
// 0096ebb3  50                   push eax
// 0096ebb4  b99053b800           mov ecx, 0xb85390
// 0096ebb9  e84263ccff           call 0x634f00
// 0096ebbe  6860199800           push 0x981960
// 0096ebc3  e8615de8ff           call 0x7f4929
// 0096ebc8  59                   pop ecx
// 0096ebc9  c3                   ret 

// dynamic initializer of a static reflection descriptor: ctor on the static object, then atexit(destructor).
// Member function pointers are {fn, 0} pairs, so the owner uses multiple inheritance.
struct BaseA { int a; };
struct BaseB { int b; };
class Owner : public BaseA, public BaseB
{
public:
    void m0();
};

struct Desc
{
    Desc(void (Owner::*)(), const char *, const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "IsDescendantOf", "ancestor", 0);
