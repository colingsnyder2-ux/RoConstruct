// from server: 50% by atomic.potato
struct VArcHandles_EventDesc {
    char pad0[4];
    char field4[4];
    int sub_70adf0(int, int);
    int sub_4c1670(int);
    int f(int, int);
};

int VArcHandles_EventDesc::f(int a, int b) {
    char local;
    *(int*)&local = 0;
    sub_4c1670(1);
    sub_70adf0(b, a);
    return a;
}
