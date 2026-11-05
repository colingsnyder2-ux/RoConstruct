// from server: 100% by atomic.potato
struct VirtualUser
{
    void SetValue(unsigned char value);
};

void VirtualUser::SetValue(unsigned char value)
{
    *(unsigned char*)((char*)this + 0xbc) = value;
}
