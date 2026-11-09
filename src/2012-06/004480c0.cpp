// from server: 53% by atomic.potato
struct AsyncResult {
    void* vfptr;
    int field4;
    int field8;
    int fieldC;
    char field10;
    void construct(char flag, int a, int b, int c);
};

extern "C" void __stdcall sub_41bef0(void* out, int a, int b);
extern "C" void __cdecl sub_982114(void* p);

void AsyncResult::construct(char flag, int a, int b, int c) {
    this->field4 = 1;
    this->field8 = 1;
    this->vfptr = (void*)0xb51c1c;
    this->fieldC = a;
    this->field10 = 0;
    if (flag != 0) {
        if (b != 0) {
            sub_41bef0(&c, b, a);
            sub_982114((void*)c);
        }
    }
}
