// from server: 50% by atomic.potato
struct ProfiledRakPeer
{
    char pad0[0x998];
    char value;
    int f();
};

int ProfiledRakPeer::f()
{
    if (value == 0)
        return 0;

    int result = 1;
    while (pad0[0x998 + result * 0x10] != 0)
        ++result;
    return result;
}
