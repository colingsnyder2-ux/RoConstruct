// from server: 100% by king_originala
struct Argument {
    char padding[8];
    int key;
    void* value;
};

struct S {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual bool dispatch(int, void*);

    char padding[20];
    int key;

    bool f(int, Argument*);
};

bool S::f(int first, Argument* argument)
{
    if (argument->key != key)
        return false;
    return dispatch(first, argument->value);
}
