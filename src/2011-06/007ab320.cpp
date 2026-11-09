// from server: 49% by atomic.potato
extern "C" void __cdecl free(void*);

struct CornerWedgePoly
{
    void clear();
};

void CornerWedgePoly::clear()
{
    void** p = (void**)this;

    if (*p)
    {
        for (;;)
        {
            void* value = *p;
            void* next = *(void**)((char*)value + 0x18);

            if (value)
            {
                free(value);
                *p = 0;
            }

            *p = next;

            if (!next)
                break;
        }
    }
}
