// from server: 55% by atomic.potato
struct Clump {
    char pad0[0x34];
    void* field34;
    char pad1[0x98 - 0x38];
    float field98;

    float getValue();
};

struct Inner {
    char pad0[0x14];
    float field14;
    void method();
};

float Clump::getValue() {
    Inner* p = (Inner*)this->field34;
    if (p) {
        p->method();
        return p->field14;
    }
    return this->field98;
}
