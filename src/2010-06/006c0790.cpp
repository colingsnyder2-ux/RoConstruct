// from server: 100% by atomic.potato
struct X_006c0790 {
    char pad_0[0x98];
    int f_98;
    void assign(int* a, int* b);
};

extern "C" void* __fastcall sub_00469fb0(void*);
extern "C" void* __fastcall sub_0046a180(void*);

void X_006c0790::assign(int* a, int* b) {
    if (a) {
        void* p = sub_00469fb0(a);
        if (p) {
            if (*(int*)((char*)p + 0x98) == f_98) {
                *(int*)((char*)p + 0x98) = 0;
            }
        }
    }
    if (b) {
        void* q = sub_0046a180(b);
        if (q) {
            *(int*)((char*)q + 0x98) = f_98;
        }
    }
}
