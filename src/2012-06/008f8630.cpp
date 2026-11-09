// from server: 81% by atomic.potato
struct S {
    int (__thiscall *callable)(S*, float, float);
    int value10;
    int value14;
    int value18;

    int run(float a, float b);
};

int S::run(float a, float b)
{
    return callable(this, a, b);
}
