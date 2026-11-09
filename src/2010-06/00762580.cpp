// from server: 100% by atomic.potato
struct Node {
    Node* next;
};

struct List {
    Node* head;
};

struct Elem {
    char pad[0x2c];
    Node node;
};

struct Base {
    virtual void f(double);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u(double);
};

struct MovingAssemblyStage {
    char pad[0x14];
    Node* head;
    void method(double);
};

void MovingAssemblyStage::method(double value)
{
    Node* sentinel = (Node*)((char*)this + 0x14);
    Node* cur = this->head;
    while (cur != sentinel) {
        Base* obj;
        if (cur != 0) {
            obj = (Base*)((char*)cur - 0x2c);
        } else {
            obj = 0;
        }
        obj->u(value);
        cur = cur->next;
    }
}
