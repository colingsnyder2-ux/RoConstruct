// from server: 100% by atomic.potato
struct SpecialShape
{
    void GetValues(int *, int *, int *, int *);
};

void SpecialShape::GetValues(int *a, int *b, int *c, int *d)
{
    *a = *(int *)((char *)this + 4);
    *b = *(int *)((char *)this + 8);
    *c = *(int *)((char *)this + 12);
    *d = *(int *)((char *)this + 16);
}
