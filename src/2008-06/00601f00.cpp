// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void* (__cdecl *allocate)(size_t);

inline void* __cdecl operator new(size_t size)
{
    return allocate(size);
}

void __cdecl operator delete(void*);

namespace std {
    class string;
}

extern void (__thiscall *constructString)(std::string*, const char*);
extern void (__thiscall *destroyString)(std::string*);

namespace std {
    class string {
        char storage[28];
    public:
        string(const char*);
        ~string();
    };

    inline string::string(const char* text)
    {
        constructString(this, text);
    }

    inline string::~string()
    {
        destroyString(this);
    }
}

struct EmptyDeleter {};

struct Object {
    char storage[388];
    Object(int, int, const std::string&);
};

struct Result {
    void* object;
    void* owner;

    Result(Object*, EmptyDeleter);
    ~Result();
};

Result __cdecl create(int first, int second, const char* name);

Result __cdecl create(int first, int second, const char* name)
{
    return Result(new Object(first, second, std::string(name)),
                  EmptyDeleter());
}
