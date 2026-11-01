// from server: 100% by king_originala
struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual int get(int value);
};

struct Result {
    void set(const int* value);
};

struct S {
    char padding[28];
    Source* source;
    void f(int value, Result* result);
};

void S::f(int value, Result* result)
{
    value = source->get(value);
    result->set(&value);
}
