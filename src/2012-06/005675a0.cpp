// from server: 100% by atomic.potato
struct VRegistry {
    VRegistry();
    int value;
    int state;
    int count;
    int* self;
    unsigned char flag;
};

VRegistry::VRegistry() {
    value = 0;
    state = 0x800;
    count = 0;
    self = (int*)((char*)this + 0x11);
    flag = 1;
}
