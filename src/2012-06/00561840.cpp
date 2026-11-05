// from server: 100% by atomic.potato
struct Creator
{
    int equals(const Creator* other);
};

int Creator::equals(const Creator* other)
{
    if (*(unsigned short*)this == 2 &&
        *(int*)((char*)this + 4) == *(int*)((char*)other + 4))
        return 1;
    return 0;
}
