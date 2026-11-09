// from server: 30% by atomic.potato
struct Inner {
    char pad0[0xc];
    int f0c;
    int f10;
};

struct Outer {
    char pad0[0xc];
    Inner* begin;
    Inner* end;
    char pad14[0x1c];
    char pad30[0x10];
    char pad40[0x4];
};

struct Vec {
    char pad0[0xc];
    Inner* begin;
    Inner* end;
    Inner* cap;
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __stdcall sub_7a79a0(unsigned int);
extern "C" void __stdcall sub_7a799a(void*);
extern "C" void __stdcall sub_8fec40(void*, void*);
extern "C" void __stdcall sub_786440(void*);
extern "C" void* __stdcall sub_483420(Vec*, int);

struct GettingUp {
    char pad0[0x30];
    Vec vec30;
    char pad48[0x8];
    void method(int, int*, int, char);
};

void GettingUp::method(int a, int* b, int c, char d) {
    int count = (vec30.end - vec30.begin) / 0x30;
    Vec local;
    local.begin = 0;
    local.end = 0;
    local.cap = 0;
    int flag = 1;
    if (d == 0) {
        int n = a - 1;
        int i = 0;
        while (i < n) {
            int r = ((int (__thiscall*)(GettingUp*, int, int))0x788a30)(this, b[i], b[i+1]);
            if (r != 0) {
                sub_8fec40(&local, &r);
            }
            i++;
            n = a - 1;
        }
        int r2 = ((int (__thiscall*)(GettingUp*, int, int))0x788a30)(this, b[a-1], b[0]);
        if (r2 != 0) {
            sub_8fec40(&local, &r2);
        }
    } else {
        int n = a - 1;
        int i = 0;
        while (i < n) {
            int r = ((int (__thiscall*)(GettingUp*, int, int))0x788a30)(this, b[a-1-i], b[a-2-i]);
            if (r != 0) {
                sub_8fec40(&local, &r);
            }
            i++;
            n = a - 1;
        }
        int r2 = ((int (__thiscall*)(GettingUp*, int, int))0x788a30)(this, b[0], b[a-1]);
        if (r2 != 0) {
            sub_8fec40(&local, &r2);
        }
    }
    Inner* slot = vec30.begin + count;
    if (count >= (unsigned)((vec30.end - vec30.begin) / 0x30)) {
        _invalid_parameter_noinfo();
    }
    if (d == 0) {
        int i = 0;
        while (i < a) {
            Inner* p = *(Inner**)sub_483420(&local, i);
            if (p->f0c == 0) {
                p->f0c = (int)slot;
            } else {
                p->f10 = (int)slot;
            }
            i++;
        }
    } else {
        int i = 0;
        while (i < a) {
            Inner* p = *(Inner**)sub_483420(&local, a - 1 - i);
            if (p->f0c == 0) {
                p->f0c = (int)slot;
            } else {
                p->f10 = (int)slot;
            }
            i++;
        }
    }
    sub_786440(slot);
    if (local.begin) {
        sub_7a799a(local.begin);
    }
    local.begin = 0;
    local.end = 0;
    local.cap = 0;
    if (local.begin) {
        sub_7a799a(local.begin);
    }
}
