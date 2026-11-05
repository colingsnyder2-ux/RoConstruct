// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_13ae11d352497826.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/shared_ptr.hpp>
struct T;
struct K { int a[4]; bool operator<(const K& o) const { return a[0] < o.a[0]; } };
struct S {
 boost::shared_ptr<T> p; K k; __int64 a8; char before[0x24]; void* object; char after[8];
 bool keep(unsigned value) const;
};
struct Key { typedef const S& result_type; const S& operator()(const S& s) const { return s; } };
struct Hash { size_t operator()(const S&) const; };
struct Equal { bool operator()(const S&,const S&) const; };
struct Less { bool operator()(const S&,const S&) const; };
struct ObjectKey { typedef void* result_type; void* operator()(const S& s) const { return s.object; } };
typedef boost::multi_index_container<S, boost::multi_index::indexed_by<boost::multi_index::hashed_unique<Key,Hash,Equal>,boost::multi_index::ordered_unique<boost::multi_index::member<S,K,&S::k> >,boost::multi_index::ordered_non_unique<ObjectKey > > > Table;
struct Modifier { void operator()(S&) const; };
bool modifyReceiver(Table& t, Table::iterator it) { return t.modify(it,Modifier()); }

