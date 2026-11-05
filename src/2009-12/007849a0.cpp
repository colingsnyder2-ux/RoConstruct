// from server: 38% by atomic.potato
struct S_func_007849a0 {
    bool f(const char* a, const char* b);
};

extern "C" void* __stdcall func_98b5a4(void*, const char*);
extern "C" void* __stdcall func_98b680(void*, const char*);
extern "C" void __stdcall func_98b6e4(void*);
extern "C" void __stdcall func_98b6f0(void*, void*);
extern "C" void __stdcall func_6b1850(void*, void*);
extern "C" bool __fastcall func_784600(void*, void*, void*);

bool S_func_007849a0::f(const char* a, const char* b)
{
    char buf1[28];
    char buf2[28];
    char buf3[28];
    char buf4[28];
    bool result;

    func_98b5a4(buf1, "$SV3");
    func_98b680(buf2, ".png");
    func_6b1850(buf3, buf2);
    func_98b6e4(buf1);
    func_98b6e4(buf2);
    func_98b6f0(buf4, buf3);
    result = func_784600(this, (void*)a, (void*)b);
    func_98b6e4(buf4);
    func_98b6e4(buf3);
    return result;
}
