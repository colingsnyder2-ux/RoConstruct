// from server: 59% by atomic.potato
extern "C" int __cdecl _errno();
extern "C" unsigned int __cdecl fread(void*, unsigned int, unsigned int, void*);
extern "C" int __cdecl fseek(void*, long, int);

extern "C" int __stdcall sub_564BE0(int*, int, int*);

struct S {
    void* field0;
    int field4;
    char pad8[8];
    unsigned char field10;
    char pad11[7];
    int field18;
    char pad1c[4];
    unsigned int field20;

    int __cdecl f(unsigned int n);
};

int S::f(unsigned int n) {
    if (this->field4 != 0) {
        return -1;
    }
    if ((this->field10 & 1) != 0) {
        return 0;
    }
    if (this->field20 == 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (fseek(this->field0, this->field18, 0) < 0) {
        sub_564BE0(&this->field4, 4, (int*)_errno());
        return -1;
    }
    unsigned int avail = this->field20;
    if (n < avail) {
        avail = n;
    }
    int r = fread((void*)n, 1, avail, this->field0);
    if (r == 0) {
        sub_564BE0(&this->field4, 0x11, (int*)0);
        return -1;
    }
    if (r < 0) {
        sub_564BE0(&this->field4, 5, (int*)_errno());
        return r;
    }
    this->field18 += r;
    this->field20 -= r;
    return r;
}
