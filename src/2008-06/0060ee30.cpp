// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_4d304d60fb72bb72.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Object {
    void setEnabled(bool);
};

struct Container {
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

extern void __cdecl prepare(Container*);
extern bool __cdecl predicate(boost::shared_ptr<Object>);

void __cdecl update(Container* container)
{
    prepare(container);
    for (unsigned i = 0; i < container->size(); ++i) {
        boost::shared_ptr<Object> value = (*container)[i].lock();
        if (predicate(value))
            value->setEnabled(true);
    }
}
