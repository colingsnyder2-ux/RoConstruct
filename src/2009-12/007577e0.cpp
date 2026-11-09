// from server: 86% by atomic.potato
struct VFrame {
    void sub_757690();
    char pad_0[0x94];
    void* p94;
    void* p98;
    void destroy();
};

void VFrame::sub_757690() {
    *(void**)this = (void*)0x9e541c;
    *(void**)((char*)this + 4) = (void*)0x9e5410;
    *(void**)((char*)this + 0x18) = (void*)0x9e5404;
    *(void**)((char*)this + 0x1c) = (void*)0x9e53fc;
    *(void**)((char*)this + 0x94) = (void*)0x9e53ec;
    *(void**)((char*)this + 0x98) = (void*)0x9e53d4;
    sub_757690();
    if (*(unsigned char*)((char*)this + 8) & 1) {
        destroy();
    }
}
