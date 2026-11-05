// from server: 32% by atomic.potato
struct S
{
    int v;
    short x;
    short y;
    float a;
    float b;
    void f(S *);
    virtual void g();
};

void S::f(S *p)
{
    this->a = (float)p->x;
    this->b = (float)p->y;
    this->g();
}
