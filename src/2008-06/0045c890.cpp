// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <intrin.h>
#include <math.h>
#include <stddef.h>
struct CriticalSection {char opaque[24];};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection*);
extern CriticalSection renderTimingMutex;
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
template<class T>struct shared_ptr {T*px;detail::shared_count pn;shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}template<class U>shared_ptr(const shared_ptr<U>&r):px(r.px),pn(r.pn){}T*get()const{return px;}T*operator->()const{return px;}};
}
namespace G3D {
struct Vector3 {
 float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(const Vector3&r):x(r.x),y(r.y),z(r.z){}
 Vector3 operator-(const Vector3&)const;
 float squaredMagnitude()const{return x*x+y*y+z*z;}float magnitude()const{return(float)sqrt(squaredMagnitude());}
};
struct Matrix3 {float elt[3][3];};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;};
struct GCamera;
inline const float&min(const float&a,const float&b){return a<b?a:b;}
inline const float&max(const float&a,const float&b){return a>b?a:b;}
}
namespace Ogre {
struct RenderSystemCapabilities {char opaque[8];unsigned flags;};
struct RenderSystem {char opaque[0x64];RenderSystemCapabilities*capabilities;const RenderSystemCapabilities*getCapabilities()const{return capabilities;}};
struct Root {__declspec(dllimport) RenderSystem*getRenderSystem();};
}
extern Ogre::Root*ogreRoot;
namespace RBX {
struct Instance;struct RenderStats;struct Extents;
struct Camera {char opaque[0x1a4];G3D::CoordinateFrame cameraFocus;G3D::CoordinateFrame getCameraCoordinateFrame()const;const G3D::CoordinateFrame&getCameraFocus()const{return cameraFocus;}};
struct ICameraOwner {
 virtual ~ICameraOwner();virtual Camera*getCamera()const=0;virtual const G3D::GCamera&getGCamera()const=0;virtual void cameraMoved()=0;virtual Extents computeCameraOwnerExtents()=0;
};
struct WorkspacePrimary {virtual ~WorkspacePrimary();char opaque[0x288-4];};
struct WorkspaceModel:WorkspacePrimary,ICameraOwner {};
struct DataModel {char opaque[0x204];WorkspaceModel*workspace;WorkspaceModel*getWorkspace()const{return workspace;}struct Lock {char opaque[12];Lock(boost::shared_ptr<const DataModel>);~Lock();};};
struct ViewBase {
 virtual ~ViewBase();virtual void render(void*)=0;virtual float getShadingQuality()const=0;virtual float getMeshDetail()const=0;virtual void updateSettings(float,float,bool,float)=0;
 virtual void suppressSkybox()=0;virtual Instance*getWorkspace()=0;virtual RenderStats&getRenderStats()=0;virtual void onWorkspaceDescendentAdded(boost::shared_ptr<Instance>)=0;virtual void updateLighting()=0;virtual void invalidateLighting(bool)=0;
 static bool&getShadowsEnabled(){static bool shadows=false;return shadows;}
};
struct RenderTuning {char opaque[0x144];float minQuality,maxQuality,minMesh,maxMesh;static RenderTuning&singleton();float getMinQuality()const{return minQuality;}float getMaxQuality()const{return maxQuality;}float getMinMesh()const{return minMesh;}float getMaxMesh()const{return maxMesh;}};
}
struct CRobloxWnd {
 char opaque0[0x5c];int mode;char opaque60[0x70-0x60];boost::shared_ptr<RBX::DataModel>dataModel;char opaque78[0x90-0x78];double pendingElapsed;char opaque98[0xb0-0x98];RBX::ViewBase*view;
 void updateThrottle();
};
typedef char VerifiedExtents[(sizeof(G3D::CoordinateFrame)==48&&sizeof(RBX::DataModel::Lock)==12&&offsetof(CRobloxWnd,dataModel)==0x70&&offsetof(CRobloxWnd,pendingElapsed)==0x90&&offsetof(CRobloxWnd,view)==0xb0&&offsetof(RBX::Camera,cameraFocus)+offsetof(G3D::CoordinateFrame,translation)==0x1c8)?1:-1];
void CRobloxWnd::updateThrottle(){
 EnterCriticalSection(&renderTimingMutex);
 if(pendingElapsed==666.0){LeaveCriticalSection(&renderTimingMutex);return;}
 double elapsed=pendingElapsed;pendingElapsed=666.0;
 LeaveCriticalSection(&renderTimingMutex);
 RBX::ViewBase*presentView=view;
 _ReadWriteBarrier();
 if(!presentView||!dataModel.get())return;
 RBX::DataModel::Lock lock(dataModel);
 float quality=view->getShadingQuality();float mesh=view->getMeshDetail();
 if(elapsed<-.01){quality*=.8f;mesh*=.8f;}
 else if(elapsed>.002){quality=quality*1.05f+1;mesh=mesh*1.05f+1;}
 quality=G3D::min(RBX::RenderTuning::singleton().getMaxQuality(),quality);
 quality=G3D::max(RBX::RenderTuning::singleton().getMinQuality(),quality);
 mesh=G3D::min(RBX::RenderTuning::singleton().getMaxMesh(),mesh);
 mesh=G3D::max(RBX::RenderTuning::singleton().getMinMesh(),mesh);
 if(dataModel->getWorkspace()&&dataModel->getWorkspace()->getCamera()){
  G3D::CoordinateFrame cameraFrame=dataModel->getWorkspace()->getCamera()->getCameraCoordinateFrame();
  float distance=(cameraFrame.translation-dataModel->getWorkspace()->getCamera()->getCameraFocus().translation).magnitude();
  if((mode==4||mode==3)&&ogreRoot&&ogreRoot->getRenderSystem()&&!(ogreRoot->getRenderSystem()->getCapabilities()->flags&0x200))RBX::ViewBase::getShadowsEnabled()=false;
  view->updateSettings(quality,mesh,RBX::ViewBase::getShadowsEnabled(),distance);
 }
}
