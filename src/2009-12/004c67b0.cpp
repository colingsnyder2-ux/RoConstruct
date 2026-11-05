// from server: 63% by atomic.potato
extern "C" void __stdcall clear(void *, int, bool);
extern "C" void *__stdcall seekg(void *, long, int);

struct S {
    int pad0[9];
    void f(long);
};

void S::f(long value)
{
    void *stream = *(void **)((char *)this + 0x24);
    clear(*(void **)stream, 0, false);
    seekg(stream, value, 1);
}
