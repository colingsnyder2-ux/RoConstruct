// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float elements[9];

    Matrix3& copy(const Matrix3&);
    Matrix3* intermediate();
    const Matrix3& result();
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;

    Frame& identity();
    Frame& operator=(const Frame&);
};

inline Frame& Frame::operator=(const Frame& other)
{
    rotation = other.rotation;
    translation.x = other.translation.x;
    translation.y = other.translation.y;
    translation.z = other.translation.z;
    return *this;
}

extern const Vector3& __cdecl zeroVector();

struct Interface {
    virtual Frame* frame(Frame*);
};

struct BaseTable {
    int unused[2];
    int displacement;
};

struct S {
    char prefix[0x134];
    BaseTable* baseTable;
    char padding[0x78];
    Frame relativeFrame;
    S* reference;

    Matrix3* calculate(Matrix3*, Matrix3*, const Matrix3*);
    void setReference(S*);
};

void S::setReference(S* value)
{
    if (reference == value)
        return;

    if (value) {
        if (reference) {
            Frame temporary;
            Matrix3 world;
            Matrix3 scratch;
            Matrix3 output;

            Interface* base = reinterpret_cast<Interface*>(
                reinterpret_cast<char*>(this) + 0x134 +
                baseTable->displacement);

            world.copy(base->frame(&temporary)->rotation);
            const Vector3& zero = zeroVector();

            temporary.rotation.copy(
                reference->calculate(&output, &scratch, &world)
                    ->intermediate()->result());
            temporary.translation.x = zero.x;
            temporary.translation.y = zero.y;
            temporary.translation.z = zero.z;
            relativeFrame = temporary;
        } else {
            Frame temporary;
            relativeFrame = temporary.identity();
        }

        reference = value;
    } else {
        Frame temporary;
        relativeFrame = temporary.identity();
        reference = 0;
    }
}
