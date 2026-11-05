// from server: 26% by atomic.potato
struct RbxManualResourceLoaderChain {
    void* field0;
    void* field4;
    void destroy();
};

void RbxManualResourceLoaderChain::destroy() {
    void** list = &field4;
    while (*list) {
        void* node = *list;
        *list = *(void**)((char*)node + 4);
        *(void**)((char*)node + 4) = node;
        void** vtbl = *(void***)node;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
        fn(node, 1);
    }
    if (this) {
        void** vtbl = *(void***)this;
        void (*fn)(void*, int) = (void (*)(void*, int))vtbl[0];
        fn(this, 1);
    }
}
