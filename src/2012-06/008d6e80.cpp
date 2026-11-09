// from server: 100% by atomic.potato
extern int G_00E55320;
extern int G_00E55318;
extern int G_00E5531C;
extern void G_009831F5(const void *);

void func_008D6E80()
{
    if ((G_00E55320 & 1) == 0)
    {
        G_00E55320 |= 1;
        G_00E55318 = 0;
        G_00E5531C = 0;
        G_009831F5((const void *)0x00B20520);
    }
}
