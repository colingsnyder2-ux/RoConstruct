// from server: 20% by atomic.potato
struct Inner {
    int f0;
    int f1;
};

struct Outer {
    char pad0[4];
    Inner* inner;
    char pad1[0x8c];
    int field94;
};

struct Result {
    int a;
    int b;
    int c;
    int d;
};

extern "C" void __stdcall sub_5395b0(Inner** p);
extern "C" void __stdcall sub_675e20(Outer* self, Result* out, int* arg);

struct GuiItem {
    char pad0[0x94];
    Outer outer;
    Result getResult(int* arg);
};

Result GuiItem::getResult(int* arg) {
    Result result;
    int* p = arg;
    if (*p >= 1 && *p == 7) {
        result.a = 0;
        result.b = 0;
        result.c = 0;
        result.d = 0;
        return result;
    }
    Inner* inner = outer.inner;
    if (inner) {
        if (((int (__stdcall*)(Inner*))((*(int**)inner)[0x50/4]))(inner)) {
            sub_675e20(&outer, &result, arg);
            if (result.a == 1) {
                return result;
            }
        }
        Inner* inner2 = outer.inner;
        if (inner2) {
            void* vt = *(void**)inner2;
            ((void (__stdcall*)(Inner*))((int*)vt)[0x94/4])(inner2);
        }
        sub_675e20(&outer, &result, arg);
        if (result.a == 1) {
            return result;
        }
        Inner* inner3 = outer.inner;
        if (inner3) {
            void* vt = *(void**)inner3;
            ((void (__stdcall*)(Inner*))((int*)vt)[0x4c/4])(inner3);
        }
        sub_5395b0(&outer.inner);
    }
    sub_675e20(&outer, &result, arg);
    return result;
}
