// from server: 57% by atomic.potato
struct Target {
    void method(int);
};

struct EventDesc {
    char pad[0x38];
    void* field38;
    void func(int a, int b);
};

void EventDesc::func(int a, int b) {
    int offset = 0;
    if (a) {
        offset = a - 0x1c;
    }
    ((Target*)((char*)field38 + offset))->method(b);
}
