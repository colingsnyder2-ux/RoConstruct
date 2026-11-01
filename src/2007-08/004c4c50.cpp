// from server: 100% by colin
struct RakPeer {
    long long getLastTimeBetweenPacketsIncrease();
};

long long RakPeer::getLastTimeBetweenPacketsIncrease()
{
    return *(long long*)((char*)this + 0x500);
}
