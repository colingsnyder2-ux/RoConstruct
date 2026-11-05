// from server: 26% by atomic.potato
struct X_006963a0 {
    char pad_0[0x8c];
    void* f_8c;
    char pad_90[0x18];
    void* f_a8;
    void dtor();
};

void func_006749e0();
void func_004d1460();
void func_005d2b60();
void func_00718a32();

void X_006963a0::dtor()
{
    *(void**)this = (void*)0x8e7b7c;
    *(void**)((char*)this + 0x14) = (void*)0x8e7b70;
    *(void**)((char*)this + 0x18) = (void*)0x8e7b68;
    *(void**)((char*)this + 0x20) = (void*)0x8e7b60;
    f_8c = (void*)0x8e7b48;
    if (f_a8) {
        func_004d1460();
        func_00718a32();
    }
    func_006749e0();
    *(void**)this = (void*)0x8e7a84;
    *(void**)((char*)this + 0x14) = (void*)0x8e7a74;
    *(void**)((char*)this + 0x18) = (void*)0x8e7a6c;
    *(void**)((char*)this + 0x20) = (void*)0x8e7a64;
    func_005d2b60();
}

void func_006963a0(X_006963a0* x)
{
    x->dtor();
}
