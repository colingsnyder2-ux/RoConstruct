// from server: 100% by colin
// from server: 97% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3
{
    float x, y, z;
    Vector3& operator=(const Vector3&);
};

inline Vector3& Vector3::operator=(const Vector3& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

struct Frame
{
    virtual ~Frame();
    Vector3 origin;
    Vector3 offset;
};

inline Frame::~Frame()
{
}

struct Root
{
    char padding[0x24];
    Vector3 position;
};

struct Part
{
    Root* getRoot();
};

struct Humanoid
{
    Part* getPart();
    void setPosition(const Vector3&);
};

struct Player;
extern Humanoid* __cdecl findHumanoid(const Player*);

struct Point
{
    char padding[0x24];
    const Player* player;

    int resolve(int, Vector3&);
    Frame getFrame(int);
    void update(int);
};

void Point::update(int value)
{
    Vector3 position = { 0.0f, 0.0f, 0.0f };
    const Player* playerCopy = player;
    Humanoid* humanoid = findHumanoid(playerCopy);

    if (humanoid)
    {
        if (!resolve(value, position))
        {
            Frame frame = getFrame(value);
            const Vector3& origin = humanoid->getPart()
                ? humanoid->getPart()->getRoot()->position
                : frame.origin;

            position = origin;
            position.x += frame.offset.x;
            position.y += frame.offset.y;
            position.z += frame.offset.z;
        }

        humanoid->setPosition(position);
    }
}
