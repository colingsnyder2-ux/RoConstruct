// from server: 100% by coldek
// from server: 95% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native Ogre DLL exports/vtable establish StringInterface/Resource load slot34 and MeshPtr12.
// Mesh allocation, bounds and ownership preserve the full target behavior.
#include <string>
#include <map>
#include <math.h>
#include <stddef.h>
#include <exception>
namespace boost {
typedef long once_flag;void call_once(void(__cdecl*)(),once_flag&);
class thread_exception:public std::exception {int m_sys_err;protected:thread_exception();thread_exception(int);public:~thread_exception()throw();};
class lock_error:public thread_exception {public:lock_error();lock_error(int);~lock_error()throw();virtual const char*what()const throw();};
struct mutex {
 void*m_mutex;bool m_critical_section;void do_lock();void do_unlock();
 struct scoped_lock {
  mutex&m_mutex;bool m_locked;
  explicit scoped_lock(mutex&m):m_mutex(m),m_locked(false){lock();}
  ~scoped_lock(){if(m_locked)unlock();}
  void lock(){if(m_locked)throw lock_error();m_mutex.do_lock();m_locked=true;}
  void unlock(){if(!m_locked)throw lock_error();m_mutex.do_unlock();m_locked=false;}
 };
};
}
struct MeshContext {char unused[0x24];boost::mutex mutex;};
extern MeshContext*meshContext;extern boost::once_flag meshOnce;
void __cdecl initializeMeshContext();
namespace Ogre {
struct Math {static inline float Sqrt(float value){return static_cast<float>(sqrt(value));}};
struct Vector3 {
 float x,y,z;
 Vector3(){}Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3 operator-(const Vector3&v)const{Vector3 result;result.z=z-v.z;result.y=y-v.y;result.x=x-v.x;return result;}
 float length()const{float xx=x*x;return Math::Sqrt((xx+y*y)+z*z);}
 float squaredLength()const{float xx=x*x;return (xx+y*y)+z*z;}
};
struct AxisAlignedBox {
 Vector3 minimum,maximum;unsigned extent;void*corners;
 AxisAlignedBox(float ax,float ay,float az,float bx,float by,float bz):corners(0){setExtents(ax,ay,az,bx,by,bz);}
 void setExtents(float ax,float ay,float az,float bx,float by,float bz){extent=1;minimum.x=ax;minimum.y=ay;minimum.z=az;maximum.x=bx;maximum.y=by;maximum.z=bz;}
 __declspec(dllimport) ~AxisAlignedBox()throw();
};
typedef std::map<std::string,std::string>NameValuePairList;
struct StringInterface {
 virtual ~StringInterface();
 virtual bool setParameter(const std::string&,const std::string&);
 virtual void setParameterList(const NameValuePairList&);
 virtual std::string getParameter(const std::string&)const;
 virtual void copyParametersTo(StringInterface*)const;
};
struct Resource:StringInterface {
 virtual ~Resource();
 virtual void preLoadImpl();virtual void postLoadImpl();virtual void preUnloadImpl();virtual void postUnloadImpl();
 virtual void loadImpl()=0;virtual void unloadImpl()=0;virtual unsigned calculateSize()const=0;
 virtual void queueFireBackgroundLoadingComplete();virtual void load(bool);virtual void reload();virtual void unload();virtual void touch();
};
struct Mesh:Resource {
 __declspec(dllimport) void _setBounds(const AxisAlignedBox&,bool);
 __declspec(dllimport) void _setBoundingSphereRadius(float);
};
struct __declspec(dllimport) MeshPtr {
 virtual ~MeshPtr()throw();virtual void destroy();virtual void swap(MeshPtr&);
 Mesh*pointer;unsigned*useCount;
 MeshPtr(const MeshPtr&);Mesh*operator->()const{return pointer;}
};
struct ManualResourceLoader;
struct MeshManager {
 __declspec(dllimport) static MeshManager&getSingleton();
 __declspec(dllimport) MeshPtr createManual(const std::string&,const std::string&,ManualResourceLoader*);
};
struct GeometryBuilder {
 void update(MeshPtr&,const float*,unsigned,const float*,const float*,const float*,const Vector3*,const Vector3*);
 MeshPtr create(const char*,const char*,const float*,unsigned,const float*,const float*,const float*,const Vector3*,const Vector3*);
};
MeshPtr GeometryBuilder::create(const char*name,const char*group,const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const Vector3*minimum,const Vector3*maximum){
 boost::call_once(initializeMeshContext,meshOnce);
 boost::mutex::scoped_lock lock(meshContext->mutex);
 MeshPtr mesh=MeshManager::getSingleton().createManual(name,group,0);
 update(mesh,vertices,vertexCount,normals,colours,texCoords,minimum,maximum);
 float radius;
 if(minimum&&maximum){
  mesh->_setBounds(AxisAlignedBox(minimum->x,minimum->y,minimum->z,maximum->x,maximum->y,maximum->z),true);
  double r=sqrt(static_cast<double>((*maximum-*minimum).squaredLength()));
  radius=static_cast<float>(r);
 }else{
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  mesh->_setBounds(AxisAlignedBox(low.x,low.y,low.z,high.x,high.y,high.z),true);
  radius=(high-low).length();
 }
 mesh->_setBoundingSphereRadius(radius*0.5f);
 mesh->load(false);
 return mesh;
}
}
typedef char mesh_ptr_size[sizeof(Ogre::MeshPtr)==12?1:-1];
typedef char mesh_payload[offsetof(Ogre::MeshPtr,pointer)==4?1:-1];
typedef char bounds_size[sizeof(Ogre::AxisAlignedBox)==32?1:-1];
typedef char mutex_offset[offsetof(MeshContext,mutex)==0x24?1:-1];
