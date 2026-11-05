// from server: 100% by tester
typedef void (__thiscall *ExceptionCtor)(void *);
typedef void (__thiscall *StringCtor)(void *, const char *);
typedef void (__thiscall *StringCopyCtor)(void *, const void *);

extern ExceptionCtor exceptionCtor;
extern StringCtor stringCtor;
extern StringCopyCtor stringCopyCtor;
extern const char runtimeErrorVtable[];

namespace std {
    class exception {
    protected:
        const void *vtable;
        char *message;
        int owned;
    public:
        exception();
        ~exception();
        const char *what() const;
    };

    class string {
        char storage[28];
    public:
        string(const char *);
        string(const string &);
        ~string();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string &);
        ~runtime_error();
        const char *what() const;
    };

    __forceinline exception::exception()
    {
        exceptionCtor(this);
    }

    __forceinline string::string(const char *text)
    {
        stringCtor(this, text);
    }

    __forceinline string::string(const string &other)
    {
        stringCopyCtor(this, &other);
    }

    __forceinline runtime_error::runtime_error(const string &text)
        : exception(), message((vtable = runtimeErrorVtable, text))
    {
    }
}

struct S_func_005eed50 {
    void f();
};

void S_func_005eed50::f()
{
    throw std::runtime_error(
        std::string("SurfaceDescriptor::get not implemented"));
}
