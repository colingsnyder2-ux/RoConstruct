// from server: 84% by atomic.potato
struct RBX_DS_CVideoStream {
    int f(int a1);
};

int RBX_DS_CVideoStream::f(int a1) {
    int* vtable = *(int**)a1;
    int (*func1)(int, int*) = (int (*)(int, int*))(vtable[9]);
    int result;
    func1(a1, &result);

    if (result == *(int*)((char*)this + 0x1c)) {
        return 0x80040208;
    }

    int (*func2)(int, int, int) = (int (*)(int, int, int))(*(int**)*(int**)a1);
    int ret = func2(a1, 0xB64360, (int)((char*)this + 0x9C));

    int ecx = ret >= 0 ? 1 : 0;
    ecx--;
    return ret & ecx;
}
