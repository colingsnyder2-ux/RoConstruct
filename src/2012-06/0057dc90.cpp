// from server: 27% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int);
extern "C" void __cdecl sub_814bf0(void*);

struct VManualGlue {
    void sub_57dc20(void*, void*);
    void __cdecl sub_57dc90(void*);
};

void VManualGlue::sub_57dc90(void* arg) {
    void* p = sub_98211a(0xac);
    if (p) {
        sub_814bf0(p);
    } else {
        p = 0;
    }
    sub_57dc20(p, arg);
}
