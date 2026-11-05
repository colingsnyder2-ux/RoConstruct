// from server: 100% by king_originala
// from server: 98% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_view_g3d_sdk_7c34f00dda825ea8.cpp

// Candidate translation unit (score above; library headers required).
// from server: 97% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <memory>
#include <map>
#include <string.h>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}T*get()const{return px;}T*operator->()const{return px;}};
namespace signals {
struct connection {unsigned long opaque[4];connection(const connection&);~connection();};
struct scoped_connection:connection {bool released;~scoped_connection();scoped_connection&operator=(const connection&);};
}
}
namespace G3D {
template<class T>class ReferenceCountedPointer {public:T*pointer;ReferenceCountedPointer():pointer(0){}~ReferenceCountedPointer();};
class Texture;class Sky;class LightingParameters;class Color3;
template<class Key,class Value>class Table {public:
 int count;void*bucket;int numBuckets;
 virtual ~Table(){freeMemory();}
 void freeMemory();
};
class TextureManager {public:
 class TextureArgs;
 Table<TextureArgs,ReferenceCountedPointer<Texture> >cache;
 unsigned size,sizeHint;
 TextureManager(unsigned);
};
}
namespace RBX {
struct Instance;struct DataModel;struct RenderStats;
namespace RenderBase {
struct RenderSceneBase {
 virtual ~RenderSceneBase();char opaque[0x268-4];
 virtual void presetLighting(G3D::ReferenceCountedPointer<G3D::Sky>,G3D::LightingParameters,G3D::Color3,G3D::Color3);
 virtual void setThrottle(float,float,bool,float);
};
struct Chunk;
class SceneManager {public:
 RenderSceneBase*renderScene;
 virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>&,bool)=0;
 virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>&)=0;
 virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>&)=0;
 virtual void clear()=0;
 virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>&,bool)=0;
 virtual void prerender(double)=0;
 virtual ~SceneManager(){}
 SceneManager(RenderSceneBase*s):renderScene(s){}
};
class SimpleSceneManager:public SceneManager {public:
 SimpleSceneManager(RenderSceneBase*s):SceneManager(s){}
 virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>&,bool);
 virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>&);
 virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>&);
 virtual void clear();virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>&,bool);virtual void prerender(double);
};
}
namespace Render {
struct Model;
struct RenderScene:RenderBase::RenderSceneBase {char opaque[0x500-0x268];RenderScene();virtual ~RenderScene();};
}
namespace RenderBase {
struct AggregatingSceneManager:SceneManager {
 char opaque[0x68-8];AggregatingSceneManager(RenderBase::RenderSceneBase*);virtual ~AggregatingSceneManager();
 virtual void invalidateModel(const G3D::ReferenceCountedPointer<RenderBase::Chunk>&,bool);
 virtual void addModel(const G3D::ReferenceCountedPointer<RenderBase::Chunk>&);virtual void removeModel(const G3D::ReferenceCountedPointer<RenderBase::Chunk>&);
 virtual void clear();virtual void setSleeping(const G3D::ReferenceCountedPointer<RenderBase::Chunk>&,bool);virtual void prerender(double);
};
}
namespace Reflection {struct SignalSource;}
struct BindInstance;struct Lighting;
struct Instance {char opaque[0x14];void visitDescendents(BindInstance);};
struct DataModel {char opaque[0x204];Instance*workspace;Lighting*findLighting();};
struct Lighting:Instance {};

