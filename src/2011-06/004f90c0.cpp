// from server: 54% by atomic.potato




extern "C" int __stdcall sub_80b2ea(int, int, int, int, int);
extern "C" int __stdcall sub_80b0ac(int, int);
extern "C" void __stdcall sub_a40a10(int);

struct SendDataJob {
    void* vtable;
    int field4;
    void SendData(int);
};

void SendDataJob::SendData(int arg) {
    int result = sub_80b2ea(*(int*)this, 0, 0xc079e4, 0xc2aba8, 0);
    if (result == 0) {
        char buf[8];
        sub_a40a10((int)buf);
        sub_80b0ac((int)buf, 0xb989fc);
    }
    int* p = *(int**)(result + 0x1c);
    int* vt = *(int**)p;
    int (*fn)(int*, int, int) = (int (*)(int*, int, int))vt[3];
    fn(p, *(int*)((char*)this + 4), arg);
}
