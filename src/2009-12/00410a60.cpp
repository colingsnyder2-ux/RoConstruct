// from server: 92% by atomic.potato
extern "C" int __stdcall sub_007f3fce(void*);

struct CChildFrame
{
    char pad0[0x10];
    int field10;
    int field14;
    int field18;
    int field1c;
    unsigned int field20;
    int init(void* arg);
};

int CChildFrame::init(void* arg)
{
    field18 = 0;
    field1c = 0;
    field10 = 0x7fff;
    field14 = 0x7fff;
    if (sub_007f3fce(this) == 0)
        return 0;
    field20 |= 0x2000000;
    return 1;
}
