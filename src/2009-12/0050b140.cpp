// from server: 68% by atomic.potato




struct VPlayer;

extern "C" VPlayer* __cdecl sub_4104A0(void*);
extern "C" int __cdecl sub_46D0D0(void*);

struct VPlayer {
    char pad[0x15c];
    void* field_15c;
    int method_4F5310();
};

int __cdecl sub_50B140(void* a1) {
    VPlayer* p = sub_4104A0(a1);
    if (p) {
        void* q = p->field_15c;
        if (q) {
            if (sub_46D0D0(q)) {
                return ((VPlayer*)q)->method_4F5310();
            }
        }
    }
    return 0;
}
