// from server: 88% by atomic.potato
struct S
{
    void *GetValue(void *);
    void SetValue(void *);
    void f(void *);
};

void S::f(void *p)
{
    S *self = this;
    void *value = self->GetValue((char *)p + 4);
    void *copy = *(void **)value;
    self->SetValue(&copy);
}
