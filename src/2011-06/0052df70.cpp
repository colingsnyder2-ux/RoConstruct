// from server: 35% by atomic.potato
struct ProfiledRakPeer {
    int f(char *args);
};

extern "C" int __stdcall sub_52DEC0(void *self, char *args);

int ProfiledRakPeer::f(char *args)
{
    char buf[32];
    int i;
    for (i = 0; i < 8; ++i)
        ((int*)buf)[i] = ((int*)args)[i];

    int *p = (int*)sub_52DEC0(this, buf);
    if (p == 0)
        return 0;

    int r = ((int (__thiscall*)(void*))((int*)*p)[6])(p);
    if (r == 0)
        return (int)p;

    return ((int (__thiscall*)(void*))((int*)*p)[6])(p);
}
