// from server: 49% by colin
struct Creator {
    void* field0;
    Creator(int arg0, int arg1);
};

void* __cdecl sub_62FEF6(unsigned int size);

Creator::Creator(int arg0, int arg1)
{
    field0 = 0;
    void* mem = sub_62FEF6(0x14);
    if (mem != 0) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(int*)((char*)mem + 0) = 0x79afa4;
        *(int*)((char*)mem + 0xc) = arg0;
    } else {
        mem = 0;
    }
    field0 = mem;
}
