// from server: 53% by king_originala
namespace std {
struct exception {
    virtual ~exception();
    virtual const char* what() const;
};

struct string {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;

    string();
    string(const char*);
    ~string();
    const char* c_str() const;
};

__forceinline const char* string::c_str() const
{
    return capacity < 16 ? storage.buffer : storage.pointer;
}

string operator+(const string&, const char*);
}

namespace Ogre {
enum LogMessageLevel {
    LML_TRIVIAL = 1,
    LML_NORMAL = 2,
    LML_CRITICAL = 3
};

struct LogManager {
    static LogManager& getSingleton();
    void logMessage(const std::string&, LogMessageLevel, bool);
};
}

extern "C" int __stdcall MoveFileExA(
    const char*, const char*, unsigned long);

struct Reference {
    virtual void unused();
    virtual void release();
    unsigned int reserved;
    unsigned int* count;

    ~Reference();
};

__forceinline Reference::~Reference()
{
    if (count) {
        --*count;
        if (*count == 0)
            release();
    }
}

struct ViewRbxGfx {
    void updateSkybox(const char* destination);
};

void ViewRbxGfx::updateSkybox(const char* destination)
{
    std::string original[6];
    std::string first(destination);
    std::string second(destination);
    std::string third(destination);
    std::string fourth(destination);
    std::string fifth(destination);
    std::string sixth(destination);
    std::string paths[6];
    std::string seventh(destination);
    std::string eighth(destination);
    std::string results[6];
    std::string ninth(destination);
    Reference reference;
    reference.count = 0;

    for (int i = 0; i < 6; ++i) {
        try {
            std::string temporary(results[i].c_str());
        }
        catch (const std::exception& error) {
            Ogre::LogManager::getSingleton().logMessage(
                std::string("RBX error in skybox: ") + error.what(),
                Ogre::LML_NORMAL,
                false);
        }

        MoveFileExA(paths[i].c_str(), destination, 1);
    }
}
