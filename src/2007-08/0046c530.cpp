// from server: 76% by colin
struct S {
    int* ptr;
    unsigned int count;
    S* method();
};

extern "C" void __stdcall func_77e6d8();
extern "C" char* __stdcall func_77e5e8(int* p);

S* S::method()
{
    int* p = ptr;
    if (p != (int*)-2) {
        if (p == 0) {
            func_77e6d8();
        }
        p = ptr;
        char* q = func_77e5e8(p);
        int* r = ptr;
        unsigned int v = (unsigned int)(q + r[5]);
        if (count >= v) {
            func_77e6d8();
        }
    }
    count++;
    return this;
}
