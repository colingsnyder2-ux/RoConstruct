// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_nonfactory_f8222f6bff20d1fd.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Result : Shared {};

struct Source {
    Result f(Source* source);
};

struct Receiver {
    void accept(void* key, Shared value);
};

struct S {
    void* key;
    Source source;
    void f(void* unused1, Receiver* receiver, Source* owner, void* unused2);
};

void S::f(void*, Receiver* receiver, Source* owner, void*)
{
    receiver->accept(key, owner->f(&source));
}