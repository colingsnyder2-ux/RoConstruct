// from server: 100% by king_originala
struct Value {
    int first;
    int second;
    Value(const Value&);
    ~Value();
};

extern Value __cdecl func_00618a40(int);

struct Dispatcher {
    void func_0057b570(void*, Value, int);
};

extern Dispatcher dispatcher;

struct VirtualPart {
    virtual void invoke(int);
};

struct DataModel {
    char padding[0x1f0];
    VirtualPart part;

    void func_0053e2a0(int, int);
    void func_0057b630(int, int*);
};

void DataModel::func_0057b630(int a, int* b)
{
    func_0053e2a0(a, reinterpret_cast<int>(b));
    part.invoke(1);
    int value = *b;
    void* object = reinterpret_cast<char*>(this) + 0x14;
    dispatcher.func_0057b570(object, func_00618a40(a), value);
}
