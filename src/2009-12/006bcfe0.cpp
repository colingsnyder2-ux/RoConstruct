// from server: 100% by atomic.potato
extern "C" void (__thiscall *AssignString)(void *, const char *);

struct CPropGrid
{
    void UpdateItemsJob();
};

void CPropGrid::UpdateItemsJob()
{
    AssignString((void *)0x00b922c0, (const char *)0x009d6b3c);
}
