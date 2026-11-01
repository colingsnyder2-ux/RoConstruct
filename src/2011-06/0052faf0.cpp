// from server: 100% by atomic.potato
extern "C" void __stdcall sub_0052ee70(void *, const char *, unsigned int);

struct ProfiledRakPeer_52ee70 {
    void Report(void *obj, const char *file, unsigned int line);
};

struct S_0052faf0 {
    void f(void *arg);
};

void S_0052faf0::f(void *arg)
{
    ((ProfiledRakPeer_52ee70 *)((char *)this + 0x50))->Report(arg, (const char *)0x00a7f220, 0xc33);
}
