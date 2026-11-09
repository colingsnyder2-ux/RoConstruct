// from server: 44% by atomic.potato
extern "C" void __stdcall func_006844c0(int,int);
struct S {
    int f(void*,void*,int);
};
int S::f(void* a,void* b,int c) {
    if(a) {
        void* d = b;
        int e = *(int*)((char*)a + 56);
        a = (void*)((char*)a - 28);
        func_006844c0(e,*(int*)((char*)a + 4));
        return 0;
    }
    void* d = b;
    int e = *(int*)((char*)a + 56);
    a = (void*)((char*)a - 28);
    func_006844c0(e,*(int*)((char*)a + 4));
    return 0;
}
