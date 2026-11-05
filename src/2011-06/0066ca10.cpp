// from server: 100% by atomic.potato
struct Inner {
    void method();
};

struct PartInstance {
    char pad[0xac];
    Inner inner;
    char pad2[0x228 - 0xac - sizeof(Inner)];
    unsigned char flag;
    void method(int arg);
};

void PartInstance::method(int arg) {
    flag = 1;
    inner.method();
}
