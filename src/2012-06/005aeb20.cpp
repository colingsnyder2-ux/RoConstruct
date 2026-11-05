// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espeon_receivernonpodfunctorsbbcab0aa6dd9a911.cpp

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
struct Key { Key() {} typedef const S& result_type; const S& operator()(const S& s) const { return s; } };
struct Hash { Hash() {} size_t operator()(const S&) const; };
struct Equal { Equal() {} bool operator()(const S&,const S&) const; };
struct Less { Less() {} bool operator()(const S&,const S&) const; };
typedef boost::multi_index_container<S, boost::multi_index::indexed_by<boost::multi_index::hashed_unique<Key,Hash,Equal>,boost::multi_index::ordered_non_unique<Key,Less> > > Table;
struct Receiver {
 virtual ~Receiver();
 void* owner;
 Table table;
 Receiver(void*);
};
Receiver::Receiver(void* p):owner(p) {}
