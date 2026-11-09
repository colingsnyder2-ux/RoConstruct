// from server: 59% by atomic.potato
extern "C" void G1_func_00606b80(void *);
extern "C" void G1_string_ctor(void *, const char *);
extern void *G1_vftable_00a932e8;

struct S
{
    S(void *);
};

S::S(void *arg)
{
    char buffer[28];
    G1_string_ctor(buffer, "TrackCamera");
    G1_func_00606b80(this);
    *(void **)this = G1_vftable_00a932e8;
}
