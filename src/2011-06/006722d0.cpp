// from server: 63% by atomic.potato
struct VPartInstance_EventDesc {
    char pad0[0x28];
    int offset28;
    int offset2c;
    int method(int, int, int);
};

int VPartInstance_EventDesc::method(int a, int b, int c)
{
    int local = 0;
    if (a == 0) {
        *(int*)b = 0;
        return local;
    }
    int edi = offset2c;
    int edx = *(int*)(a + 0x78);
    edx = *(int*)(edx + edi);
    edx += offset28;
    int ecx = edx + a + 0x78;
    extern int __stdcall sub_4c18a0(int, int, int);
    sub_4c18a0(ecx, b, c);
    return b;
}
