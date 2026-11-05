// from server: 72% by atomic.potato
struct Inner {
    char pad0[0x14];
    int field14;
    char pad18[0x08];
    int field20;
};

struct Outer {
    char pad0[0x14];
    Inner inner;
};

extern "C" int __stdcall sub_6f8090(int);
extern "C" int __stdcall sub_419490(int);
extern "C" int __stdcall sub_6f5e70(int);
extern "C" int* __stdcall sub_6f3dc0(int*, int, int, int*);

struct SelectChildrenOfSelectionSelectionVerb {
    char pad0[0x14];
    int field14;
    char pad18[0x08];
    int field20;
    bool method();
};

bool SelectChildrenOfSelectionSelectionVerb::method() {
    int v = sub_6f8090((int)(&this->field14));
    int r = sub_419490(v);
    if ((unsigned)r <= 0) {
        return false;
    }
    int p = this->field20;
    if (p == 0) {
        return false;
    }
    int s = sub_6f5e70(p);
    if (s == 0) {
        return false;
    }
    int a = *(int*)(s + 0x98);
    int b = *(int*)(s + 0x94);
    int* res = sub_6f3dc0(&b, b, a, (int*)0x6f4170);
    int val = *res;
    if (val == *(int*)(s + 0x98)) {
        return false;
    }
    if (*res == 0) {
        return false;
    }
    return true;
}
