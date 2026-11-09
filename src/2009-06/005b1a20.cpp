// from server: 44% by why2
struct TextureProxy {
    char pad[0x190];
    double value;
    double get() const;
};

double TextureProxy::get() const {
    return value;
}
