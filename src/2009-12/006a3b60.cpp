// from server: 100% by atomic.potato
typedef int (*Function)(void *, void *);

int f(void *a, void *b, void *c)
{
    return ((Function)(*(void **)a))(b, c);
}
