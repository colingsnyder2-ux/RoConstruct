// from server: 29% by atomic.potato
struct S
{
    int *Get(int *);
    void Set(int *);
};

int *S::Get(int *p)
{
    return p;
}

void S::Set(int *)
{
}

void __fastcall Function0077ebf0(S *self, void *, int *p)
{
    int *value;
    value = self->Get(p + 1);
    self->Set(value);
}
