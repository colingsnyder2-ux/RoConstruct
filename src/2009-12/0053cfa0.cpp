// from server: 68% by atomic.potato
struct ChangePropertyItem {
    void sub_53CFA0();
};

extern "C" void __stdcall sub_533810(int, void*);
extern "C" void __stdcall sub_53BD00(void*);

void ChangePropertyItem::sub_53CFA0() {
    unsigned short buf[2];
    buf[0] = 0;
    buf[1] = 0;
    sub_533810(*(int*)((char*)this + 4), buf);
    if (*(int*)((char*)this + 4) != 0) {
        sub_53BD00(buf);
    }
}
