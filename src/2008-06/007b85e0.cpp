// from server: 100% by king_originala
struct Texture;

struct Ptr {
    Texture* value;
    Ptr(Texture* const&);
    ~Ptr();
    void assign(Texture*);
};

struct Texture {
    char storage[0x30];
    Texture* target;
    Ptr clone();
};

inline Ptr::Ptr(Texture* const& p) : value(0) {
    assign(p);
}

Ptr Texture::clone() {
    return Ptr(target);
}
