// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_physicsnativecleanup42da6f112eb9d238.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <boost/shared_ptr.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <G3D/CoordinateFrame.h>
#include <functional>
#include <stddef.h>
// Value and three index keys established by the server-exact PhysicsSender update.
struct PhysicsRecord {
 boost::shared_ptr<void> part;
 double priority;
 G3D::CoordinateFrame previous;
 float scale;
 int sequence;
 float distance;
 PhysicsRecord(const PhysicsRecord&);
 
};
struct PartHash {size_t operator()(const boost::shared_ptr<void>&p)const{return boost::hash<void*>()(p.get());}};
namespace bmi=boost::multi_index;
typedef boost::multi_index_container<PhysicsRecord,bmi::indexed_by<
 bmi::hashed_unique<bmi::member<PhysicsRecord,boost::shared_ptr<void>,&PhysicsRecord::part>,PartHash>,
 bmi::ordered_non_unique<bmi::member<PhysicsRecord,double,&PhysicsRecord::priority>,std::greater<double> >,
 bmi::ordered_non_unique<bmi::member<PhysicsRecord,int,&PhysicsRecord::sequence> >
> > PhysicsRecords;
struct Modifier {void operator()(PhysicsRecord&)const;};
bool modifyPhysics(PhysicsRecords&t,PhysicsRecords::iterator i){return t.modify(i,Modifier());}
bool replacePhysics(PhysicsRecords&t,PhysicsRecords::iterator i,const PhysicsRecord&v){return t.replace(i,v);}
void rehashPhysics(PhysicsRecords&t,unsigned n){t.rehash(n);}
void erasePhysics(PhysicsRecords&t,PhysicsRecords::iterator i){t.erase(i);}
std::pair<PhysicsRecords::iterator,bool>insertPhysics(PhysicsRecords&t,const PhysicsRecord&v){return t.insert(v);}
typedef char ValueSize[sizeof(PhysicsRecord)==80?1:-1];
typedef char SequenceOffset[offsetof(PhysicsRecord,sequence)==68?1:-1];

void clearPhysics(PhysicsRecords&t){t.clear();}
PhysicsRecords*newPhysics(){return new PhysicsRecords;}
void deletePhysics(PhysicsRecords*p){delete p;}
