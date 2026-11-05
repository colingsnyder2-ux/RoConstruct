// from server: 100% by king_originala
struct Access {
    virtual void slot0();
    virtual void slot1();
    virtual int get(int);
};

struct Result {
    void assign(const int*);
};

struct Descriptor {
    unsigned char padding[28];
    Access* access;

    void read(int, Result*);
};

void Descriptor::read(int value, Result* result)
{
    value = access->get(value);
    result->assign(&value);
}
