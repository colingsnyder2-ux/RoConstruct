// from server: 54% by atomic.potato
struct Stage;
struct Assembly;

struct TreeStage
{
    int f(Stage *);
};

struct Assembly
{
    int value;
};

struct Stage
{
    int value;
};

extern "C" void __stdcall call_78d010(Assembly *);
extern "C" void __stdcall call_750ac0(Stage *, TreeStage *);

int TreeStage::f(Stage *stage)
{
    Assembly *assembly = *(Assembly **)((char *)this + 8);
    call_78d010(assembly);
    call_750ac0(stage, this);
    return 0;
}
