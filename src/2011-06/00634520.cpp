// from server: 88% by atomic.potato
struct Tool {
    char padding[0x1f4];
    int field1f4;
    void method(int value);
};

extern "C" void __cdecl sub_6343b0(Tool *, int);
extern "C" void __cdecl sub_411f60(Tool *, const char *);

void Tool::method(int value) {
    if (value != field1f4) {
        sub_6343b0(this, value);
        sub_411f60(this, "QSUVW");
    }
}
