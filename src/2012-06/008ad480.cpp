// from server: 65% by atomic.potato
struct RBXFlag
{
    int GetFlag(void *);
};

int RBXFlag::GetFlag(void *value)
{
    unsigned char *p = (unsigned char *)value;
    if (p[0x8c] == 0)
        return 0;
    return *(int *)(p + 0x88) != *(int *)((char *)this + 0x280);
}
