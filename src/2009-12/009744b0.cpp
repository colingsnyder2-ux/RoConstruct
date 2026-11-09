// from server: 100% by nuck16
// roc 2009-12 009744b0  unit: seg_00970000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009744b0
//
// 009744b0  33c9                 xor ecx, ecx
// 009744b2  51                   push ecx
// 009744b3  68accb9b00           push 0x9bcbac
// 009744b8  51                   push ecx
// 009744b9  b8d0a56b00           mov eax, 0x6ba5d0
// 009744be  50                   push eax
// 009744bf  b9481bb900           mov ecx, 0xb91b48
// 009744c4  e8d72ed4ff           call 0x6b73a0
// 009744c9  6850589800           push 0x985850
// 009744ce  e85604e8ff           call 0x7f4929
// 009744d3  59                   pop ecx
// 009744d4  c3                   ret 

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
    Desc(void (Owner::*)(), const char *, int);
    ~Desc();
};

static Desc desc(&Owner::m0, "Stop", 0);
