// from server: 100% by EspClaude
// from server: 98% by colin
// from server: 82% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_82604c713942e3f8.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>
struct S {
 double before; void* object; char after[0x274];
 ~S();
 bool keep(unsigned value) const;
};
struct Key { typedef const S& result_type; const S& operator()(const S& s) const { return s; } };
struct Hash { size_t operator()(const S&) const; };
struct Equal { bool operator()(const S&,const S&) const; };
struct Less { bool operator()(const S&,const S&) const; };
typedef boost::multi_index::member<S,void*,&S::object> ObjectKey;
typedef boost::multi_index_container<S, boost::multi_index::indexed_by<boost::multi_index::hashed_unique<Key,Hash,Equal>,boost::multi_index::ordered_non_unique<ObjectKey > > > Table;
struct Modifier { void operator()(S&) const; };
bool modifyReceiver(Table& t, Table::iterator it) { return t.modify(it,Modifier()); }

