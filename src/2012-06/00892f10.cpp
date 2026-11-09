// from server: 100% by atomic.potato
struct S_00892f10
{
    int pad0[4];
    int value;
    int f();
};

int S_00892f10::f()
{
    return value == 13 || value == 271 ? 1 : 0;
}
