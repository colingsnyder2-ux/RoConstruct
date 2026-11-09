// from server: 15% by Intel
struct AdornBillboarder {
    void* vtable[4];
    void* field_10;
    void render(float, float, float, float, float, float);
};

void AdornBillboarder::render(float a1, float a2, float a3, float a4, float a5, float a6) {
    void* this_ptr = this;
    void* vtable_ptr = *(void**)((char*)this_ptr + 0x10);
    void (*func)(float, float, float, float, float, float) = (void(*)(float, float, float, float, float, float))*(void**)((char*)vtable_ptr + 0x40);
    func(a1, a2, a3, a4, a5, a6);
}
