// from server: 58% by colin
struct AsyncResult {
    void* ptr0;
    void* ptr1;
    void release();
};

struct S {
    char pad[0x3a4];
    void* field3a4;
    void* field3a8;
    char pad2[0x38];
    AsyncResult asyncResult;
    void sub_8dfc60(void*);
    void sub_8dff40(void*);
    void sub_414da0(const char*);
    void sub_79a9f0();
    void sub_684200(int, int);
    void sub_5728d0();
    void func(void* p, bool b);
};

void S::func(void* p, bool b) {
    if (asyncResult.ptr0 != 0) {
        sub_684200(0, 0);
        sub_5728d0();
    }
    if (p != 0) {
        sub_79a9f0();
        if (p == (void*)0) {
            return;
        }
        if (b) {
            sub_8dfc60(p);
        } else {
            sub_8dff40(p);
        }
        if (field3a4 != 0) {
            field3a4 = 0;
            sub_414da0((const char*)0xe55690);
        }
        if (field3a8 != 0) {
            field3a8 = 0;
            sub_414da0((const char*)0xe557ec);
        }
    }
}
