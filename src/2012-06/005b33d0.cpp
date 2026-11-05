// from server: 90% by atomic.potato
extern "C" void __stdcall sub_8766f(void *);
extern "C" void __cdecl sub_982114(void *);

struct S {
    int value;
    int state;

    void __stdcall f();
};

void __stdcall S::f()
{
    S *q = (S *)((char *)this + 4);
    sub_8766f(q);
    sub_982114((void *)q->state);
    q->state = 0;
}
