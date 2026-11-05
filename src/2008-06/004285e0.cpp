// from server: 100% by colin
extern void (__thiscall *stringCopy)(void*, const void*);
extern void (__thiscall *stringConstruct)(void*, const char*);
extern void (__thiscall *stringDestroy)(void*);
extern const char* (__thiscall *stringData)(const void*);

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class C, class T, class A>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const basic_string&);
        __declspec(dllimport) basic_string(const C*);
        ~basic_string();
        const C* c_str() const;
    };

    template<class C, class T, class A>
    inline basic_string<C, T, A>::basic_string(const basic_string& other)
    {
        stringCopy(this, &other);
    }

    template<class C, class T, class A>
    inline basic_string<C, T, A>::~basic_string()
    {
        stringDestroy(this);
    }

    template<class C, class T, class A>
    inline const C* basic_string<C, T, A>::c_str() const
    {
        return stringData(this);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct LogRecord {
    virtual ~LogRecord();
    unsigned char padding[28];
    int kind;
    std::string path;
};

std::string __cdecl relocateLog(const char*, std::string);

struct MainLogManager {
    virtual ~MainLogManager();
    LogRecord* record;
    unsigned int padding;
    std::string path;
};

MainLogManager::~MainLogManager()
{
    if (record) {
        std::string savedPath(record->path);
        int kind = record->kind;
        delete record;
        record = 0;

        if (kind == 2)
            relocateLog(savedPath.c_str(), "error\\");
        else
            relocateLog(savedPath.c_str(), "archive\\");
    }
}
