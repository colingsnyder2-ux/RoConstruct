// from server: 35% by atomic.potato
struct VPlayerBoundFuncDesc {
    void construct();
    void invoke();
};

extern "C" void __stdcall sub_41C610();
extern "C" void __stdcall sub_508760();

void VPlayerBoundFuncDesc::construct()
{
    char pad[8];
    int flag = 0;
    char buf[0x20];
    *(int*)buf = 0;
    int* p = (int*)(buf + 0x20);
    int arg = *(int*)((char*)&pad + 0x3c);
    *(int*)(buf + 0x30) = 1;
    *(void**)(buf + 0x24) = buf;
    if (arg == 0) {
        *(int*)buf = arg;
        int* q = (int*)(buf + 0x20);
        int vt = *(int*)arg;
        void* r = (void*)(buf + 0x28);
        ((void (__stdcall*)(void*, void*, int))vt)(r, q, 0);
    }
    sub_41C610();
    int a = *(int*)((char*)&pad + 0x38);
    int b = *(int*)((char*)&pad + 0x34);
    sub_508760();
    int* v = *(int**)(buf + 0x1c);
    *(int*)(buf + 0x04) = 1;
    *(char*)(buf + 0x14) = 0;
    if (v != 0) {
        int vt2 = *(int*)v;
        if (vt2 != 0) {
            void* r2 = (void*)(buf + 0x2c);
            ((void (__stdcall*)(void*, void*, int))vt2)(r2, r2, 2);
        }
    }
}
