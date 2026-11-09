// from server: 20% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_68F330();
extern "C" void __stdcall sub_68D440();

void S::f()
{
    char buf[0x20];
    *(int*)buf = 0;
    int* p = (int*)buf;
    int arg = *(int*)((char*)&arg + 0x44);
    *(int*)((char*)buf + 0x34) = 1;
    *(void**)((char*)buf + 0x28) = buf;
    if (arg != 0) {
        *(int*)p = arg;
        int* q = (int*)arg;
        int fn = *q;
        p = (int*)((char*)p + 8);
        ((void (__stdcall*)(int, int*, int*))fn)(0, p, (int*)((char*)buf + 0x54));
    }
    sub_68F330();
    sub_68D440();
}
