// from server: 65% by atomic.potato
struct S
{
    double value;
    unsigned char state;
};

extern "C" void update_004151e0(void*);
extern "C" void __stdcall f_007fd820(S*, const S*, double);

struct ViewUpdateJob
{
    S* update(S*, const S*);
};

double g_00a6f090 = 0.0;

S* ViewUpdateJob::update(S* a, const S* b)
{
    update_004151e0(this);
    f_007fd820(a, b, g_00a6f090);
    return a;
}
