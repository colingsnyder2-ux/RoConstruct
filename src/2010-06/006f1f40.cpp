// from server: 100% by atomic.potato
struct VPlayers {
    char pad[4];
    bool sub_006f1d70(void*);
    bool sub_006f05e0(void*);
    int func_006f1f40(void*);
};

int VPlayers::func_006f1f40(void* a)
{
    if (sub_006f1d70(a))
        return sub_006f05e0(a) ? 1 : 2;
    return 0;
}
