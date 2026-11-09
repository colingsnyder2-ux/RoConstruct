// from server: 100% by colin
struct Vector3 {
    float x, y, z;

    Vector3(float, float, float);
    Vector3(const Vector3&);
    Vector3& operator=(const Vector3&);
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c) {}

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z) {}

inline Vector3& Vector3::operator=(const Vector3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

extern const Vector3& __cdecl zeroVector();
extern const Vector3& __cdecl unitVector();

struct Plane {
    float data[4];

    Plane(const Vector3&, const Vector3&);
    Plane(const Plane&);
    virtual ~Plane();
};

struct Ray {
    float data[6];

    Ray(const Ray&);
    virtual ~Ray();
};

inline Plane::~Plane() {}
inline Ray::~Ray() {}

extern bool __cdecl intersect(const Ray&, const Plane&, Vector3&);
extern Vector3 __cdecl transformVector(const Vector3&);

struct DragState {
    bool ready();
    Vector3 position(int);
    void generateDataForMovingAssemblyStage();
    Vector3 move(const Vector3&);
};

struct GroupDragTool {
    char padding0[20];
    bool enabled;
    char padding1[7];
    DragState* state;
    char padding2[8];
    bool active;
    char padding3[3];
    Vector3 previous;

    Ray ray(int);
    void update(int);
};

void GroupDragTool::update(int argument)
{
    Vector3 point(0.0f, 0.0f, 0.0f);

    bool hit = enabled && active && state->ready() &&
        intersect(ray(argument), Plane(unitVector(), zeroVector()), point);

    if (hit)
    {
        point = state->position(argument);
        state->generateDataForMovingAssemblyStage();

        Vector3 current = transformVector(point);
        Vector3 displacement = transformVector(
            Vector3(current.x - previous.x,
                    current.y - previous.y,
                    current.z - previous.z));

        previous = current;

        state->move(displacement);
    }
}
