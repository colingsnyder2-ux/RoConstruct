// from server: 100% by atomic.potato
struct Inner {
    virtual bool check();
    virtual bool other();
    virtual bool third();
    virtual bool fourth();
};

struct S {
    int pad0[0x2f];
    Inner* items[4];
    int count;
    bool f();
};

bool S::f() {
    int i = 0;
    if (count > 0) {
        Inner** p = items;
        do {
            if (p[0]->fourth())
                return true;
            ++i;
            ++p;
        } while (i < count);
    }
    return false;
}
