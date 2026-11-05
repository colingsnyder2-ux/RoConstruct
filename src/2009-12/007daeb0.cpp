// from server: 83% by atomic.potato
struct Stage
{
};

struct S
{
    void f(Stage *);
};

extern "C" void __fastcall call_7b8f20(void *, Stage *);
extern "C" void __fastcall call_7b2f40(void *, S *);

void S::f(Stage *stage)
{
    call_7b8f20(*(void **)((char *)this + 8), stage);
    call_7b2f40(stage, this);
}
