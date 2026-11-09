// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1-dll roc_espeon_replicatornativevectore25554b5975257eb.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <vector>
struct Target;
struct __multiple_inheritance S;

typedef boost::shared_ptr<Target> Pair;

extern Pair __cdecl makePair(Target*);

typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void,S,Target*>, boost::_bi::list2<boost::_bi::value<S*>,boost::arg<1> > > Callback;

typedef std::vector<Target*> Listener;

struct Target {
    void connect(Callback);
};

struct Base1 {};
struct Base2 {};

struct S : Base1, Base2 {
    char padding[0x2c57];
    Listener listener;

    void update(Target*, unsigned);
    void apply(Pair, unsigned);
    void onEvent(Target*);
};

void S::update(Target* target, unsigned value)
{
    Target* original = target;
    if (original) {
        listener.push_back(target);
        apply(makePair(original), value);

        Callback callback = boost::bind(&S::onEvent, this, _1);
        original->connect(callback);
    }
}

