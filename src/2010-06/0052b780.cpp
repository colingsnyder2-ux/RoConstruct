// from server: 60% by atomic.potato
struct S {
    virtual ~S();
    int v[5];
    S();
};

extern "C" void std_bad_cast_destructor(S *);

S::S()
{
    v[0] = 0xA1ED44;
    v[5] = 0xA1ED3C;
    v[5] = 0xA00968;
    if (v[6])
        std_bad_cast_destructor((S *)v[6]);
    v[0] = 0xA1EB6C;
}
