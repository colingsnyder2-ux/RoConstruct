// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Texture;

struct Ptr {
    Texture* value;
    Ptr(Texture*);
    Ptr(const Ptr&);
    ~Ptr();
    void assign(Texture*);
};

struct Texture {
    char storage[0x54];
    Texture(Ptr);
    Ptr clone();
};

inline Ptr::Ptr(Texture* p) : value(0) {
    assign(p);
}

Ptr Texture::clone() {
    return Ptr(new Texture(Ptr(this)));
}
