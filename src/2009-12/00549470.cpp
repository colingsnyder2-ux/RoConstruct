// from server: 12% by atomic.potato
struct S
{
    void DeleteInstanceItem();
};

void S::DeleteInstanceItem()
{
    volatile unsigned char *p = (volatile unsigned char *)0x549326;
    *p = *p;
}
