// from server: 100% by tester
struct ChatButton {
    int isVisible() const;
};

extern "C" void* __cdecl sub_48DFB0(void*);
extern "C" bool __cdecl sub_4915A0(void*, int);

int ChatButton::isVisible() const {
    void* p = sub_48DFB0((void*)this);
    if (p != 0 && *(int*)((char*)p + 0x1a0) != 0) {
        if (sub_4915A0((void*)this, 1)) {
            return 1;
        }
    }
    return 0;
}
