// from server: 100% by king_originala
struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3& other);
};

struct Frame {
    Matrix3 rotation;
    float x, y, z;
    Frame(const Matrix3& matrix);
};

inline Frame::Frame(const Matrix3& matrix) : rotation(matrix)
{
}

struct Object {
    const Frame* getFrame();
    void setFrame(const Frame& frame);
};

extern void __cdecl sendFrame(const Frame& frame, int flag);

void __cdecl updateFrame(Object* object)
{
    const Frame* source = object->getFrame();
    Frame frame(source->rotation);
    frame.x = source->x;
    frame.y = source->y;
    frame.z = source->z;
    sendFrame(frame, 1);
    object->setFrame(frame);
}
