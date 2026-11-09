// from server: 35% by atomic.potato
extern "C" int __cdecl getNextStateIndex();

struct S
{
    int f();
    float x;
    float y;
    int z[50];
};

int S::f()
{
    x = 0.0f;
    y = 0.0f;
    z[47] = getNextStateIndex();
    return 0;
}
