// from server: 49% by colin
struct Creator {
    int field0;
    Creator(int arg0, int arg1);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

Creator::Creator(int arg0, int arg1)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)((char*)p + 0) = 0x787ac4;
        *(int*)((char*)p + 0xc) = arg0;
    } else {
        p = 0;
    }
    field0 = (int)p;
}
