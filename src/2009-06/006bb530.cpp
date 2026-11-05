// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Result {
    int value;
    Result(const Result&);
    ~Result();
};

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual Result get(int) = 0;
};

struct S {
    char padding[24];
    Interface* object;
    Result get(int);
};

Result S::get(int index) {
    return object->get(index);
}