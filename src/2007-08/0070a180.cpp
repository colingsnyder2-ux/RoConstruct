// from server: 100% by colin
struct Inner {
    char pad[8];
    Inner* field8;
};

struct Inner2 {
    int field0;
    int field4;
};

struct Helper {
    Inner* find(int);
};

struct CXTColorHex {
    char pad[0x7c];
    Helper helper;
    void sub_709f50(int, int);
    void method(int);
};

void CXTColorHex::method(int index) {
    if (index == -1)
        return;
    Inner* p = helper.find(index);
    p = p->field8;
    if (p == 0)
        return;
    Inner2* q = *(Inner2**)((char*)p + 0x14);
    sub_709f50(q->field0, q->field4);
}
