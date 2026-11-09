// from server: 43% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl sub_00924880(void *);
extern "C" void __cdecl sub_009250F0(void *);

int S::f()
{
    char local[8];
    void *value;
    sub_00924880(local);
    value = *(void **)(local);
    sub_009250F0(value);
    return 0;
}
