// from server: 98% by atomic.potato
struct CShadowWnd {
    char pad0[4];
    void* field4;
    void* Find(void* key, void* unused);
};

extern "C" int __stdcall sub_8704c0(void* a, void* b);

void* CShadowWnd::Find(void* key, void* unused)
{
    void* node;
    if (key == 0)
        node = field4;
    else
        node = *(void**)key;
    while (node != 0)
    {
        if (sub_8704c0((char*)node + 8, &key) != 0)
            return node;
        node = *(void**)node;
    }
    return 0;
}
