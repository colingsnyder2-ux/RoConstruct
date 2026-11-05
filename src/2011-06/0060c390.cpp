// from server: 61% by atomic.potato
struct VCoordinateFrame {
    char pad[0x10];
    char f(int);
};

extern "C" void __stdcall sub_60C260(void*, void*);

char VCoordinateFrame::f(int a) {
    char buf[0x10];
    *(int*)(buf + 8) = a;
    *(int*)(buf + 4) = 0x60b160;
    buf[3] = 1;
    sub_60C260(buf + 4, buf + 3);
    return buf[3];
}
