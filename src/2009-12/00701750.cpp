// from server: 51% by atomic.potato
struct P
{
    void g();
};

struct S
{
    char pad[36];
    char pad2[244];
    P* m_p;
    void f(int);
};

struct V
{
    float x;
    float y;
};

extern "C" void call_006edb90(S*);
extern "C" void call_005f4d10(V*, V*);

void S::f(int value)
{
    S* p = this;
    P* q = *(P**)((char*)p + 36);
    if (q)
        q = (P*)((char*)q - 8);
    call_006edb90((S*)q);
    call_005f4d10((V*)this, (V*)value);
}
