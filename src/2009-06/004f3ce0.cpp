// from server: 33% by atomic.potato
extern "C" void __stdcall helper_004806f0();
extern "C" void __stdcall helper_004f36b0();

struct EventSource {
    void* func_004f3ce0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
};

void* EventSource::func_004f3ce0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j)
{
    char pad[8];
    int local0 = 0;
    char buf[32];
    *(int*)buf = 0;
    int* p = (int*)buf;
    if (a != 0) {
        *p = a;
        int* q = (int*)a;
        int fn = *q;
        p += 2;
        ((void (__stdcall*)(int, int*, int*))fn)(0, p, (int*)((char*)&local0 + 0x10));
    }
    helper_004806f0();
    helper_004f36b0();
    int* r = (int*)local0;
    if (r != 0) {
        int fn2 = *r;
        if (fn2 != 0) {
            ((void (__stdcall*)(int, int*, int*))fn2)(2, (int*)((char*)&local0 + 0x18), (int*)((char*)&local0 + 0x18));
        }
    }

    return this;
}
