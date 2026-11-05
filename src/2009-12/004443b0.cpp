// from server: 70% by atomic.potato
struct S {
    int f(int);
};

int S::f(int a) {
    if (a != 0) {
        a -= 0x1c;
        if (a != 0) {
            int r = ((int (__thiscall *)(void *))*(void **)((char *)this + 4))((char *)a + 0x98);
            return *(int *)&r;
        }
    }
    int r = ((int (__thiscall *)(void *))*(void **)((char *)this + 4))(0);
    return *(int *)&r;
}
