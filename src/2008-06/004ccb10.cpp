// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espeon_senderobservedgap99130102c930ce05.cpp

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
};
typedef boost::multi_index_container<S,boost::multi_index::indexed_by<boost::multi_index::hashed_unique<boost::multi_index::member<S,void*,&S::key> >,boost::multi_index::ordered_non_unique<boost::multi_index::member<S,double,&S::priority>,std::greater<double> >,boost::multi_index::ordered_unique<boost::multi_index::member<S,void*,&S::secondary> > > > Table;
struct Sender {
 virtual ~Sender();
 Table table;
 // Target constructs table at +4 and stores owner at +0x3c; table occupies 0x34 bytes.
 char tableTail[4];
 void* owner;
 unsigned a40,a44,a48,a4c,a50,a54;
 bool a58; char p59[3]; bool a5c; char p5d[3];
 unsigned a60,a64,a68; bool a6c; char p6d[3]; bool a70;
 Sender(void*);
};
Sender::Sender(void* p):owner(p),a40(0),a44(0),a48(0),a50(0),a54(0),a58(false),a5c(false),a64(0),a68(0),a6c(false),a70(false) {}
