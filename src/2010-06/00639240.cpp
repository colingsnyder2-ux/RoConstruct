// from server: 100% by atomic.potato
struct VVector2int16 {
    void sub_638090(int*, int*);
    void sub_639150();
    void f(int*);
};

void VVector2int16::f(int* p) {
    int tmp[3];
    sub_638090(tmp, p);
    void (VVector2int16::*fn)(int*) = *(void (VVector2int16::**)(int*))(*(int*)this + 0x78);
    (this->*fn)(tmp);
    sub_639150();
}
