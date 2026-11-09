// from server: 100% by colin
struct DeleteInstanceItem {
    int field0;
    int field4;
    int field8;
    void write(int a, int b);
};

extern "C" char __cdecl sub_4879D0(int* a);
extern "C" void* __cdecl sub_62FEF6(unsigned int size);

void DeleteInstanceItem::write(int a, int b)
{
    int local[2];
    local[0] = a;
    local[1] = b;
    if (!sub_4879D0(local)) {
        this->field8 = 0x4aa3f0;
        this->field0 = 0x4a91a0;
        void* p = sub_62FEF6(8);
        if (p) {
            *(int*)p = local[0];
            *(int*)((char*)p + 4) = local[1];
        }
        this->field4 = (int)p;
    }
}
