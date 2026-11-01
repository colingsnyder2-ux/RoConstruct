// from server: 100% by atomic.potato
struct CXTPControls
{
    int GetValue();
};

int CXTPControls::GetValue()
{
    int value = *(int*)((char*)this + 0xd0);
    if (value != 0)
        return *(int*)(value + 0x24);
    return 0;
}
