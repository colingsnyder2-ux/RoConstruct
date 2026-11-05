// from server: 100% by atomic.potato
struct SleepStage {
    void sub_7602B0(void*, int);
    void sub_75F150(void*, int);
    void func(void*);
};

void SleepStage::func(void* a) {
    int v = *(int*)((char*)a + 8);
    int r = (*(int (__thiscall**)(void*))(*(int*)a + 0x10))(a);
    if (r == 1) {
        if (v == 4) {
            sub_7602B0(a, 3);
            return;
        }
        if (v == 2) {
            sub_7602B0(a, 1);
            return;
        }
    } else {
        if (v == 2) {
            sub_75F150(a, 1);
        }
    }
}
