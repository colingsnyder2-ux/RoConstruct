// from server: 64% by atomic.potato
struct S
{
};

extern "C" void *__cdecl sub_00539920(void *);
extern "C" void *__cdecl sub_00533710(void *, void *);

void * __cdecl f(void *p)
{
    char local[12];
    void *a = sub_00539920(local);
    return sub_00533710(p, a);
}
