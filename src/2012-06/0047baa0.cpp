// from server: 69% by atomic.potato
struct AbortVerb
{
    int padding0[3];
    int f();
};

extern "C" int Call4701F0(void *);
extern "C" void Call4B0300(void *);

int AbortVerb::f()
{
    void *p = *(void **)((char *)this + 0x0c);
    void *q = *(void **)((char *)p + 0xbc);
    if (Call4701F0(q))
        Call4B0300(*(void **)((char *)*(void **)((char *)this + 0x0c) + 0xbc));
    return 0;
}
