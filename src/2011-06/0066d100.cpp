// from server: 69% by atomic.potato
struct GetSetImpl {
    char pad[0x18];
    int offset18;
    int offset1c;
    int offset20;
    void invoke(int, int);
};

void GetSetImpl::invoke(int a, int b) {
    char* p = (char*)a;
    if (p != 0) {
        p -= 0x1c;
    } else {
        p = 0;
    }
    int* q = (int*)b;
    int v1 = q[1];
    int v0 = q[0];
    int idx = *(int*)(this->pad + 0x20);
    int* base = (int*)(p + 0x94);
    int val = *(int*)((char*)(*base) + idx);
    val += this->offset1c;
    void (*fn)(int, int) = (void (*)(int, int))this->offset18;
    fn(val + (int)(p + 0x94), v0);
}
