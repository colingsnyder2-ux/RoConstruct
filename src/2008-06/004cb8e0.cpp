// from server: 100% by colin
// from server: 81% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_espeon_senderexternalassignmentfe6548abc09e4e8a.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <functional>
struct S {
 void* key;
 unsigned control;
 double priority;
 char storage[52];
 void* secondary;
 char tail[8];
 ~S();
 S& operator=(const S&);
};
typedef boost::multi_index_container<S,boost::multi_index::indexed_by<boost::multi_index::hashed_unique<boost::multi_index::member<S,void*,&S::key> >,boost::multi_index::ordered_non_unique<boost::multi_index::member<S,double,&S::priority>,std::greater<double> >,boost::multi_index::ordered_unique<boost::multi_index::member<S,void*,&S::secondary> > > > Table;
struct Modifier { void operator()(S&) const; };
bool modifySender(Table& t, Table::iterator it) { return t.modify(it,Modifier()); }

void growSender(Table& t, unsigned n) { t.rehash(n); }
bool replaceSender(Table& t, Table::iterator it, const S& value) { return t.replace(it,value); }
