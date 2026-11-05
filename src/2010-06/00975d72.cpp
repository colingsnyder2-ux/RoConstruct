// from server: 36% by atomic.potato
struct RBX_RightAngleRampBuilder {
    char pad0[0x10];
    char* end;
    void sub_975A90(void*, void*, void*);
    void sub_975A00(void*, int, void*, void*);
    void sub_9759D0(void*, void*, void*);

    void sub_975D72(void* a, int b, void* c, void* d);
};

extern "C" void __stdcall sub_7A89B2(int, int);
extern "C" void __stdcall sub_975920(void*, void*, void*);

void RBX_RightAngleRampBuilder::sub_975D72(void* a, int b, void* c, void* d) {
    sub_7A89B2(0, 0);
    char* ecx = (char*)b;
    int eax = (int)((char*)end - ecx) >> 4;
    float tmp[4];
    float* src = (float*)d;
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];
    if (eax < (int)c) {
        int off = (int)c << 4;
        sub_975A90(this, end, ecx + off);
        int eax2 = *(int*)((char*)this + 0x10);
        int edx = (eax2 - (int)ecx) >> 4;
        int edi = (int)c - edx;
        sub_975A00(this, eax2, (void*)edi, tmp);
        *(int*)((char*)this + 0x10) += off;
        int esi = *(int*)((char*)this + 0x10) - off;
        sub_975920(ecx, (void*)esi, tmp);
    } else {
        int off = (int)c << 4;
        int edi = (int)end - off;
        sub_975A90(this, (void*)edi, end);
        *(int*)((char*)this + 0x10) = eax;
        sub_9759D0(ecx, (void*)edi, end);
        sub_975920(ecx, ecx + off, tmp);
    }
}
