// from server: 100% by atomic.potato
struct CXTPHookManagerHookAble {
    int find(void* a, void* b);
};

extern "C" int __stdcall compare_key(void* a, void* b);

int CXTPHookManagerHookAble::find(void* a, void* b)
{
    void* node;
    if (b == 0)
        node = *(void**)((char*)this + 4);
    else
        node = *(void**)b;

    while (node != 0) {
        if (compare_key((char*)node + 8, &a) != 0)
            return (int)node;
        node = *(void**)node;
    }
    return 0;
}
