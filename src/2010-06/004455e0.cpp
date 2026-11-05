// from server: 75% by atomic.potato
struct S {
    int value;
    void get(int *);
};

void S::get(int *out)
{
    *out = *(int *)((char *)this + 0x4a);
}
