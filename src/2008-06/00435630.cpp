// from server: 100% by colin
#include <list>
#include <algorithm>

struct Text;
struct Parameter;

struct Visitor {
    void (__cdecl *function)(int*, Text*, Parameter*&);
    int* count;
    Text* text;
    void operator()(Parameter*& parameter) { function(count, text, parameter); }
};

typedef std::list<Parameter*>::iterator Iterator;

template Visitor std::for_each<Iterator, Visitor>(Iterator, Iterator, Visitor);
