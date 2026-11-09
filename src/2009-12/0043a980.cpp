// from server: 84% by atomic.potato
struct UDim2Item {
    void sub_437DE0(int);
    void f(int);
};

void UDim2Item::f(int a) {
    sub_437DE0(a);
    char* p = (char*)this + 0x24;
    int i = 2;
    do {
        if (*(void**)p) {
            void* q = *(void**)p;
            void** v = *(void***)((char*)q + 0x10C);
            ((void (__thiscall*)(void*, int))v[0])(v, a);
        }
        p += 4;
        i--;
    } while (i);
}
