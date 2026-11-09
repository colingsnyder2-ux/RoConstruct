// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_espeon_interpolationrehashfreehashddb2cbee99c4423b.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
struct __declspec(align(8)) S {
 char storage[0x280];
 ~S();
 bool keep(unsigned value) const;
};
struct Key { typedef const S& result_type; const S& operator()(const S& s) const { return s; } };
size_t __cdecl hash_value(const S&);
struct Hash { size_t operator()(const S& s) const { return hash_value(s); } };
struct Equal { bool operator()(const S&,const S&) const; };
struct Less { bool operator()(const S&,const S&) const; };
typedef boost::multi_index_container<S, boost::multi_index::indexed_by<boost::multi_index::hashed_unique<Key,Hash,Equal>,boost::multi_index::ordered_non_unique<Key,Less> > > Table;
struct Receiver {
 char prefix[8];
 Table table;
 void update(unsigned value);
};
void Receiver::update(unsigned value) {
 Table::nth_index<0>::type& index=table.get<0>();
 Table::iterator it=index.begin(), end=index.end();
 while(it!=end) {
  if(!it->keep(value)) it=index.erase(it);
  else ++it;
 }
}

void reserveInterpolation(Table& table,unsigned n) { table.get<0>().rehash(n); }
