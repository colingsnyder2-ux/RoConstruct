// from server: 100% by tester
struct RakPeer
{
    static void shiftRight(RakPeer* peer);
};

void RakPeer::shiftRight(RakPeer* peer)
{
    unsigned int* p = (unsigned int*)peer;
    unsigned int carry = 0;
    for (int i = 7; i >= 0; --i)
    {
        unsigned int v = p[i];
        p[i] = (v >> 1) | carry;
        carry = v << 31;
    }
}
