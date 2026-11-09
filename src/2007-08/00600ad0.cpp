// from server: 100% by colin
struct VWidget {
    char pad0[0x20];
    void* ptr20;
    char pad24[0xC];
    float f30;
    float f34;
    void getSize(float* out);
};

void VWidget::getSize(float* out)
{
    if (f30 == 0.0f && f34 == 0.0f && ptr20 != 0) {
        void** vtbl = *(void***)ptr20;
        void (__thiscall *fn)(void*, float*) = (void (__thiscall *)(void*, float*))vtbl[1];
        float tmp[2];
        fn(ptr20, tmp);
        f30 = tmp[0];
        f34 = tmp[1];
    }
    out[0] = f30;
    out[1] = f34;
}
