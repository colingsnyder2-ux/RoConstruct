// from server: 100% by nuck16
// roc 2009-12 00973840  unit: seg_00970000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973840
//
// 00973840  33c9                 xor ecx, ecx
// 00973842  51                   push ecx
// 00973843  51                   push ecx
// 00973844  51                   push ecx
// 00973845  b840176900           mov eax, 0x691740
// 0097384a  50                   push eax
// 0097384b  51                   push ecx
// 0097384c  6884b09b00           push 0x9bb084
// 00973851  685c449a00           push 0x9a445c
// 00973856  b97411b900           mov ecx, 0xb91174
// 0097385b  e870c2d1ff           call 0x68fad0
// 00973860  6840509800           push 0x985040
// 00973865  e8bf10e8ff           call 0x7f4929
// 0097386a  59                   pop ecx
// 0097386b  c3                   ret 

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
    Desc(const char *, const char *, int, void (Owner::*)(), int, int);
    ~Desc();
};

static Desc desc("Command", "Data", 0, &Owner::m0, 0, 0);
