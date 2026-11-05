// from server: 72% by atomic.potato
struct ScoreHud {
    char pad0[0xa4];
    void* field_a4;
    void* field_a8;
    void set(void* a, void* b);
};

extern "C" void* __fastcall sub_4692d0(void*);
extern "C" void* __fastcall sub_414a30(void*);

void ScoreHud::set(void* a, void* b) {
    void* v;
    if (a) {
        v = sub_4692d0(a);
    } else {
        v = 0;
    }
    field_a4 = v;
    if (a) {
        field_a8 = sub_414a30(a);
    } else {
        field_a8 = 0;
    }
}
