// from server: 100% by king_originala
struct Matrix
{
    float data[9];
    Matrix(const Matrix&);
};

struct Frame
{
    Matrix rotation;
    float x, y, z;
    Frame();
};

struct Part
{
    const Frame& getFrame() const;
};

struct Owner
{
    Part* getPart();
};

struct S
{
    Frame getFrame();
};

Frame S::getFrame()
{
    volatile int state = 0;
    Part* part = reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 456)->getPart();
    return part ? part->getFrame() : Frame();
}
