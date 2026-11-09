// from server: 39% by atomic.potato
struct CMap {
    char pad[0x100];
    int count;
    void** items;
    void* Find(void* key, void* arg);
};

extern "C" int (__stdcall *g_fn)(void*, void*, void*);

void* CMap::Find(void* key, void* arg) {
    int i = 0;
    if (count <= 0) {
        return 0;
    }
    while (i >= 0 && i < count) {
        void* item = items[i];
        if (g_fn(item, key, arg) != 0) {
            return item;
        }
        i++;
        if (i >= count) {
            break;
        }
    }
    return 0;
}
