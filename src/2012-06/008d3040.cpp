// from server: 100% by atomic.potato
extern "C" void __cdecl sub_9831f5(void *);

unsigned long g_e5507c;
unsigned long g_e55074;
unsigned long g_e55078;

void sub_8d3040()
{
    if (g_e5507c & 1)
        return;

    g_e5507c |= 1;
    g_e55074 = 0;
    g_e55078 = 0;
    sub_9831f5((void *)0x00b20350);
}
