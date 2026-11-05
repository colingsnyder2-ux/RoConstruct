// from server: 66% by Intel
struct BrickBuilder {
    void** ptr;

    void GetFunc();
};

struct InternalData {
    char padding[0x34];
    void (*func)();
};

void BrickBuilder::GetFunc() {
    InternalData* data = (InternalData*)(*this->ptr);
    void (*target)() = data->func;
    target();
}
