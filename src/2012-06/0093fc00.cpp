// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_7472034aa9c5f055.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
struct Record {char storage[44];~Record();};
typedef std::map<void*,Record> Tree;
typedef std::vector<void*> Sequence;
void __cdecl releaseEntry(const Tree::value_type&);
struct Event
{
    void clear();
};

struct Object
{
    void *getPrimary();
    void *getFirst();
    void *getSecond();
    void *getThird();
    void *getFourth();
    void *getFifth();
    void *getSixth();
};

struct Listener
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void remove(void *);
};

struct PadBase { char padding0[0x2b74]; };
struct ConnBase { char data[0xc4]; };
struct S : PadBase, ConnBase
{
    Tree tree;
    Sequence sequence;
    void *cached;
    Event event;
    char padding1[0xdb];
    Listener *listener;

    void update(unsigned, Object *);
    void setPrimary(void *);
    void attach(void *, int);
};

void S::update(unsigned, Object *object)
{
    std::for_each(tree.begin(),tree.end(),boost::bind(releaseEntry,_1));
    tree.clear();
    event.clear();
    sequence.erase(sequence.begin(),sequence.end());

    void *value = object ? object->getPrimary() : 0;
    setPrimary(value);
    if (object)
    {
        value = object->getFirst();
        attach(value, 1);
        value = object->getSecond();
        attach(value, 0);
        value = object->getThird();
        attach(value, 0);
        value = object->getFourth();
        attach(value, 0);
        value = object->getFifth();
        cached = value;
        attach(value, 0);
        value = object->getSixth();
        attach(value, 0);
    }
    else if (listener)
    {
        listener->remove(static_cast<ConnBase*>(this));
        listener = 0;
    }
}
