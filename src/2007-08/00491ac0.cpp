// from server: 100% by colin
struct Listener {
    void setListener(int, int);
};

void Listener::setListener(int a, int b) {
    int* old = *(int**)((char*)this + 0x140);
    if (old) {
        int* vtbl = *(int**)old;
        int arg = *(int*)((char*)this + 0x12c);
        ((void (__thiscall*)(int*, int))vtbl[0xec / 4])(old, arg);
    }
    *(int*)((char*)this + 0x140) = a;
    *(int*)((char*)this + 0x144) = b;
    if (a) {
        int* p = (int*)a;
        int* vtbl = *(int**)p;
        int arg = *(int*)((char*)this + 0x12c);
        ((void (__thiscall*)(int*, int))vtbl[0xe8 / 4])(p, arg);
    }
}
