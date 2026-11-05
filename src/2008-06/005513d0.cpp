// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 005513d0: forwards a 3-float value with its GL element type
// (00501d00 returns GL_FLOAT) and byte size to the generic setter (004896b0).
class Vec3 { public: float x, y, z; };

unsigned glFormatOf();

class Program {
public:
    void setVector(int index, const Vec3& value);
    void setValue(int index, const void* value, unsigned format, int size);
    void* pointer;
};

void Program::setVector(int index, const Vec3& value)
{
    setValue(index, &value, glFormatOf(), 12);
}
