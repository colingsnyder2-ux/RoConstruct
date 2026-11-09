// from server: 100% by king_originala
struct Result {
    void* value;
};

struct Delegate {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual Result get(int argument) = 0;
};

struct S {
    unsigned char padding[12];
    Delegate* delegate;
    Result get(int argument);
};

Result S::get(int argument)
{
    Delegate* p = delegate;
    volatile unsigned int temporary = 0;
    if (!p) {
        Result result;
        result.value = p;
        return result;
    }
    return p->get(argument);
}
