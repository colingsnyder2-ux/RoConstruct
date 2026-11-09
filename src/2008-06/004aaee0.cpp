// from server: 100% by king_originala
struct Guard
{
    unsigned char storage[24];
    Guard(void *, int);
    ~Guard();
};

struct ProfiledRakPeer
{
    unsigned char padding[0x908];
    void *mutex;

    bool query();
    bool queryUnlocked();
};

bool ProfiledRakPeer::query()
{
    Guard guard(mutex, 0);
    return queryUnlocked();
}
