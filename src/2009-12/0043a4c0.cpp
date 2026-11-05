// from server: 33% by atomic.potato
struct UDimItem {
    char pad0[0x24];
    void* field24;
    void* field28;
    void method(int);
};

void UDimItem::method(int arg) {
    void* p = field24;
    if (p) {
        void* q = *(void**)((char*)p + 0x10c);
        void (*fn)(void*, int) = *(void (**)(void*, int))q;
        fn(q, arg);
    }
    p = field28;
    if (p) {
        void* q = *(void**)((char*)p + 0x10c);
        void (*fn)(void*, int) = *(void (**)(void*, int))q;
        fn(q, arg);
    }
}
