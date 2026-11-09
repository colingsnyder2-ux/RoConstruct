// from server: 42% by atomic.potato
struct MovingAssemblyStage
{
    int unused[4];
    int state;
    int f();
};

extern "C" void __cdecl Function007bb240();
extern "C" void __cdecl Function007bb520(int);

int MovingAssemblyStage::f()
{
    int value = state;
    if (value == 0)
        Function007bb520(1);
    else if (value == 1)
        Function007bb520(3);
    else if (value == 2)
        Function007bb520(1);
    else
        Function007bb240();
    return 0;
}
