// from server: 29% by atomic.potato
extern "C" void* __stdcall sub_00401610();
extern "C" void* __stdcall sub_0068cf90();
extern "C" void* __stdcall sub_0068cf20();
extern "C" void __stdcall sub_007736f0();
extern "C" void __stdcall sub_00640310();
extern "C" void __stdcall sub_005e5960();
extern "C" void __stdcall sub_00402560();

struct S {
    char pad[0x90];
    void* begin;
    void* end;
    void* __cdecl f(int);
};

void* S::f(int idx) {
    sub_00401610();
    sub_00401610();
    void* v = sub_0068cf90();
    int n = (int)v;
    int count = ((char*)end - (char*)begin) >> 3;
    if (n + 1 > count) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_00640310();
    } else {
        void* p = *(void**)((char*)begin + n * 8);
        if (p) return p;
    }
    if (*(int*)0xab3af4) {
        sub_00401610();
        sub_00401610();
        void* r = sub_0068cf20();
        void* out;
        sub_005e5960();
        void* q = out;
        if (q) {
            void* slot = (char*)begin + n * 8;
            *(void**)slot = q;
            sub_00402560();
            return q;
        }
        sub_007736f0();
    }
    return 0;
}
