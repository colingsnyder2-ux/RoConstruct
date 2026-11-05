// from server: 100% by king_originala
struct Base {
    virtual ~Base();
};

struct Reference {
    void* pointer;
    Reference(const Reference&);
    ~Reference();
    void assign(void*);
};

inline Reference::Reference(const Reference& other) : pointer(0) {
    assign(other.pointer);
}

struct Material : Base {
    bool flag;
    Reference first;
    Reference second;
    float a, b, c, d, e, f, g;

    Material(const Material&);
    virtual ~Material();
};

Material::Material(const Material& other)
    : flag(other.flag),
      first(other.first),
      second(other.second),
      a(other.a),
      b(other.b),
      c(other.c),
      d(other.d),
      e(other.e),
      f(other.f),
      g(other.g) {
}
