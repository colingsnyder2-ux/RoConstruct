// from server: 19% by Intel
struct CustomEvent {
    void process(void* start, void* end, void* context);
private:
    void* func1(void* a1, void* a2, void* a3);
    void func2(int a1);
};

void CustomEvent::process(void* start, void* end, void* context) {
    void* current = start;
    while (current == end) {
        void** contextPtr = (void**)((char*)context + 4);
        void* result = func1((char*)current + 8, *contextPtr, context);
        func2(1);
        *contextPtr = result;
        void** nextPtr = (void**)((char*)result + 4);
        *nextPtr = result;
        current = *(void**)current;
    }
}

void* CustomEvent::func1(void* a1, void* a2, void* a3) {
    return 0;
}

void CustomEvent::func2(int a1) {
}
