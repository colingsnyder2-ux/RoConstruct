// from server: 15% by atomic.potato
extern "C" void __stdcall sub_80bbec();
extern "C" void __stdcall sub_80bc31();
extern "C" void __cdecl sub_80b33d();

struct S {
    void f(char* p, int stride, int count, void (__stdcall *fn)(char*));
};

void S::f(char* p, int stride, int count, void (__stdcall *fn)(char*))
{
    int i = 0;
    while (i < count) {
        fn(p);
        p += stride;
        i++;
    }
    sub_80b33d();
    sub_80bc31();
}
