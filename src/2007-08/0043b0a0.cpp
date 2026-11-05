// from server: 43% by colin
// roc 2007-08 0043b0a0  unit: CSelectionPropGrid  size: 316 bytes

extern "C" {
    int __stdcall sub_699000(int);
    int __stdcall sub_699320(int, int, int);
}

struct Inner {
    char pad0[0x28];
    int count;
};

struct Obj {
    char pad0[0xb8];
    Inner* inner;
};

struct CSelectionPropGrid {
    char pad0[0x18c];
    char field18c[0x10];
    char field19c[0x10];
    void method(int);
};

struct Arg {
    char pad0[0x100];
    char field100[0x18];
    char pad118[0x4];
    Obj* obj118;
};

extern "C" int __stdcall sub_438e10(int, void*);
extern "C" int __stdcall sub_4397d0(int, int);
extern "C" int __stdcall sub_4339d0(int, void*);
extern "C" int __stdcall sub_464ec0(int, void*);

extern "C" {
    typedef int (__stdcall *Fn0)();
    extern Fn0 imp_77dd98;
    extern int (__stdcall *imp_77dcb8)(int);
    extern int (__stdcall *imp_77ddbc)(int);
}

void CSelectionPropGrid::method(int arg)
{
    Arg* a = (Arg*)arg;
    Obj* o = a->obj118;
    int v = sub_4397d0((int)this, o->inner->count);
    Obj* o2 = (Obj*)v;
    int i = 0;
    if (o2->inner->count > 0) {
        do {
            int x = sub_699000(i);
            int r1;
            sub_438e10(x, &r1);
            int r2;
            sub_438e10((int)a, &r2);
            int t = imp_77dd98();
            int cmp = imp_77dcb8(t);
            bool less = cmp < 0;
            imp_77ddbc(r1);
            imp_77ddbc(r2);
            if (less) break;
            i++;
        } while (i < o2->inner->count);
    }
    sub_699320((int)o2, i, (int)a);
    int* p = &a->obj118->inner->count;
    sub_4339d0((int)(this->field19c), &p);
    *(int*)&this->field18c = (int)&a->field100;
    sub_464ec0((int)(this->field18c), &p);
}
