// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_eventfront_9136a3c85628154f.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
typedef std::string String;
typedef boost::shared_ptr<void> Shared;
struct Object {
    char padding[20];
    char value;
};

struct E {
    char padding[28];
    String text;
    Object* object;
    unsigned unused;
    Shared shared;

    E(const E&);
    ~E();
};

typedef std::list<E> List;
struct Consumer {
    char storage[72];
    void consume(E);
};

struct Configuration {
    char padding[304];
    unsigned limit;
};

extern Configuration* __cdecl configuration();

struct Dispatcher {
    void send(void*, String, Shared);
};

extern Dispatcher dispatcher;
struct S {
    char padding[304];
    Consumer consumer;
    List list;

    void f(const E*);
};

void S::f(const E* value) {
    list.push_front(*value);
    while(list.size()>configuration()->limit)list.pop_back();
    consumer.consume(*value);

    void* object = value->object ? &value->object->value : 0;
    dispatcher.send(
        object, value->text, value->shared);
}