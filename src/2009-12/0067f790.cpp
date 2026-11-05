// from server: 92% by atomic.potato
struct VCoordinateFrame {
    bool sub_67F4E0(void*);
    bool f(void*);
};

bool VCoordinateFrame::f(void* a) {
    char buf[16];
    *(void**)(buf + 8) = a;
    buf[3] = 1;
    *(void**)(buf + 4) = (void*)0x67e420;
    *(void**)(buf + 12) = buf + 3;
    sub_67F4E0(buf + 4);
    return buf[3];
}
