// from server: 100% by atomic.potato
extern "C" void G_00631ee0(int, int, int);

void G_00632710(int a, void* p, int type)
{
    if (type != 4)
    {
        G_00631ee0(a, (int)p, type);
        return;
    }

    *(int*)p = 0x00C4F6C0;
    *((char*)p + 4) = 0;
    *((char*)p + 5) = 0;
}
