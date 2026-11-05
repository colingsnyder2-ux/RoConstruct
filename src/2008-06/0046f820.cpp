// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>

struct Object {
    virtual ~Object();
};

struct Objects : std::vector<Object*> {
    Object*& at(unsigned int);
    iterator erase(iterator, iterator);
};

struct S {
    std::string name;
    Objects objects;

    virtual ~S();
};

S::~S()
{
    unsigned int count = objects.size();
    for (unsigned int i = 0; i < count; ++i) {
        Object *p = objects.at(i);
        if (p)
            delete p;
    }
    objects.erase(objects.begin(), objects.end());
}
