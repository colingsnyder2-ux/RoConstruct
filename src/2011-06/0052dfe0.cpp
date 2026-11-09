// from server: 100% by atomic.potato
struct ProfiledRakPeer
{
    char pad0[0xbd8];
    int value0;
    int value1;
    void set(int value0, int value1);
};

void ProfiledRakPeer::set(int value0, int value1)
{
    this->value0 = value0;
    this->value1 = value1;
}
