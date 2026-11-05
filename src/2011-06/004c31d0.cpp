// from server: 45% by atomic.potato
struct VPlayerEventDesc {
    char pad0[4];
    char field4;
    void sub_4c1670(int);
    void* sub_4c14b0(void*, void*);
    void* init(void* a, void* b);
};

void* VPlayerEventDesc::init(void* a, void* b) {
    char local = 0;
    this->sub_4c1670(1);
    return this->sub_4c14b0(a, b);
}
