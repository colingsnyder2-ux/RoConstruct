// from server: 88% by atomic.potato
struct S
{
    void* f(void*);
    void g(void*);
};

void S::g(void* a)
{
    void* p = f((char*)a + 4);
    void* q = *(void**)p;
    g(&q);
}
