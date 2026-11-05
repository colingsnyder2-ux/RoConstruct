// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern std::string* (__thiscall * const stringCopy)(std::string*, const std::string&);
extern void (__thiscall * const stringDestroy)(std::string*);





struct Base
{
    unsigned char storage[8];

    Base(void*, std::string);
    virtual ~Base();
};

struct ClearBackpack : Base
{
    void* volatile owner;
    void* volatile target;
    volatile unsigned int state;
    volatile unsigned int flags;

    ClearBackpack(std::string, void*);
    virtual ~ClearBackpack();
};

ClearBackpack::ClearBackpack(std::string name, void* object)
    : Base(object ? static_cast<char*>(object) + 0x2ec : 0, name),
      owner(object),
      target(object),
      state(0),
      flags(0)
{
}
