// from server: 100% by atomic.potato
struct CHookSub {
    int unknown00;
    int unknown04;
    int unknown08;
    int Lookup(int value, int option);
    void Erase(int value);
};

struct CHookSink {
    void* vtable;
    int unknown04;
    int unknown08;
    int unknown0C;
    int unknown10;
    CHookSub sub;
    int unknown20;
    void MethodB(int flag);
    void MethodA(int flag);
    void Handle(int value);
};

void CHookSink::Handle(int value) {
    int found = sub.Lookup(value, 0);
    if (found) {
        sub.Erase(found);
    }
    if (unknown20 == 0) {
        MethodA(0);
        MethodB(0);
    }
}
