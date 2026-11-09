// from server: 63% by atomic.potato
struct Creator
{
    void initialize();
};

void Creator::initialize()
{
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 12) = 0;
    *(unsigned short*)((char*)this + 0) = 2;
    *(unsigned short*)((char*)this + 18) = 0xffff;
    *(unsigned short*)((char*)this + 16) = 0;
}
