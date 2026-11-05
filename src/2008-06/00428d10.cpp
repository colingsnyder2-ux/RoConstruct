// from server: 100% by colin
namespace std {
template<class T> struct char_traits;
template<class T> struct allocator;

template<class T, class Traits, class Alloc>
struct basic_string {
    unsigned char storage[28];
    __declspec(dllimport) basic_string(const T*);
    basic_string(const basic_string&);
    ~basic_string();
    const T* c_str() const;
};
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

extern void (__thiscall* stringConstruct)(String*, const char*);
extern void (__thiscall* stringDestroy)(String*);
extern const char* (__thiscall* stringData)(const String*);

namespace std {
template<class T, class Traits, class Alloc>
inline basic_string<T, Traits, Alloc>::~basic_string()
{
    stringDestroy(this);
}

template<class T, class Traits, class Alloc>
inline const T* basic_string<T, Traits, Alloc>::c_str() const
{
    return stringData(this);
}
}

void __cdecl operator delete(void*) throw();

struct Shader {
    virtual ~Shader();
};

extern Shader* __cdecl getShader();
extern String __cdecl getShaderPath();
extern String __cdecl archiveFile(const char*, String);
extern int archiveMode;
extern void* currentManager;

struct Primary {
    virtual void primarySlot();
};

struct StreamBase {
    unsigned char storage[36];
    virtual ~StreamBase();
};

template<class T>
struct OwnedPointer {
    T* pointer;
    ~OwnedPointer();
};

template<class T>
inline OwnedPointer<T>::~OwnedPointer()
{
    delete pointer;
}

struct LogManager : Primary, StreamBase {
    OwnedPointer<char> buffer;
    String filename;
    virtual ~LogManager();
};

LogManager::~LogManager()
{
    if (getShader()) {
        String path = getShaderPath();
        Shader* shader = getShader();
        if (shader)
            delete shader;

        if (archiveMode == 2)
            archiveFile(path.c_str(), String("error\\"));
        else
            archiveFile(path.c_str(), String("archive\\"));
    }

    currentManager = 0;
}
