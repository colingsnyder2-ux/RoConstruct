// from server: 28% by atomic.potato
struct S
{
    int padAC;
    int padB0;
    int f();
};

extern "C" int helper(S*, int);

int S::f()
{
    if (padB0 > 0)
        return helper((S*)((char*)this - 8), *(int*)padAC);
    return helper((S*)((char*)this - 8), 0);
}
