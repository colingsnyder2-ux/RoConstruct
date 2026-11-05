// from server: 100% by colin
struct GetSetImpl {
    char pad0[8];
    int field8;
    int fieldC;
    int field10;
    void invoke(int arg);
};

void GetSetImpl::invoke(int arg) {
    int* p = (int*)arg;
    if (p != 0) {
        p = (int*)((char*)p - 4);
    } else {
        p = 0;
    }
    int idx = *(int*)((char*)p + 0x108);
    int off = field10;
    int fn = *(int*)(idx + off);
    fn += fieldC;
    int self = (int)((char*)p + 0x108 + fn);
    int call = field8;
    ((void (__thiscall*)(int))call)(self);
}
