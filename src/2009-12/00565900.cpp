// from server: 78% by atomic.potato
struct RakPeer
{
    unsigned char pad0[8];
    unsigned short count;

    int GetCount();
};

int RakPeer::GetCount()
{
    unsigned int result = 0;
    unsigned int n = count;

    if (n != 0)
    {
        unsigned char* p = *(unsigned char**)((char*)this + 0x53c);
        do
        {
            if (*p != 0)
                ++result;
            p += 0x13d0;
        } while (--n != 0);
    }

    return result;
}
