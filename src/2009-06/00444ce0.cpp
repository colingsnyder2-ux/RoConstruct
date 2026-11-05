// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Result {
    Result(const Result&);
    ~Result();
    int value;
};

struct Interface {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual Result get(int) = 0;
};

struct S {
    Interface* object;
    int argument;
    Result get();
};

Result S::get() {
    return object->get(argument);
}