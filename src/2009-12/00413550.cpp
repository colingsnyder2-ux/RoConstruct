// from server: 62% by atomic.potato
extern "C" void construct_string(void *, const char *);
extern "C" void call_67a5c0(void *);

struct CutVerb
{
    void *vftable;
    CutVerb(void *);
};

CutVerb::CutVerb(void *arg)
{
    void *p;
    p = arg;
    construct_string((void *)0, "Copy");
    call_67a5c0(this);
    vftable = (void *)0x9a22b8;
}
