// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern float multiplier;

struct S
{
    char padding[0x38];
    float value;
    float scale;
    int f();
};

int S::f()
{
    if (value < multiplier * scale || value > scale + scale)
        return 1;
    return 0;
}
