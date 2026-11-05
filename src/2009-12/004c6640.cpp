// from server: 64% by atomic.potato
extern "C" void clear(void *, int, bool);
extern "C" void *seekg(void *, long, int);

struct S
{
    void f(long);
};

void S::f(long pos)
{
    void *stream = *(void **)((char *)this + 0x24);
    void *base = *(void **)stream;
    void *object = (char *)(*(void **)((char *)base + 4)) + (unsigned int)stream;
    clear(object, 0, false);
    seekg(stream, pos, 0);
}
