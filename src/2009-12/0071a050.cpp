// from server: 100% by atomic.potato
struct EventDescFunc_0071a050
{
    char pad0[208];
    void* m_p;
    int get();
};

int EventDescFunc_0071a050::get()
{
    char* p = (char*)m_p;
    p = *(char**)(p + 36);
    return *(int*)(p + 148);
}
