// from server: 100% by king_originala
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
