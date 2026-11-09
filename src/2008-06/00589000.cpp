// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_variantmap_bf7f519b9c063a40.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Object {
    virtual ~Object();
    virtual void reserved();
    virtual Object *clone();
};

struct Value {
    void *type;
    Object *object;

    Value();
    Value(const Value &);
    ~Value();
};

inline Value::Value(const Value &other)
{
    void *t = other.type;
    Object *p = other.object;
    type = t;
    object = p ? p->clone() : 0;
}

inline Value::~Value()
{
    if (object)
        delete object;
}


typedef std::map<unsigned int,Value> Map;
Value& f(Map& map,const unsigned int& key){return map[key];}
