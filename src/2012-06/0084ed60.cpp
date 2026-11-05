// from server: 89% by atomic.potato
extern "C" int __stdcall sub_41BEF0(int, int, int);
extern "C" int __stdcall sub_982114(int);

struct S {
    void* vtable;
    int field_4;
    int field_8;
    int field_c;
    char field_10;
    char pad[3];
    void* init(int a, char b, int c, int d, int e);
};

void* S::init(int a, char b, int c, int d, int e) {
    this->field_4 = 1;
    this->field_8 = 1;
    this->vtable = (void*)0xbd2cf8;
    this->field_c = a;
    this->field_10 = 0;
    if (b != 0) {
        if (c != 0) {
            int tmp;
            sub_41BEF0(c, d, (int)&tmp);
            sub_982114(tmp);
        }
    }
    return this;
}
