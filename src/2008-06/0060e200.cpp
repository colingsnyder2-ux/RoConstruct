// from server: 100% by king_originala
extern void __cdecl alignedFree(void*);

struct Vector3 {
    float x, y, z;

    Vector3();
    Vector3(int);
    Vector3(const Vector3&);
};

__forceinline Vector3::Vector3()
    : x(0.0f), y(0.0f), z(0.0f)
{
}

__forceinline Vector3::Vector3(int)
{
}

__forceinline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

struct Array {
    void* data;
    int count;
    int capacity;

    Array();
    ~Array();
};

inline Array::Array()
    : count(0), capacity(0)
{
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

extern void __cdecl collect(const void*, Array*);
extern void __cdecl calculate(Vector3*, const Array&, const Vector3&, int);

struct Contact {
    char prefix[8];
    char geometry[32];
    int value;

    Vector3 evaluate(const Vector3&);
};

Vector3 Contact::evaluate(const Vector3& argument)
{
    Array entries;
    collect(geometry, &entries);

    if (entries.count > 0) {
        Vector3 result(0);
        calculate(&result, entries, argument, value);
        return result;
    }

    static const Vector3 zero;
    return zero;
}
