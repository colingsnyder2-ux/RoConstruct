// from server: 100% by king_originala
struct S;

struct Arg
{
    void* unused;
    S* stage;
};

struct S
{
    virtual void slot0();
    virtual int rank();

    char padding[0x1d8];
    bool pending;

    void func_0064b5e0(Arg*);
    void func_0064b6d0(Arg*);
    void func_0064b890(Arg*, bool);
};

void S::func_0064b890(Arg* arg, bool enable)
{
    if (arg->stage != 0)
    {
        int otherRank = arg->stage->rank();
        if (otherRank >= rank())
        {
            if (enable)
            {
                pending = true;
                func_0064b6d0(arg);
            }
            else
            {
                func_0064b5e0(arg);
            }
        }
    }
}
