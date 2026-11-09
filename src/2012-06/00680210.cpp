// from server: 81% by colin
struct AncestryChangedSignalData {
    void invoke(void* a, void* b);
};

void AncestryChangedSignalData::invoke(void* a, void* b)
{
    void* node = *(void**)((char*)a + 4);
    while (node) {
        void** vtbl = *(void***)this;
        void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl[0x50/4];
        fn(this, node, b);
        node = *(void**)node;
    }
}
