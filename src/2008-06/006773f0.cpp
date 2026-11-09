// from server: 100% by king_originala
struct Matrix {
    float m[9];
    Matrix(const Matrix&);
    const Matrix& multiply(Matrix& result, const Matrix&) const;
};

struct Vector3 {
    float x, y, z;
};

struct Frame {
    Matrix rotation;
    Vector3 translation;
};

struct Color {
    float r, g, b, a;
};

struct Adorn;

struct AdornTable {
    char reserved0[56];
    void (__thiscall *setFrame)(Adorn*, const Frame&);
    char reserved1[20];
    void (__thiscall *draw)(Adorn*, float, float, const Color&, const Color&);
};

struct Adorn {
    AdornTable* table;
};

extern const Matrix& __cdecl convertRotation(const Vector3&);
extern const Color& __cdecl defaultColor();

void __cdecl render(Adorn* adorn, const Frame* frame,
                    const Vector3& rotation, float first, float second,
                    const Vector3& rgb)
{
    float temporary[9];
    Frame transformed = {
        frame->rotation.multiply(
            *reinterpret_cast<Matrix*>(temporary), convertRotation(rotation)),
        { frame->translation.x, frame->translation.y, frame->translation.z }
    };
    adorn->table->setFrame(adorn, transformed);

    AdornTable* table = adorn->table;
    Color color = { rgb.x, rgb.y, rgb.z, 1.0f };
    table->draw(adorn, second, first, color, defaultColor());
}
