// from server: 94% by atomic.potato
struct CSettingsPropGrid {
    bool sub_460400(int, void*);
    void* sub_4125d0();

    void sub_4a6020(int a, void* b);
};

extern "C" bool __stdcall sub_6c80f0(void*, void*);

void CSettingsPropGrid::sub_4a6020(int a, void* b) {
    void* p = sub_4125d0();
    void* q = *(void**)((char*)b + 0x14);
    if (sub_6c80f0(q, p)) {
        sub_460400(a, b);
    }
}
