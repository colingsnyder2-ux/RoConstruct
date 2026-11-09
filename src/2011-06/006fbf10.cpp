// from server: 71% by atomic.potato
struct Flag
{
    int value;
    bool IsEnabled(Flag* flag);
};

bool Flag::IsEnabled(Flag* flag)
{
    if (*((unsigned char*)flag + 0x9c) != 0)
        return false;
    return *((int*)((unsigned char*)flag + 0x98)) != *((int*)((unsigned char*)this + 0x264));
}
