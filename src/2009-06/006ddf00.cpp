// from server: 100% by atomic.potato
struct Node {
    Node* next;
    char pad[0x28];
};

struct Inner {
    virtual void f(double);
    virtual void g(double);
    virtual void h(double);
    virtual void i(double);
    virtual void j(double);
    virtual void k(double);
    virtual void l(double);
    virtual void m(double);
    virtual void n(double);
    virtual void o(double);
    virtual void p(double);
    virtual void q(double);
    virtual void r(double);
    virtual void s(double);
    virtual void t(double);
    virtual void u(double);
};

struct S {
    char pad[0x14];
    Node head;
    void method(double);
};

void S::method(double d) {
    Node* p = head.next;
    Node* end = &head;
    while (p != end) {
        Inner* obj;
        if (p != 0) {
            obj = (Inner*)((char*)p - 0x2c);
        } else {
            obj = 0;
        }
        obj->u(d);
        p = p->next;
    }
}
