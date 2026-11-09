// from server: 63% by atomic.potato
struct DecalTool
{
    void f(void*);
    void (**vfunc)(void*);
};

void DecalTool::f(void* arg)
{
    int value = *(int*)((char*)arg + 0x14);
    if (value == 0x7f || value == 0x1b)
        (*vfunc)((char*)this + 0x4c);
}
