// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// SpawnPlayer reconstructed from complete005d2b80, with native SDK service/ownership/container APIs.
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
#include <cstdlib>
#include <typeinfo>
#include <cstddef>
#include <intrin.h>
namespace boost {
namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;
namespace detail {
// Actual Boost1.34.1 Windows counted base; only unused methods are omitted.
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class shared_count {sp_counted_base*pi_;
public:shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {T*px;detail::shared_count pn;
template<class Y>friend class shared_ptr;
public:shared_ptr():px(0),pn(){}
 template<class Y>shared_ptr(const shared_ptr<Y>&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}
 typedef T*shared_ptr::*unspecified_bool_type;
 operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
};
}

namespace G3D {
class Vector3 {public:float x,y,z;Vector3():x(0.0f),y(0.0f),z(0.0f){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}};
class Matrix3 {public:float elt[3][3];};
class CoordinateFrame {public:Matrix3 rotation;Vector3 translation;};
}
namespace RBX {
// Opaque primary native base views only; no Instance-family objects or RTTI are created here.
class Instance {public:void setParent(Instance*);};
class PVInstance:public Instance {};
class ModelInstance:public PVInstance {};
class RootInstance:public ModelInstance {public:void moveToPoint(PVInstance*,G3D::Vector3);};
class Workspace:public RootInstance {};
class ForceField:public Instance {};
template<class Root>class Creatable {public:template<class T>static boost::shared_ptr<T>create();};
class DebrisService:public Instance {public:void addItem(boost::shared_ptr<Instance>,double);};
class ServiceProvider {public:template<class T>static T*find(const Instance*);};
class BrickColor {int number;public:bool operator==(const BrickColor&r)const{return number==r.number;}};
namespace Network {class Player:public Instance {public:char unobserved00[0x178];BrickColor teamColor;bool neutral;bool getNeutral()const{return neutral;}BrickColor getTeamColor()const{return teamColor;}};}
class SpawnLocation:public Instance {public:char unobserved00[0x3e8];BrickColor teamColor;char unobserved3ec[0x14];bool neutral;char unobserved401[3];int forcefieldDuration;BrickColor getTeamColor()const{return teamColor;}const G3D::CoordinateFrame&getCoordinateFrame()const;};
class SpawnerService:public Instance {public:char unobserved00[0x130];std::list<SpawnLocation*>spawners;void SpawnPlayer(boost::shared_ptr<ModelInstance>,Network::Player*);};
void SpawnerService::SpawnPlayer(boost::shared_ptr<ModelInstance>character,Network::Player*p){
 Workspace*workspace=ServiceProvider::find<Workspace>(this);
 if(!workspace){std::string message("SpawnPlayer couldn't get the workspace");throw std::runtime_error(message);}
 if(spawners.empty()){
  workspace->moveToPoint(character.get(),G3D::Vector3(0.0f,100.0f,0.0f));
  return;
 }
 std::vector<SpawnLocation*>possibleLocations;
 for(std::list<SpawnLocation*>::const_iterator it=spawners.begin();it!=spawners.end();++it){
  if((*it)->neutral)possibleLocations.push_back(*it);
  else if(!p->getNeutral()&&p->getTeamColor()==(*it)->getTeamColor())possibleLocations.push_back(*it);
 }
 if(possibleLocations.empty()){
  workspace->moveToPoint(character.get(),G3D::Vector3(0.0f,100.0f,0.0f));
  return;
 }
 SpawnLocation*chosen=possibleLocations[rand()%possibleLocations.size()];
 G3D::Vector3 spawnPos=chosen->getCoordinateFrame().translation;
 int duration=chosen->forcefieldDuration;
 spawnPos.y+=7.0f;
 if(duration>0){
  boost::shared_ptr<ForceField>forcefield=Creatable<Instance>::create<ForceField>();
  forcefield->setParent(character.get());
  DebrisService*debris=ServiceProvider::find<DebrisService>(this);
  debris->addItem(forcefield,chosen->forcefieldDuration);
 }
 workspace->moveToPoint(character.get(),spawnPos);
}
typedef char native_spawn_list[sizeof(std::list<SpawnLocation*>)==28?1:-1];
typedef char native_spawn_vector[sizeof(std::vector<SpawnLocation*>)==24?1:-1];
typedef char native_spawn_owner[sizeof(boost::shared_ptr<ModelInstance>)==8?1:-1];
typedef char native_spawn_position[sizeof(G3D::Vector3)==12?1:-1];
typedef char native_spawn_frame[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char native_spawn_translation[offsetof(G3D::CoordinateFrame,translation)==36?1:-1];
typedef char native_spawn_locations[offsetof(SpawnerService,spawners)==0x130?1:-1];
typedef char native_spawn_player_team[offsetof(Network::Player,teamColor)==0x178?1:-1];
typedef char native_spawn_player_neutral[offsetof(Network::Player,neutral)==0x17c?1:-1];
typedef char native_spawn_team[offsetof(SpawnLocation,teamColor)==0x3e8?1:-1];
typedef char native_spawn_neutral[offsetof(SpawnLocation,neutral)==0x400?1:-1];
typedef char native_spawn_duration[offsetof(SpawnLocation,forcefieldDuration)==0x404?1:-1];
}
