// from server: 100% by tester
struct Sub {
    char pad[0x74];
    float value;
};

struct PartInstance {
    char pad[0x1e0];
    Sub* sub;
    float get() const;
};

float PartInstance::get() const {
    return sub->value;
}