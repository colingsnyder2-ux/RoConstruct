// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_4c382e7d776dca1a.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define BOOST_MULTI_INDEX_DISABLE_COMPRESSED_ORDERED_INDEX_NODES
#include <cstddef>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/identity.hpp>
namespace RBX { class PVInstance; }
struct Item {
	RBX::PVInstance* instance;
	char data[0x278];
	int order;
	bool operator==(const Item& other) const { return instance == other.instance; }
};
std::size_t hash_value(const Item& item);
typedef boost::multi_index_container<Item,
	boost::multi_index::indexed_by<
		boost::multi_index::hashed_unique<boost::multi_index::identity<Item> >,
		boost::multi_index::ordered_non_unique<boost::multi_index::member<Item, int, &Item::order> >
	> > Items;
typedef Items::nth_index<0>::type HashIndex;
template bool HashIndex::modify_(HashIndex::node_type*);
