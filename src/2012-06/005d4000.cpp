// from server: 68% by atomic.potato
struct Inner {
    char pad0[0xc];
    int field_c;
};

struct Mid {
    char pad0[0x1c];
    Inner inner;
};

struct S {
    int f(int, int);
    int sub_4e75f0();
};


extern "C" char __fastcall sub_6c8100(int, int);

int S::f(int a, int b)
{
    int* src = (int*)b;
    *(int*)this = src[0];
    *(int*)((char*)this + 4) = *(int*)((char*)src + 0x24);

    int* p = (int*)a;
    int* result = 0;
    if (p != 0) {
        Mid* m = (Mid*)((char*)p + 0x1c);
        if (m != 0) {
            int v = m->inner.field_c;
            int r = sub_4e75f0();
            char ok = sub_6c8100(v, r);
            if (ok) {
                result = (int*)p;
            }
        }
    }
    *(int*)((char*)this + 8) = (int)result;
    *(int*)((char*)this + 0xc) = 0;
    if (result != 0) {
        *(int*)((char*)this + 0xc) = 1;
    }
    return (int)this;
}
