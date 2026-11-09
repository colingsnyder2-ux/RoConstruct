// from server: 84% by atomic.potato
struct VHumanoid {
    char pad[0x44];
    void* field44;
};

extern "C" void* __cdecl sub_80B2EA(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_67F2F0(void*);

void* __cdecl sub_6802A0(VHumanoid* p) {
    if (p != 0) {
        void* q = p->field44;
        if (q != 0) {
            void* r = sub_80B2EA(q, 0, (void*)0xC071F8, (void*)0xC1A934, 0);
            if (r != 0) {
                return sub_67F2F0(r);
            }
        }
    }
    return 0;
}
