// from server: 100% by atomic.potato
struct Sub {
    void f(const char*, const char*, int);
};

struct RakPeer {
    void m(const char*, const char*);
};

void RakPeer::m(const char* a, const char* b)
{
    if (a == 0 || *a == 0 || b == 0)
        return;
    ((Sub*)((char*)this + 0x6fc))->f(a, b, 0);
}
