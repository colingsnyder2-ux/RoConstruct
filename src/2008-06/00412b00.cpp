// from server: 100% by atomic.potato
extern "C" int __stdcall sub_6a0e06(void* p);

int __stdcall func_00412b00(void* p)
{
    int* q = (int*)p;
    q[6] = 0;
    q[7] = 0;
    q[4] = 0x7fff;
    q[5] = 0x7fff;
    if (sub_6a0e06(p) == 0)
        return 0;
    q[8] |= 0x2000000;
    return 1;
}
