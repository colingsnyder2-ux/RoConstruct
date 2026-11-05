// from server: 100% by atomic.potato
struct SpecialShape
{
    void Get(int *, int *, int *, int *);
};

void SpecialShape::Get(int *a, int *b, int *c, int *d)
{
    *a = *(int *)this;
    *b = *((int *)this + 1);
    *c = *((int *)this + 2);
    *d = *((int *)this + 3);
}
