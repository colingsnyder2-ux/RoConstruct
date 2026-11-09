// from server: 51% by atomic.potato
struct Creator
{
    void assign(unsigned short a, const char* b);
};

void Creator::assign(unsigned short a, const char* b)
{
    *(unsigned short*)this = a;
    *(unsigned short*)((char*)this + 0x24) = 0;
    if (b != 0)
    {
        char* p = (char*)this + 2;
        do
        {
            *p = *b;
            p++;
            b++;
        } while (*(b - 1) != 0);
        *(int*)((char*)this + 0x28) = 0;
        *(unsigned short*)((char*)this + 0x22) = 2;
    }
    else
    {
        *((char*)this + 2) = 0;
        *(int*)((char*)this + 0x28) = 0;
        *(unsigned short*)((char*)this + 0x22) = 2;
    }
}
