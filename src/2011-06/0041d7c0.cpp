// from server: 100% by atomic.potato
struct DSVideoCaptureEngine {
    char pad[0x20];
    void* field20;
    char pad2[4];
    void* field28;
    void* field2c;
    void cleanup();
    void destroy();
};

void DSVideoCaptureEngine::cleanup() {
    if (field20) {
        void** vtbl = *(void***)field20;
        void (__stdcall *fn)(void*) = (void (__stdcall*)(void*))vtbl[2];
        fn(field20);
        field20 = 0;
    }
    if (field28) {
        void** vtbl = *(void***)field28;
        void (__stdcall *fn)(void*) = (void (__stdcall*)(void*))vtbl[2];
        fn(field28);
        field28 = 0;
    }
    field20 = 0;
    field28 = 0;
    field2c = 0;
    destroy();
}
