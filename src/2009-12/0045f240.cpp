// from server: 71% by atomic.potato
extern "C" void __cdecl sub_5eab80();

double g_9adf68;

struct InsertModelFromRobloxVerb
{
    unsigned char pad[0x10];
    int value;
    unsigned char pad2[4];
    double time;
    unsigned char f();
};

struct Target
{
    unsigned char f(int);
};

unsigned char InsertModelFromRobloxVerb::f()
{
    sub_5eab80();
    if (time + g_9adf68 < 0.0)
        return 0;
    return ((Target *)value)->f(value);
}
