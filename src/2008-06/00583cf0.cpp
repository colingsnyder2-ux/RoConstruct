// from server: 100% by king_originala
struct Matrix
{
    float elements[9];

    Matrix(const Matrix&);
    Matrix& assign(const Matrix&);
    Matrix multiply(const Matrix&) const;
};

struct Frame
{
    Matrix rotation;
    float x, y, z;

    void identity();
};

struct Source
{
    Frame* getFrame();
};

struct Interface
{
    virtual void reserved();
    virtual int available();
};

struct S
{
    Frame* f(Frame* result);
};

Frame* S::f(Frame* result)
{
    int* offsets = *reinterpret_cast<int**>(
        reinterpret_cast<char*>(this) - 0x160);
    Interface* object = reinterpret_cast<Interface*>(
        reinterpret_cast<char*>(this) + offsets[1] - 0x160);

    if (object->available())
    {
        Source* source = *reinterpret_cast<Source**>(
            reinterpret_cast<char*>(this) - 0xb4);
        Frame* frame = source->getFrame();

        Frame local = {
            frame->rotation,
            frame->x,
            frame->y,
            frame->z
        };

        result->rotation.assign(local.rotation.multiply(
            *reinterpret_cast<Matrix*>(
                reinterpret_cast<char*>(this) - 0xe4)));
        result->x = local.x;
        result->y = local.y;
        result->z = local.z;
    }
    else
    {
        result->identity();
    }

    return result;
}
