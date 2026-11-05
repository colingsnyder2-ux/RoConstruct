// from server: 83% by Intel
struct boost_exception {
    void* vtable;
    void* field_4;
    void* field_8;
    void* field_C;
    void destroy();
};

extern "C" void* __stdcall GetProcessHeap();
extern "C" int __stdcall HeapFree(void* hHeap, unsigned int dwFlags, void* lpMem);

void boost_exception::destroy() {
    this->vtable = (void*)0x00C0CD98;
    void* ptr = this->field_8;
    if (ptr) {
        void* vtable_ptr = *(void**)ptr;
        void (*destructor)(void*) = *(void (**)(void*))((char*)vtable_ptr + 8);
        destructor(ptr);
    }
    if (this->field_C) {
        void* heap = GetProcessHeap();
        if (heap) {
            HeapFree(heap, 0, this->field_C);
        }
    }
}
