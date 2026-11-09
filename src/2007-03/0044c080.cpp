// from server: 100% by sophus
// roc 2007-03 0044c080  unit: seg_00440000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044c080

extern "C" __declspec(dllimport) int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct Inner {
    char pad[0x20];
    void* field20;
};

struct Mid {
    char pad[4];
    Inner* field4;
};

struct Outer {
    char pad[0x20];
    void* field20;
    char pad2[0xec - 0x24];
    char fieldEC;
};

struct V {
    virtual void pad00();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual int fn68();
    virtual int* fn6c(int*);
};

struct S {
    char pad[0x2c];
    void* field2C;
    int method(int);
};

extern "C" Mid* __cdecl sub_61e390();

int S::method(int arg) {
    Mid* m = sub_61e390();
    Inner* in = m->field4;
    Outer* o = (Outer*)in->field20;
    if (o->fieldEC != 0) {
        void* arg = o->field20;
        return PostMessageA(arg, 0x10, 0, 0);
    }
    V* obj = (V*)field2C;
    int r = obj->fn68();
    if (r != 0) {
        V* obj2 = (V*)field2C;
        int* pr = obj2->fn6c(&r);
        Inner* in2 = (Inner*)pr;
        r = PostMessageA(in2->field20, 0x111, 0xe102, 0);
    }
    return r;
}
