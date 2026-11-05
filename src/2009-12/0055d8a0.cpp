// from server: 93% by atomic.potato
struct S
{
};

void * __cdecl Get(void *p)
{
    void **x = p ? (void **)((char *)p + 0x70) : 0;
    void *head = *x;
    void *it = head;
    while (*(void **)it != x)
        it = *(void **)it;
    *(void **)it = head;
    return 0;
}
