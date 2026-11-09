// from server: 60% by atomic.potato
struct CRobloxWnd {
    static void RenderJob(void** begin, void** end, void* a, void* b, void* c, void* d, void (__stdcall *callback)(void*));
};

void CRobloxWnd::RenderJob(void** begin, void** end, void* a, void* b, void* c, void* d, void (__stdcall *callback)(void*)) {
    for (; begin != end; begin += 2) {
        callback((char*)*begin + (int)b);
    }
    
    *(void**)a = b;
    *((void**)a + 1) = c;
    *((void**)a + 2) = d;
    *((void**)a + 3) = *(void**)((char*)&d + 4);
}
