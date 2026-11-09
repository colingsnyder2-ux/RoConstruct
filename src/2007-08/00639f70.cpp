// from server: 100% by colin
struct Inner {
    int method();
};

struct CXTPControl {
    char pad[0xfc];
    Inner* ptr;
    int get();
};

int CXTPControl::get() {
    if (ptr)
        return ptr->method();
    return 0;
}
