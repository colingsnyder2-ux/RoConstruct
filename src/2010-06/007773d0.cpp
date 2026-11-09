// from server: 34% by atomic.potato
struct S {
    int f(int);
};
int S::f(int a1) {
    if (a1 != 0) {
        goto L1;
    }
    {
        int v1 = *(int*)(*(int*)(*((int*)this + 1) + 4) + 0xf0);
        void* (__stdcall *p)(void*) = (void* (__stdcall *)(void*))0x4e5f50;
        p((void*)v1);
    }
    return 0;
L1:
    {
        int v2 = *(int*)(*((int*)this + 2) + 0xf0);
        void* (__stdcall *p)(void*) = (void* (__stdcall *)(void*))0x4e5f50;
        p((void*)v2);
    }
    return 0;
}
