// from server: 82% by atomic.potato
struct BoundPropGetSet
{
    int get(void *value);
};

int BoundPropGetSet::get(void *value)
{
    unsigned char *p = (unsigned char *)value;
    if (p)
        p -= 0x1c;
    else
        p = 0;
    unsigned int index = *(unsigned int *)(p + 0x98);
    unsigned int offset = *(unsigned int *)((unsigned char *)this + 0xc);
    unsigned int base = *(unsigned int *)((unsigned char *)this + 8);
    unsigned int table = *(unsigned int *)(index + 0x98);
    unsigned int entry = *(unsigned int *)(table + offset);
    return *(int *)(entry + (unsigned int)p + 0x98);
}
