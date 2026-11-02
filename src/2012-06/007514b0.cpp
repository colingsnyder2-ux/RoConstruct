// from server: 100% by tajop
struct Target { void set(int value); };
void* func(void* x);
struct PartInstance {
    char pad[0x198];
    int value;
    void update();
};
void PartInstance::update() {
    Target* t = (Target*)func(this);
    if (t) t->set(value);
}
