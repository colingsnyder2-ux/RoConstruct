// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_physicsnativelookuporder1c54654781b870d3.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <G3D/CoordinateFrame.h>
struct Thing;
typedef boost::shared_ptr<Thing> Shared;
Shared __cdecl convert(const Shared&);
struct Node {
 Shared value;
 double timeKey;
 G3D::CoordinateFrame frame;
 float priority;
 int orderKey;
 float distance;
 Node(Shared);
 Node(const Node&);
};
typedef char NodeSizeCheck[sizeof(Node)==80?1:-1];
struct SharedHash { size_t operator()(const Shared& value) const { return boost::hash<Thing*>()(value.get()); } };
namespace bmi=boost::multi_index;
typedef boost::multi_index_container<Node,bmi::indexed_by<
 bmi::hashed_unique<bmi::member<Node,Shared,&Node::value>,SharedHash >,
 bmi::ordered_non_unique<bmi::member<Node,double,&Node::timeKey>,std::greater<double> >,
 bmi::ordered_non_unique<bmi::member<Node,int,&Node::orderKey> >
> > Tree;
struct S { unsigned long unused; Tree tree; void f(Shared); };
void S::f(Shared argument) {
 Shared value=convert(argument);
 Tree::nth_index<0>::type& search=tree.get<0>();
 Tree::nth_index<0>::type::iterator position=search.find(value);
 if(position==search.end()) search.insert(Node(value));
}
