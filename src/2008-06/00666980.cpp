// from server: 100% by king_originala
extern const float initialX;
extern const float initialY;

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct GroupDragTool : Primary, Secondary {
    char pad[0x98];
    float fieldA0;
    float fieldA4;

    GroupDragTool(void* a, float x, float y);
    ~GroupDragTool();
};

struct ValueResult {
    void* value;
};

struct RunStateOwner {
    ValueResult setValue(float value);
};

struct LookupResult {
    char pad[0x10];
    RunStateOwner owner;
};

struct Lookup {
    LookupResult* find(void* object);
};

extern Lookup lookup;

struct Vector {
    float x;
    float y;
    float z;

    Vector();
};

inline Vector::Vector() : x(0.0f), y(0.0f), z(0.0f)
{
}

struct Landed : GroupDragTool {
    Vector first;
    Vector second;
    Vector third;

    Landed(void* a);
    virtual ~Landed();
};

Landed::Landed(void* a)
    : GroupDragTool(a, initialX, initialY)
{
    LookupResult* result =
        lookup.find(a ? static_cast<char*>(a) + 0x14 : 0);
    if (result)
        result->owner.setValue(0.0f);
}
