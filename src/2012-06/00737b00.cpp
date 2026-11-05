// from server: 72% by atomic.potato
struct S
{
    void *GetValue(void *);
    void SetValue(void *);
};

struct T
{
    void f(void *);
};

void T::f(void *p)
{
    S *s = (S *)this;
    void *v = s->GetValue((char *)p + 4);
    s->SetValue(v);
}
