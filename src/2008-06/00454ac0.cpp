// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <memory>

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long use;
    volatile long weak;
    void release()
    {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};

template <class T>
struct Shared {
    T* px;
    Control* pn;
    Shared(const Shared& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->use);
    }
    ~Shared()
    {
        if (pn)
            pn->release();
    }
    template <class U>
    Shared(const Shared<U>& other) : px(other.px), pn(other.pn)
    {
        if (pn)
            _InterlockedIncrement(&pn->use);
    }
    T* operator->() const { return px; }
};

struct Variant {
    int value;
    ~Variant();
};
struct Tuple : std::vector<Variant> {
    ~Tuple();
};

template <class T>
struct AutoPtr {
    T* p;
    ~AutoPtr() { delete p; }
};

extern const char* (__thiscall *string_c_str)(const std::string*);

struct ScriptContext {
    std::auto_ptr<Tuple> execute(int security, const char* script, const char* name, Tuple& args);
};

struct Instance {
    int reserved;
};

struct DataModel : Instance {
    ScriptContext* scriptContext();
};

struct Lock {
    Lock(Shared<Instance> instance);
    ~Lock();
    char storage[0xc];
};

struct Doc {
    Shared<DataModel> getDataModel() const;
    int run(std::string script);
};

int Doc::run(std::string script)
{
    Lock lock(getDataModel());
    Tuple args;
    try {
        getDataModel()->scriptContext()->execute(1, string_c_str(&script), "Doc script", args);
        return 1;
    } catch (...) {
        return 0;
    }
}
