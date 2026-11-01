// from server: 100% by king_originala
extern volatile int global_976b78;

struct S
{
    void sub_5adbf0(void *, void *);
};

extern "C" void __cdecl sub_612410(void *, void *);
extern "C" void __cdecl sub_612460(void *, int);
extern "C" S * __cdecl sub_612120(void *, int);
extern "C" void __cdecl sub_611c20(void *, int);

void __cdecl sub_5ae230(void *state, void *arg)
{
    if (global_976b78 > 0)
    {
        sub_612410(state, (void *)67);
        sub_612460(state, -10002);
        S *object = sub_612120(state, -1);
        sub_611c20(state, -2);
        object->sub_5adbf0(state, arg);
    }
}
