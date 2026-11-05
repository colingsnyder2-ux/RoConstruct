// from server: 100% by atomic.potato
struct Inner {
    void method();
    char pad[0xd0];
};

struct Outer {
    char pad[0x2c8];
    Inner* field;
    char* get();
};

char* Outer::get() {
    Inner* p = field;
    p->method();
    return (char*)p + 0xd0;
}
