// from server: 100% by king_originala
struct TextXmlParser;

struct Element {
    char storage[44];
    Element(int, const char*, TextXmlParser*);
    ~Element();
};

struct Vector {
    float x, y, z;
    Vector(float, float, float);
    Vector(const Vector&);
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c) {}

struct TextXmlParser {
    void apply(Element*, Vector, int);
    void setVector(const char*, float, float, float, int);
};

void TextXmlParser::setVector(const char* name, float x, float y, float z, int flag) {
    Element element(0, name, this);
    apply(&element, Vector(x, y, z), flag);
}
