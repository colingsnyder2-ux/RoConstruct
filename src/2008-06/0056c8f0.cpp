// from server: 100% by king_originala
struct Block
{
    unsigned int data[9];
    Block(const Block&);
};

struct Camera
{
    Block block;
    float x;
    float y;
    float z;

    Camera(const Camera&);
};

struct Base
{
    virtual ~Base();
};

struct Holder : Base
{
    Camera camera;

    Holder(const Camera&);
    virtual ~Holder();
};

inline Camera::Camera(const Camera& source)
    : block(source.block)
{
    x = source.x;
    y = source.y;
    z = source.z;
}

Holder::Holder(const Camera& source)
    : camera(source)
{
}
