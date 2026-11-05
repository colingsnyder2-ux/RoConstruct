// from server: 100% by EspClaude
// from server: 81% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_761f79aaf529f9d5.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
typedef std::string String;
typedef boost::shared_ptr<void> Shared;

struct Target {
    void send(String, Shared);
};

struct Object {
    char padding[0xd0];
    Target target;
};

struct E {
    char padding[28];
    String text;
    boost::shared_ptr<Object> object;
    Shared shared;

    E(const E&);
    ~E();
};

typedef std::list<E> List;

struct Task {
    char data[0x4c];
    Task(const Task&);
    ~Task();
};

extern void handler();
extern bool handlerFlag;
extern Task __cdecl makeTask(void (*)(), bool, E);

struct Queue {
    void post(Task);
};

struct Configuration {
    char padding[0x8c];
    unsigned limit;
};

extern Configuration* __cdecl configuration();

struct S {
    char padding[0xb4];
    List list;
    char padding2[0xf8 - 0xb4 - sizeof(List)];
    Queue queue;

    void f(const E*);
};

void S::f(const E* value) {
    list.push_front(*value);
    while(list.size()>configuration()->limit)list.pop_back();
    queue.post(makeTask(handler, handlerFlag, *value));
    value->object->target.send(value->text, value->shared);
}
