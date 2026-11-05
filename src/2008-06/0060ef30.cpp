// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_652c8a4937850eb7.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Vector3 {
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct Object {
    void setState(int);
    void setLinear(const Vector3&);
    void setAngular(const Vector3&);
};

struct Collection {
    unsigned reserved[3];
    boost::weak_ptr<Object>* first;
    boost::weak_ptr<Object>* last;
    unsigned size() const { return (unsigned)(last - first); }
    boost::weak_ptr<Object>& operator[](unsigned pos)
    {
        if (pos >= size())
            _invalid_parameter_noinfo();
        return *(first + pos);
    }
};

extern void __cdecl prepare(Collection*);
extern bool __cdecl eligible(boost::shared_ptr<Object>);

inline const Vector3& zeroVector()
{
    static Vector3 value;
    return value;
}

void __cdecl process(Collection* collection)
{
    prepare(collection);
    for (unsigned i = 0; i < collection->size(); ++i) {
        boost::shared_ptr<Object> pointer = (*collection)[i].lock();
        if (eligible(pointer)) {
            pointer->setState(0);
            if (collection->size() == 1) {
                pointer->setLinear(zeroVector());
                pointer->setAngular(zeroVector());
            }
        }
    }
}
