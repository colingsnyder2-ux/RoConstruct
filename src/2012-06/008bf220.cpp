// from server: 45% by atomic.potato
extern "C" int __cdecl sub_8bf150(int);

extern "C" int __cdecl sub_8befd0();

struct SpatialFilter {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int f();
};

int SpatialFilter::f() {
    int value = field10;
    if (value == 0)
        return sub_8bf150(1);
    value -= 1;
    if (value == 0)
        return sub_8bf150(4);
    value -= 1;
    if (value == 0)
        return sub_8bf150(1);
    return sub_8befd0();
}
