// from server: 44% by atomic.potato
struct S {
    void f();
};

extern "C" void __cdecl sub_94fa70(void*);
extern "C" void __cdecl sub_740000(void*, void*);
extern "C" void __cdecl sub_7a7e20(void*, int, int);
extern "C" void __cdecl sub_982114(void*);

void S::f()
{
    char* p = (char*)this;
    float* src = *(float**)(p + 0x18);
    float* dst = *(float**)(p + 0x20);
    *dst = *src;
    src++;
    dst++;
    sub_94fa70(src);
    float v = *(float*)(p + 0x24);
    char buf[0x14];
    *(float*)buf = v;
    sub_740000(buf + 4, p + 0x3c);
    int count = (*(int*)(p + 0x30) - *(int*)(p + 0x2c)) / 0x28;
    sub_7a7e20(*(void**)(p + 0x2c), 0, count);
    void* q = *(void**)(p + 0x4c);
    if (q) {
        sub_982114(q);
    }
}
