// from server: 86% by atomic.potato
extern "C" int __cdecl fflush(void*);

int FlushIfPresent(void* p)
{
    if (p != 0)
    {
        p = *(void**)((char*)p + 0x54);
        if (p != 0)
            return fflush(p);
    }
    return 0;
}
