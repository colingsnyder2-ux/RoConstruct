// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectionlocal_1158e1c2590f06c3.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Instance;
struct Entries;
extern boost::shared_ptr<Instance> __cdecl acquire(Instance*);
struct Listener
{
    void attach(void*);
};

struct Instance
{
    char padding[0xa4];
    Listener listener;
};

struct Iterator
{
    void* owner;
    boost::shared_ptr<Instance>* position;
};

struct Entries
{
    void* owner;
    unsigned long padding[2];
    boost::shared_ptr<Instance>* first;
    boost::shared_ptr<Instance>* last;

    void append(const boost::shared_ptr<Instance>&);
    Iterator begin();
    Iterator end();
};

inline Iterator Entries::begin()
{
    boost::shared_ptr<Instance>* start = first;
    if (start > last)
        _invalid_parameter_noinfo();
    Iterator result;
    result.owner = owner;
    result.position = start;
    return result;
}

inline Iterator Entries::end()
{
    boost::shared_ptr<Instance>* finish = last;
    if (first > finish)
        _invalid_parameter_noinfo();
    Iterator result;
    result.owner = owner;
    result.position = finish;
    return result;
}

inline Iterator find_entry(Iterator current, Iterator finish,
                           Instance* const& value)
{
    boost::shared_ptr<Instance>* position = current.position;
    boost::shared_ptr<Instance>* end = finish.position;
    while (position != end) {
        if (position->get() == value) break;
        ++position;
    }
    current.position = position;
    return current;
}

struct Holder
{
    boost::shared_ptr<Entries>* get();
};

struct Selection
{
    char padding[0x150];
    unsigned long signal;
    Holder holder;

    void notify(boost::shared_ptr<Instance>);
    void select(Instance*);
};

void Selection::select(Instance* instance)
{
    boost::shared_ptr<Instance> item = acquire(instance);
    boost::shared_ptr<Entries> entries(*holder.get());

    Entries* list = entries.get();
    Iterator finish = list->end();
    Iterator initial = list->begin();
    Iterator current = find_entry(initial, finish, item.get());

    finish = list->end();
    if (!current.owner || current.owner != finish.owner)
        _invalid_parameter_noinfo();

    if (current.position == finish.position)
    {
        list->append(item);
        instance->listener.attach(this ? &signal : 0);
        notify(item);
    }
}
