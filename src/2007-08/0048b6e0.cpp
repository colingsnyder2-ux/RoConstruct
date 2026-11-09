// from server: 49% by colin
struct Creator {
    void* field0;
    Creator(const void* arg, int dummy);
};

extern "C" void* __cdecl operator_new(unsigned int size);

Creator::Creator(const void* arg, int dummy) {
    field0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)((char*)p + 0) = (void*)0x79b01c;
        *(const void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
