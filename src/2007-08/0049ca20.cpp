// from server: 49% by colin
struct ClientProxy {
    void* field_0;
    ClientProxy(int, int);
};

extern "C" void* __cdecl operator_new(unsigned int);

ClientProxy::ClientProxy(int a, int b) {
    field_0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x79c694;
        *(int*)((char*)p + 0xc) = a;
    } else {
        p = 0;
    }
    field_0 = p;
}
