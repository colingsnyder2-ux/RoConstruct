// from server: 100% by colin
struct MD5HasherImpl {
    void* field0;
    void* field4;
    void* field8;
    void construct(int a, int b);
};

extern "C" char __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void MD5HasherImpl::construct(int a, int b) {
    int local[2];
    local[0] = a;
    local[1] = b;
    if (sub_4879D0(local) == 0) {
        field8 = (void*)0x5466B0;
        field0 = (void*)0x5463C0;
        void* p = sub_62FEF6(8);
        if (p != 0) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
        }
        field4 = p;
    }
}
