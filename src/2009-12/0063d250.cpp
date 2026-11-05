// from server: 91% by atomic.potato
struct Team_0063d250
{
    int f(void *);
};

extern "C" int __cdecl call_007f4aaa(void *, void *, void *, void *, void *);

int Team_0063d250::f(void *p)
{
    int r = call_007f4aaa(p, (void *)0xaffe40, (void *)0xb2aed0, (void *)0, (void *)0);
    return r != 0;
}
