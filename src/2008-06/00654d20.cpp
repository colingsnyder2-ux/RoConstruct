// from server: 100% by coldek
// from server: 77% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Native ScoreHud board builder. Opaque receiver prefixes create no GUI/Instance objects or RTTI.
#include <string>
#include <vector>
#include <typeinfo>
#include <cstddef>
#include <intrin.h>
namespace boost {
class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};
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
public:shared_ptr():px(0),pn(){}
 T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}
 typedef T*shared_ptr::*unspecified_bool_type;
 operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
};
// The existing client instantiation at005018d0 is the genuine conversion boundary.
template<class Target,class Source>__declspec(noalias) Target lexical_cast(const Source&);
}
namespace RBX {
template<class T>class CopyOnWrite:public boost::noncopyable {boost::shared_ptr<T>object;
public:operator typename boost::shared_ptr<T>::unspecified_bool_type()const{return object;}
 const T&operator*()const{return *object.get();}const T*operator->()const{return object.get();}
};
class Instance;
typedef std::vector<boost::shared_ptr<Instance> >Instances;
class Instance {public:char unobserved00[0x108];CopyOnWrite<Instances>children;std::string name;
 size_t numChildren()const{return children?children->size():0;}
 Instance*getChild(size_t i){return (*children)[i].get();}
 const std::string&getName()const{return name;}
 Instance*findFirstChildByName(const std::string&)const;
};
namespace Reflection {
class DescribedBase;
template<class T>class TypedPropertyDescriptor {public:
 // Native RTTI-linked GetSet implementations prove these four actual methods.
 // Two predicate slots precede the value getter; there is no virtual destructor.
 class GetSet {public:
  virtual bool isReadOnly()const=0;
  virtual bool isWriteOnly()const=0;
  virtual T getValue(const DescribedBase*)const=0;
  virtual void setValue(DescribedBase*,const T&)const=0;
 };
};
}
// Actual pointer storage read at97d39c in IntValue's native descriptor.
extern Reflection::TypedPropertyDescriptor<int>::GetSet*nativeIntValueGetSet;
// Native Instance's actual DescribedBase subobject is at+14; preserve the null conversion.
const Reflection::DescribedBase*observedDescribedBase(const Instance*p){return p?reinterpret_cast<const Reflection::DescribedBase*>(reinterpret_cast<const char*>(p)+0x14):0;}
extern const type_info nativeInstanceType,nativeIntValueType;
extern "C" void*__cdecl __RTDynamicCast(void*,long,void*,void*,int);
namespace Network {class Players {public:__declspec(noalias) boost::shared_ptr<const Instances>getPlayers();};}
class BoardData {public:std::vector<std::vector<std::string> >data;std::vector<std::string>fields;
 void SetSize(int,int);
 void AddField(std::string,int);
};
class ScoreHud {public:char unobserved00[0x150];Network::Players*players;void BuildBoardData(BoardData&);};
typedef char native_owner_size[sizeof(boost::shared_ptr<const Instances>)==8?1:-1];
typedef char native_counted_base_size[sizeof(boost::detail::sp_counted_base)==12?1:-1];
typedef char native_cow_size[sizeof(CopyOnWrite<Instances>)==8?1:-1];
typedef char native_board_size[sizeof(BoardData)==48?1:-1];
typedef char native_instance_children[offsetof(Instance,children)==0x108?1:-1];
typedef char native_instance_name[offsetof(Instance,name)==0x110?1:-1];
typedef char native_hud_players[offsetof(ScoreHud,players)==0x150?1:-1];
void ScoreHud::BuildBoardData(BoardData&data){
 if(!players)return;
 boost::shared_ptr<const Instances>playerList=players->getPlayers();
 for(size_t i=0;i<playerList->size();++i){
  Instance*player=playerList->at(i).get();
  Instance*stats=player->findFirstChildByName("leaderstats");
  if(stats){
   data.SetSize((int)playerList->size(),(int)stats->numChildren()+1);
   data.AddField("Player",0);
   for(size_t j=0;j<stats->numChildren();++j){
    data.AddField(stats->getChild(j)->getName(),(int)j+1);
   }
   data.data[i][0]=player->getName();
   for(size_t j=0;j<stats->numChildren();++j){
    __RTDynamicCast(stats->getChild(j),0,(void*)&nativeInstanceType,(void*)&nativeIntValueType,0);
    int statValue=nativeIntValueGetSet->getValue(observedDescribedBase(stats->getChild(j)));
    data.data[i][j+1]=boost::lexical_cast<std::string>(statValue);
   }
  }else{
   data.SetSize((int)playerList->size(),1);
   data.AddField("Player List",0);
   data.data[i][0]=player->getName();
  }
 }
 for(size_t i=0;i<playerList->size();++i){
  if(data.data[i][0].size()>16)data.data[i][0].resize(16);
 }
}
}

namespace RBX {typedef char native_getset_size[sizeof(Reflection::TypedPropertyDescriptor<int>::GetSet)==4?1:-1];}
