// from server: 88% by atomic.potato
extern "C" void copy9(void *, const void *);

struct S_func_006f4810 {
    char pad0[204];
    float m_x;
    float m_y;
    float m_z;
    void f(void *);
};

void S_func_006f4810::f(void *p)
{
    char *src = pad0 + 204;
    copy9(p, src);
    ((float *)p)[9] = ((float *)src)[9];
    ((float *)p)[10] = ((float *)src)[10];
    ((float *)p)[11] = ((float *)src)[11];
}
