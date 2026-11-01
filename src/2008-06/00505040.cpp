// from server: 100% by king_originala
extern "C" long (__stdcall *InterlockedDecrement)(volatile long *);
extern const double *infinitySource;

struct Object {
    virtual ~Object();
    volatile long references;
    void release();
};

struct Reference {
    Object *pointer;
    Reference();
    ~Reference();
    Reference &operator=(Object *);
};

inline Reference::Reference() : pointer(0) {}

inline Reference::~Reference() {
    if (pointer && InterlockedDecrement(&pointer->references) == 0) {
        pointer->release();
        if (pointer)
            delete pointer;
    }
}

Reference makeLighting();

struct Array {
    void *data;
    int count;
    int capacity;
    Array();
    ~Array();
};

inline Array::Array() {
    count = 0;
    capacity = 0;
    data = 0;
}

struct Shader {
    unsigned char storage[32];
    Shader();
    ~Shader();
};

struct Matrix {
    unsigned char storage[248];
    Matrix();
};

struct Base {
    unsigned char storage[612];
    Base();
    virtual ~Base();
};

struct Scene : Base {
    Array array0;
    Array array1;
    Array array2;
    Array array3;
    Array array4;
    Array array5;
    Shader shader;
    Reference first;
    unsigned char unused[20];
    Reference current;
    Reference previous;
    bool enabled;
    float distance;
    Array additional;
    bool active;
    Reference last;
    unsigned char padding[4];
    Matrix firstMatrix;
    Matrix secondMatrix;

    Scene();
    virtual ~Scene();
};

inline float initialDistance() {
    static double value = *infinitySource;
    return (float)value;
}

Scene::Scene()
    : enabled(false),
      distance(initialDistance()),
      active(false)
{
    previous = makeLighting().pointer, current = previous.pointer;
}
