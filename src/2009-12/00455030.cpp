// from server: 78% by atomic.potato
extern "C" int __cdecl pubsync(char*);

int func_00455030(void* p)
{
    return pubsync(*(char**)p + 4);
}
