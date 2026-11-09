// from server: 88% by atomic.potato
struct S
{
    void *Get(void *p);
    void Set(void *p);
};

void S::Set(void *p)
{
    void *value = Get((char *)p + 4);
    void *arg = *(void **)value;
    Set(&arg);
}