namespace ViewNew {class ViewG3D;}
struct BindBool;struct BindInstance;
namespace SlotDetail {
class X;
union FunctionBuffer {void*obj_ptr;const void*const_obj_ptr;void(*func_ptr)();struct BoundMember {void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;char data;};
struct Function {void*vtable;FunctionBuffer functor;};
struct SlotBase {boost::shared_ptr<void>data;};
}
struct SlotBool:SlotDetail::SlotBase {SlotDetail::Function slot_function;template<class F>SlotBool(const F&);~SlotBool();};
struct SlotInstance:SlotDetail::SlotBase {SlotDetail::Function slot_function;template<class F>SlotInstance(const F&);~SlotInstance();};
typedef char SlotExtent[(sizeof(SlotBool)==40&&sizeof(SlotInstance)==40)?1:-1];
struct BoolSignalDescriptor {boost::signals::connection connect(Reflection::SignalSource*,const SlotBool&,int);};
struct InstanceSignalDescriptor {boost::signals::connection connect(Reflection::SignalSource*,const SlotInstance&,int);};
extern BoolSignalDescriptor lightingChanged;
extern InstanceSignalDescriptor descendantAdded;
inline Reflection::SignalSource*signalSource(Instance*p){return p?reinterpret_cast<Reflection::SignalSource*>(reinterpret_cast<char*>(p)+0x14):0;}

struct MaterialFactory {char opaque[16];MaterialFactory(G3D::TextureManager*);~MaterialFactory();};
class ViewBase {public:
 virtual ~ViewBase();
 std::auto_ptr<RenderBase::SceneManager>sceneManager;
 std::auto_ptr<RenderBase::RenderSceneBase>renderLibScene;
 std::auto_ptr<G3D::TextureManager>textureManager;
 std::auto_ptr<MaterialFactory>materialFactory;
 boost::shared_ptr<DataModel>dataModel;
 boost::signals::scoped_connection lightingConnection,workspaceConnection;
 bool baseFlag;char padding[3];
 ViewBase(boost::shared_ptr<DataModel>);
 virtual void render(void*)=0;
 virtual float getShadingQuality()const=0;virtual float getMeshDetail()const=0;
 virtual void updateSettings(float,float,bool,float)=0;virtual void suppressSkybox()=0;
 virtual Instance*getWorkspace()=0;virtual RenderStats&getRenderStats()=0;
 virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance>)=0;
 virtual void updateLighting()=0;virtual void invalidateLighting(bool)=0;
};
namespace ViewNew {
class ViewG3D:public ViewBase {public:
 G3D::ReferenceCountedPointer<G3D::Sky>sky;std::map<Instance*,Render::Model*>models;
 ViewG3D(boost::shared_ptr<DataModel>);
 virtual ~ViewG3D();virtual void render(void*);
 virtual float getShadingQuality()const;virtual float getMeshDetail()const;
 virtual void updateSettings(float,float,bool,float);virtual void suppressSkybox();
 virtual Instance*getWorkspace();virtual RenderStats&getRenderStats();
 virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance>);virtual void updateLighting();virtual void invalidateLighting(bool);
};
}
struct BindBool {typedef void(ViewNew::ViewG3D::*Method)(bool);Method method;ViewNew::ViewG3D*owner;BindBool(Method m,ViewNew::ViewG3D*p):method(m),owner(p){}};
struct BindInstance {typedef void(ViewNew::ViewG3D::*Method)(boost::shared_ptr<Instance>);Method method;ViewNew::ViewG3D*owner;BindInstance(Method m,ViewNew::ViewG3D*p):method(m),owner(p){}};
namespace ViewNew {
ViewG3D::ViewG3D(boost::shared_ptr<DataModel>dm):ViewBase(dm),sky(),models(){
 renderLibScene.reset(new Render::RenderScene);
 textureManager.reset(new G3D::TextureManager(0xa00000));
 sceneManager.reset(new RenderBase::AggregatingSceneManager(renderLibScene.get()));
 materialFactory.reset(new MaterialFactory(textureManager.get()));
 renderLibScene->setThrottle(0.f,0.f,false,0.f);
 Lighting*lighting=dm.get()?dm->findLighting():0;
 lightingConnection=lightingChanged.connect(signalSource(lighting),BindBool(&ViewG3D::invalidateLighting,this),10);
 {Instance* workspace=dm->workspace;_ReadWriteBarrier();workspace->visitDescendents(BindInstance(&ViewG3D::onWorkspaceDescendentAdded,this));}
 workspaceConnection=descendantAdded.connect(signalSource(dm->workspace),BindInstance(&ViewG3D::onWorkspaceDescendentAdded,this),10);
}
}
}
