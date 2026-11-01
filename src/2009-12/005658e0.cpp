// from server: 100% by atomic.potato
struct RakPeer {
    void f(unsigned short value);
};

void RakPeer::f(unsigned short value)
{
    *(unsigned short*)((char*)this + 10) = value;
}
