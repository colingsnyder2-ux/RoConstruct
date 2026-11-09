// from server: 100% by colin
struct CHookSink {
    char pad[0x14];
    int field14;
    char pad2[0x20 - 0x18];
    int field20;
    void method(int);
    void method_6a3580(int);
    void method_6a3530(int);
};

struct Sub14 {
    int __thiscall find(int, int);
    void __thiscall remove(int);
};

void CHookSink::method(int arg)
{
    Sub14 *p = (Sub14 *)&field14;
    int r = p->find(arg, 0);
    if (r != 0)
        p->remove(r);
    if (field20 == 0) {
        method_6a3580(0);
        method_6a3530(0);
    }
}
