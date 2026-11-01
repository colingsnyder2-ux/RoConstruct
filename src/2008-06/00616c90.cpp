// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
typedef void (__cdecl *ErrorHandler)();

namespace RBX {
class Instance;
class Decal;
}

struct Children;

struct Proxy {
    Children* owner;
};

struct Entry {
    RBX::Instance* object;
    void* control;
};

struct Iterator {
    Proxy* proxy;
    Entry* position;
    RBX::Instance* get(ErrorHandler error) const;
    void advance(ErrorHandler error);
};

struct Children {
    Proxy* proxy;
    unsigned int reserved[2];
    Entry* first;
    Entry* last;
    Iterator begin(ErrorHandler error);
    Proxy* end(Entry*& position, ErrorHandler& error);
};

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char padding[0x104];
    Children* children;
};

class Decal : public Instance {
public:
    char padding2[0x34];
    void* value;
};
}

struct Context {
    unsigned int reserved;
    void* value;
};

struct Selection {
    Context* lookup(int argument, RBX::Instance** object, int* temporary);
    RBX::Decal* find(RBX::Instance* object, int argument);
};

inline Iterator Children::begin(ErrorHandler error) {
    Iterator result;
    result.position = first;
    if (first > last)
        error();
    result.proxy = proxy;
    return result;
}

inline Proxy* Children::end(Entry*& position, ErrorHandler& error) {
    position = last;
    error = invalid_parameter_noinfo;
    if (first > position)
        error();
    return proxy;
}

inline RBX::Instance* Iterator::get(ErrorHandler error) const {
    if (!proxy)
        error();
    Children* owner = proxy ? proxy->owner : 0;
    if (position >= owner->last)
        error();
    return position->object;
}

inline void Iterator::advance(ErrorHandler error) {
    if (!proxy)
        error();
    Children* owner = proxy ? proxy->owner : 0;
    if (position >= owner->last)
        error();
    ++position;
}

RBX::Decal* Selection::find(RBX::Instance* object, int argument) {
    int temporary;
    Context* context = lookup(argument, &object, &temporary);
    if (context && object->children) {
        ErrorHandler error;
        Entry*& finishPosition = reinterpret_cast<Entry*&>(argument);
        Proxy* finishProxy = object->children->end(finishPosition, error);
        Iterator current = object->children->begin(error);
        for (;;) {
            if (!current.proxy || current.proxy != finishProxy)
                error();
            if (current.position == finishPosition)
                break;
            RBX::Decal* decal = dynamic_cast<RBX::Decal*>(current.get(error));
            if (decal && decal->value == context->value)
                return decal;
            current.advance(error);
        }
    }
    return 0;
}
