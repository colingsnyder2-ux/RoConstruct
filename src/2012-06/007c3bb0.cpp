// from server: 66% by atomic.potato
struct MegaClusterInstance
{
    int GetValue();
};

int MegaClusterInstance::GetValue()
{
    int value = *(int *)((char *)this + 0x198);
    value = *(int *)((char *)value + 0xe4);
    if (value == 0)
        return 0;

    value = *(int *)((char *)value + 0xa4);
    if (value == 0)
        return 0;

    return value;
}
