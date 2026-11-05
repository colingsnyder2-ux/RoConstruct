// from server: 100% by colin
struct DataModel {
    char pad[0x160];
    struct VTableHolder {
        virtual void f(int);
        virtual void g(int);
    } holder;
    void func(int, int);
};

void DataModel::func(int a, int b) {
    this->func(a, b);
    this->holder.g(1);
}
