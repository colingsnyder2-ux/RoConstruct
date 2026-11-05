// test lua_exception with try/catch to force C++ EH frame
// roc-flags: /O2 /GS- /MD /EHsc
extern "C" void luaD_realloc(void* L, int n);

namespace std {
    class __declspec(dllimport) exception {
    public:
        virtual ~exception();
    };
}

struct lua_exception : std::exception {
    char padding[8];
    void* L;
    void* field_10;
    char flag_14;
    
    virtual ~lua_exception();
};

lua_exception::~lua_exception() {
    try {
        if (flag_14) {
            if (field_10) {
                *(unsigned long*)((char*)field_10 + 8) = 0;
            }
            luaD_realloc(L, -2);
        }
    }
    catch (...) {
    }
    // base destructor called automatically
}