// from server: 47% by atomic.potato
struct CRobloxView {
    char pad[0x58];
    void* m_map;
    void insert(void* key, void* value);
};

struct MapHelper {
    void* insert(void** value);
};

extern "C" void* __stdcall getLocalScope_005943f0();

void CRobloxView::insert(void* key, void* value)
{
    void* v;
    if (key != 0) {
        v = *(void**)((char*)key + 4);
    } else {
        v = getLocalScope_005943f0();
    }
    void* slot = ((MapHelper*)&m_map)->insert(&value);
    *(void**)slot = v;
}
