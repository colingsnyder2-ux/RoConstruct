// from server: 100% by tajop
struct Target {
};

typedef void (Target::*Pmf)(void*, int, int, int);

struct Bucket {
    Bucket* next_;
};

struct ValueBase {
    void* value;
};

struct Node : ValueBase, Bucket {
};

struct Iter {
    Bucket* bucket_;
    Bucket* node_;
};

struct Func {
    Pmf f;
    Target* t;
    int a1;
    int a2;
    int a3;

    void operator()(void* x) {
        (t->*f)(x, a1, a2, a3);
    }
};

Func for_each_value(Iter first, Iter last, Func fn) {
    Iter end = last;
    Bucket* node = first.node_;
    Bucket* bucket = first.bucket_;
    for (; node != end.node_; ) {
        fn(static_cast<Node*>(node)->value);
        node = node->next_;
        while (!node) {
            node = bucket[1].next_;
            ++bucket;
        }
    }
    return fn;
}
