// from server: 100% by atomic.potato
struct ContactConnector
{
    int* Get(void* value);
};

int* ContactConnector::Get(void* value)
{
    if (value == 0)
        return *(int**)((char*)this + 0x24);
    return *(int**)((char*)this + 0x28);
}
