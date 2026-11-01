// from server: 100% by colin
#include <exception>
struct StandardOut {
    void print(int, const char *, ...);
};
struct OutHandle {
    StandardOut *pointer;
    void *count;
    ~OutHandle();
    StandardOut *operator->() const { return pointer; }
};
OutHandle __cdecl singleton();
struct __declspec(dllimport) RocString {
    char storage[28];
    RocString(const char *);
    ~RocString();
    const char *c_str() const;
};
struct World;
struct Listener {
    virtual void onEvent(const World *, int) = 0;
};
struct S {
    void raise(int event, Listener *listener);
};
void S::raise(int event, Listener *listener)
{
    try {
        listener->onEvent(reinterpret_cast<const World *>(this), event);
    }
    catch (std::exception *e) {
        RocString what(e->what());
        singleton()->print(2, "Exception caught in onEvent. %s", what.c_str());
    }
}
