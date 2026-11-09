// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace RBX {
struct Key {
	int a, b;
	bool operator<(const Key& other) const;
};
struct Bucket {
	double d;
	char pad[0x140];
};
}
typedef std::map<RBX::Key, RBX::Bucket> M;
typedef M::_Mybase T;
template T::iterator T::insert(T::const_iterator, const T::value_type&);
