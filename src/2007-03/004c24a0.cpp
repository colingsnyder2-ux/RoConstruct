// from server: 100% by tester
struct Sub {
    char pad[0x8c];
    float value;
};

struct PartInstance {
    char pad[0x58];
    Sub* sub;
    float get() const;
};

float PartInstance::get() const {
    return sub->value;
}