// from server: 56% by atomic.potato
struct StringStream
{
};

extern "C" void stringstream_str(StringStream *, void *);

struct S_func_004ca4b0
{
    S_func_004ca4b0 *f(StringStream *);
};

S_func_004ca4b0 *S_func_004ca4b0::f(StringStream *p)
{
    stringstream_str(p, 0);
    return (S_func_004ca4b0 *)p;
}
