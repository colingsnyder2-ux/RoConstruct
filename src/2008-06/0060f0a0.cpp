// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_212d4950c50f93ed.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise, off)
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Matrix
{
    float elements[9];
    bool equals(const Matrix&) const;
};

struct Transform
{
    Matrix rotation;
    float x, y, z;
};

struct Part
{
    bool enabled() const;
    const Transform* getTransform() const;
    void setTransform(const Transform&);
};

struct Container {
    unsigned reserved[3];
    boost::weak_ptr<Part>* first;
    boost::weak_ptr<Part>* last;
    unsigned size() const { return (unsigned)(last - first); }
    const boost::weak_ptr<Part>& operator[](unsigned pos) const
    {
        if (pos >= size())
            _invalid_parameter_noinfo();
        return *(first + pos);
    }
};

extern float adjustment;
extern void __cdecl adjustTransform(Transform*, const Transform*, float);

void __cdecl updateParts(const Container* parts)
{
    for (unsigned i = 0; i < parts->size(); ++i) {
        boost::shared_ptr<Part> part = (*parts)[i].lock();
        Part* object = part.get();
        if (object && object->enabled())
        {
            const Transform* current = object->getTransform();
            Transform next;
            adjustTransform(&next, current, adjustment);
            if (!(next.x == current->x &&
                  next.y == current->y &&
                  next.z == current->z &&
                  next.rotation.equals(current->rotation)))
                object->setTransform(next);
        }
    }
}
