// from server: 100% by colin
namespace ns_ROCX000009 {
// from server: 100% by atomic.potato
struct UTupleHolder {
    void* ptr;
    char pad[4];
    void destroy();
};

void UTupleHolder::destroy() {
    void* p = ptr;
    if (p != 0) {
        void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))p;
        void* arg = (void*)((char*)this + 8);
        if (fn != 0) {
            fn(arg, arg, (void*)2);
        }
        ptr = 0;
    }
}
}
