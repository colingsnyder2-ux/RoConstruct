// from server: 100% by atomic.potato
struct Chunk {
    int field0;
    int field4;
    int field8;
    void init(int a, int b, int c);
};

extern "C" char __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void Chunk::init(int a, int b, int c) {
    int local[3];
    local[0] = a;
    local[1] = b;
    local[2] = c;
    if (!sub_4879D0(local)) {
        this->field8 = 0x4d2d30;
        this->field0 = 0x4d23b0;
        void* p = sub_62FEF6(0xc);
        if (p) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
            *(int*)((char*)p + 8) = local[2];
        }
        this->field4 = (int)p;
    }
}
