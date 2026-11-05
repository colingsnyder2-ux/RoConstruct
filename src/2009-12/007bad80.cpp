// from server: 85% by atomic.potato
struct Inner
{
    char padding[0x24];
    int *field;
    int f();
};

struct Vec2
{
    int x;
    int y;
};

struct Serializer
{
    int compare(Vec2 *v);
};

struct Outer
{
    char padding[0x14];
    void g(Inner *p);
};

void Outer::g(Inner *p)
{
    int *q = (int *)p->f();
    Vec2 v;
    v.x = q[0x1e];
    v.y = q[0x1f];
    Serializer *s = (Serializer *)((char *)this + 0x14);
    s->compare(&v);
}
