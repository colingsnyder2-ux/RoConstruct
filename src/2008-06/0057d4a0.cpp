// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern const char signalName[];





struct Base {
    virtual void slot();
    char storage[8];

    Base(void*, std::string);
};

struct SignalDesc : Base {
    void* owner;

    virtual void slot();
    SignalDesc(void*);
};

SignalDesc::SignalDesc(void* object)
    : Base(object ? static_cast<char*>(object) + 0x1c8 : 0,
           std::string(signalName)),
      owner(object)
{
}
