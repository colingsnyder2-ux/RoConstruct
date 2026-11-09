// from server: 47% by atomic.potato
struct EventDesc {
    char pad0[4];
    int field4;
    int init(int a, int b);
};

extern "C" int __stdcall sub_4C1670(int, int);
extern "C" int __stdcall sub_5AD350();

int EventDesc::init(int a, int b) {
    field4 = 0;
    sub_4C1670(1, 0);
    sub_5AD350();
    return a;
}
