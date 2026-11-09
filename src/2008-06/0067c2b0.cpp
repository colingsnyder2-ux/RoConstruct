// from server: 41% by king_originala
struct Vector3 {
    float x, y, z;
    float length() const;
};

struct AxisAlignedBox {
    Vector3 minimum, maximum;
    int extent;
    int infinite;
    AxisAlignedBox &operator=(const AxisAlignedBox &);
    Vector3 getHalfSize() const;
    ~AxisAlignedBox();
};

struct String {
    unsigned char storage[28];
    String &operator=(const String &);
    const char *c_str() const;
    ~String();
};

String operator+(const char *, const String &);

struct StringConverter {
    static String toString(int, unsigned short, char, unsigned int);
};

struct LogManager {
    static LogManager &getSingleton();
    void logMessage(const String &, int, bool);
};

struct HardwareIndexBufferSharedPtr {
    void *pointer;
    unsigned int *references;
    virtual ~HardwareIndexBufferSharedPtr();
};

struct ContentProvider {
    int value;
    unsigned char flag;
    int count;
    void f();
};

struct ContentReference {
    ContentProvider *pointer;
    ~ContentReference();
};

inline ContentReference::~ContentReference()
{
    pointer->f();
}

struct Factory {
    unsigned char reserved[32];
    int count;
    String f(ContentReference *);
};

struct Object {
    unsigned char reserved[204];
    AxisAlignedBox bounds;
    float radius;
    Object *f(Factory *, const Vector3 *, unsigned int, Vector3 *,
              Vector3 *, ContentProvider *, HardwareIndexBufferSharedPtr *,
              int, int, int);
};

Object *Object::f(Factory *factory, const Vector3 *vertices,
                  unsigned int count, Vector3 *minimum, Vector3 *maximum,
                  ContentProvider *provider,
                  HardwareIndexBufferSharedPtr *indexBuffer,
                  int, int, int)
{
    ContentReference reference;
    reference.pointer = provider;
    HardwareIndexBufferSharedPtr indices = *indexBuffer;

    double minX = 3.402823466e+38F;
    double minY = minX;
    double minZ = minX;
    double maxX = -3.402823466e+38F;
    double maxY = maxX;
    double maxZ = maxX;

    while (count != 0) {
        if (vertices->x < minX)
            minX = vertices->x;
        if (vertices->y < minY)
            minY = vertices->y;
        if (vertices->z < minZ)
            minZ = vertices->z;
        if (vertices->x > maxX)
            maxX = vertices->x;
        if (maxY < vertices->y)
            maxY = vertices->y;
        if (vertices->z > maxZ)
            maxZ = vertices->z;
        ++vertices;
        --count;
    }

    minimum->x = (float)minX;
    minimum->y = (float)minY;
    minimum->z = (float)minZ;
    maximum->x = (float)maxX;
    maximum->y = (float)maxY;
    maximum->z = (float)maxZ;

    {
        AxisAlignedBox box;
        box.minimum.x = (float)minX;
        box.minimum.y = (float)minY;
        box.minimum.z = (float)minZ;
        box.maximum.x = (float)maxX;
        box.maximum.y = (float)maxY;
        box.maximum.z = (float)maxZ;
        box.extent = 1;
        box.infinite = 0;
        bounds = box;
        radius = box.getHalfSize().length();
    }

    {
        String name = "RBX cr " +
            StringConverter::toString(factory->count++, 0, ' ', 0);
    }

    String resource = factory->f(&reference);
    resource.c_str();
    LogManager::getSingleton().logMessage("RBX cr " + resource, 2, false);
    return this;
}
