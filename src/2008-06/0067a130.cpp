// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// Complete VisualEngine destructor; native Ogre interfaces and target-observed fields.
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <stddef.h>
namespace boost {typedef long once_flag;void call_once(void(__cdecl*)(),once_flag&);}
namespace Ogre {
struct Resource {virtual ~Resource();};
template<class T>struct SharedPtr {
 T*pRep;unsigned*pUseCount;
 virtual ~SharedPtr(){release();}
 void release(){bool destroyThis=false;if(pUseCount){if(--(*pUseCount)==0)destroyThis=true;}if(destroyThis)destroy();}
 virtual void destroy(){delete pRep;delete pUseCount;}
 virtual void swap(SharedPtr&r){std::swap(pRep,r.pRep);std::swap(pUseCount,r.pUseCount);}
 T*operator->()const{return pRep;}bool isNull()const{return pRep==0;}
};
typedef SharedPtr<Resource>ResourcePtr;
struct DataStream;typedef SharedPtr<DataStream>DataStreamPtr;
struct ScriptLoader {
 virtual ~ScriptLoader();
 virtual const std::vector<std::string>&getScriptPatterns()const=0;
 virtual void parseScript(DataStreamPtr&,const std::string&)=0;
 virtual float getLoadingOrder()const=0;
};
struct ManualResourceLoader;
typedef std::map<std::string,std::string>NameValuePairList;
typedef unsigned long ResourceHandle;
struct ResourceManager:ScriptLoader {
 virtual ~ResourceManager();
 virtual ResourcePtr create(const std::string&,const std::string&,bool,ManualResourceLoader*,const NameValuePairList*);
 virtual std::pair<ResourcePtr,bool>createOrRetrieve(const std::string&,const std::string&,bool,ManualResourceLoader*,const NameValuePairList*);
 virtual void setMemoryBudget(size_t);virtual size_t getMemoryBudget()const;virtual size_t getMemoryUsage()const;
 virtual void unload(const std::string&);virtual void unload(ResourceHandle);
 virtual void unloadAll(bool);virtual void reloadAll(bool);
 virtual void unloadUnreferencedResources(bool);virtual void reloadUnreferencedResources(bool);
 virtual void remove(ResourcePtr&);virtual void remove(const std::string&);virtual void remove(ResourceHandle);
 virtual void removeAll();virtual ResourcePtr getByName(const std::string&);
};
struct MaterialManager:ResourceManager {__declspec(dllimport) static MaterialManager&getSingleton();};
struct TextureManager:ResourceManager {__declspec(dllimport) static TextureManager&getSingleton();};
struct IndexData;
struct SubMesh {bool useSharedVertices;int operationType;void*vertexData;IndexData*indexData;};
struct Mesh:Resource {
 __declspec(dllimport) unsigned short getNumSubMeshes()const;
 __declspec(dllimport) SubMesh*getSubMesh(unsigned short)const;
};
struct __declspec(dllimport) MeshPtr:SharedPtr<Mesh> {
 MeshPtr(const SharedPtr<Resource>&);virtual ~MeshPtr();
};
struct MeshManager:ResourceManager {__declspec(dllimport) static MeshManager&getSingleton();};
struct SceneManager;struct RenderTarget;
struct Root {
 __declspec(dllimport) void destroySceneManager(SceneManager*);
 __declspec(dllimport) void detachRenderTarget(RenderTarget*);
};
enum LogMessageLevel {LML_TRIVIAL=1,LML_NORMAL=2,LML_CRITICAL=3};
struct LogManager {
 __declspec(dllimport) static LogManager&getSingleton();
 __declspec(dllimport) void logMessage(const std::string&,LogMessageLevel=LML_NORMAL,bool=false);
};
struct StringConverter {
 __declspec(dllimport) static std::string toString(unsigned,unsigned short=0,char=' ',std::ios::fmtflags=std::ios::fmtflags(0));
 __declspec(dllimport) static std::string toString(int,unsigned short=0,char=' ',std::ios::fmtflags=std::ios::fmtflags(0));
};
struct RenderOwner {virtual ~RenderOwner();};
struct VisualEngine {
 virtual ~VisualEngine();
 SceneManager*sceneManager;void*unobserved08;RenderTarget*renderTarget;void*unobserved10;RenderOwner*renderOwner;
};
void __cdecl reportResourceUsage(ResourceManager&,const std::string&,std::vector<std::string>&);
void __cdecl reportResourceCounts(ResourceManager&,const std::string&);
struct RbxSubMesh;
struct MeshContext {std::map<RbxSubMesh*,std::string>names;};
struct SubMeshSphereRegistry {char unobserved[0x1c];unsigned count;unsigned size()const{return count;}};
extern Root*root;extern MeshContext*meshContext;extern boost::once_flag meshOnce;
extern SubMeshSphereRegistry*subMeshSpheres;void __cdecl initializeMeshContext();
VisualEngine::~VisualEngine(){
 if(root){
  if(sceneManager)root->destroySceneManager(sceneManager);
  if(renderTarget)root->detachRenderTarget(renderTarget);
  if(renderOwner)delete renderOwner;
  std::vector<std::string>textures,materials,meshes;
  reportResourceUsage(MaterialManager::getSingleton(),"Material",materials);
  reportResourceUsage(TextureManager::getSingleton(),"Texture",textures);
  // The target passes the same vector to its Material and Mesh reports.
  reportResourceUsage(MeshManager::getSingleton(),"Mesh",materials);
  reportResourceCounts(MaterialManager::getSingleton(),"matl");
  reportResourceCounts(TextureManager::getSingleton(),"tex");
  reportResourceCounts(MeshManager::getSingleton(),"mesh");
  boost::call_once(initializeMeshContext,meshOnce);
  MeshContext*context=meshContext;
  LogManager::getSingleton().logMessage("RBX sms c="+StringConverter::toString(context->names.size()),LML_NORMAL,false);
  if(context->names.size()){
   std::string remaining;
   for(std::map<RbxSubMesh*,std::string>::const_iterator it=context->names.begin();it!=context->names.end();++it)remaining+=" "+it->second;
   LogManager::getSingleton().logMessage("RBX sms remaining: "+remaining,LML_NORMAL,false);
  }
  MeshPtr mesh=MeshManager::getSingleton().getByName("rbxvb");
  if(!mesh.isNull()){
   int subMeshCount=mesh->getNumSubMeshes();int indexedCount=0;
   for(int i=0;i<subMeshCount;++i)if(mesh->getSubMesh(static_cast<unsigned short>(i))->indexData)++indexedCount;
   LogManager::getSingleton().logMessage("RBX sm c="+StringConverter::toString(indexedCount),LML_NORMAL,false);
  }
  if(subMeshSpheres)LogManager::getSingleton().logMessage("RBX sm2sph c="+StringConverter::toString(subMeshSpheres->size()),LML_NORMAL,false);
 }
}
}
typedef char visual_scene_offset[offsetof(Ogre::VisualEngine,sceneManager)==4?1:-1];
typedef char visual_target_offset[offsetof(Ogre::VisualEngine,renderTarget)==12?1:-1];
typedef char visual_owner_offset[offsetof(Ogre::VisualEngine,renderOwner)==20?1:-1];
typedef char submesh_index_offset[offsetof(Ogre::SubMesh,indexData)==12?1:-1];
typedef char resource_ptr_size[sizeof(Ogre::ResourcePtr)==12?1:-1];
typedef char mesh_ptr_size[sizeof(Ogre::MeshPtr)==12?1:-1];
typedef char registry_size[sizeof(Ogre::MeshContext)==32?1:-1];
