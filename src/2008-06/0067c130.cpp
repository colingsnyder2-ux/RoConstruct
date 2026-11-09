// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native Ogre declarations plus target-observed RbxSubMesh and MeshContext layout.
#include <string>
#include <vector>
#include <map>
#include <stddef.h>
#include <exception>
namespace boost {
typedef long once_flag;void call_once(void(__cdecl*)(),once_flag&);
class thread_exception:public std::exception {int m_sys_err;protected:thread_exception();thread_exception(int);public:~thread_exception()throw();};
class lock_error:public thread_exception {public:lock_error();lock_error(int);~lock_error()throw();virtual const char*what()const throw();};
struct recursive_mutex {
 void*m_mutex;bool m_critical_section;unsigned m_count;void do_lock();void do_unlock();
 struct scoped_lock {
  recursive_mutex&m_mutex;bool m_locked;
  explicit scoped_lock(recursive_mutex&m):m_mutex(m),m_locked(false){lock();}
  ~scoped_lock(){if(m_locked)unlock();}
  void lock(){if(m_locked)throw lock_error();m_mutex.do_lock();m_locked=true;}
  void unlock(){if(!m_locked)throw lock_error();m_mutex.do_unlock();m_locked=false;}
 };
};
}
namespace Ogre {
struct Vector3 {
 float x,y,z;
 Vector3(){}Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 __declspec(dllimport) float length()const;
};
struct AxisAlignedBox {
 Vector3 minimum,maximum;unsigned extent;void*corners;
 AxisAlignedBox(float ax,float ay,float az,float bx,float by,float bz):corners(0){setExtents(ax,ay,az,bx,by,bz);}
 void setExtents(float ax,float ay,float az,float bx,float by,float bz){extent=1;minimum.x=ax;minimum.y=ay;minimum.z=az;maximum.x=bx;maximum.y=by;maximum.z=bz;}
 __declspec(dllimport) AxisAlignedBox&operator=(const AxisAlignedBox&);
 __declspec(dllimport) Vector3 getHalfSize()const;
 __declspec(dllimport) ~AxisAlignedBox()throw();
};
struct HardwareBuffer {
 enum Usage {HBU_STATIC=1,HBU_DYNAMIC=2,HBU_WRITE_ONLY=4,HBU_DISCARDABLE=8,HBU_STATIC_WRITE_ONLY=5,HBU_DYNAMIC_WRITE_ONLY=6,HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE=14};
 enum LockOptions {HBL_NORMAL,HBL_DISCARD,HBL_READ_ONLY,HBL_NO_OVERWRITE};
 virtual void*lockImpl(size_t,size_t,LockOptions)=0;
 virtual void unlockImpl()=0;
 virtual ~HardwareBuffer();
 virtual void*lock(size_t,size_t,LockOptions);
 virtual void unlock();
 virtual void readData(size_t,size_t,void*)=0;
 virtual void writeData(size_t,size_t,const void*,bool)=0;
 size_t mSizeInBytes;
 size_t getSizeInBytes()const{return mSizeInBytes;}
};
struct HardwareIndexBuffer:HardwareBuffer {enum IndexType {IT_16BIT,IT_32BIT};};
template<class T>struct SharedPtr {
 virtual ~SharedPtr();virtual void destroy();virtual void swap(SharedPtr&);
 T*pRep;unsigned*pUseCount;
 T*operator->()const{return pRep;}
};
struct __declspec(dllimport) HardwareIndexBufferSharedPtr:SharedPtr<HardwareIndexBuffer> {
 ~HardwareIndexBufferSharedPtr();
 HardwareIndexBufferSharedPtr&operator=(const HardwareIndexBufferSharedPtr&);
};
struct VertexDeclaration;struct VertexBufferBinding;struct HardwareVertexBufferSharedPtr;
struct HardwareBufferManager {
 virtual void destroyAllDeclarations();virtual void destroyAllBindings();
 virtual VertexDeclaration*createVertexDeclarationImpl();virtual void destroyVertexDeclarationImpl(VertexDeclaration*);
 virtual VertexBufferBinding*createVertexBufferBindingImpl();virtual void destroyVertexBufferBindingImpl(VertexBufferBinding*);
 virtual ~HardwareBufferManager();
 virtual HardwareVertexBufferSharedPtr createVertexBuffer(size_t,size_t,HardwareBuffer::Usage,bool)=0;
 virtual HardwareIndexBufferSharedPtr createIndexBuffer(HardwareIndexBuffer::IndexType,size_t,HardwareBuffer::Usage,bool)=0;
 __declspec(dllimport) static HardwareBufferManager&getSingleton();
};
struct IndexData {HardwareIndexBufferSharedPtr indexBuffer;size_t indexStart,indexCount;};
struct VertexData;struct Mesh;
struct SubMesh {
 bool useSharedVertices;int operationType;VertexData*vertexData;IndexData*indexData;
 std::vector<unsigned short>blendIndexToBoneIndexMap;
 std::vector<IndexData*>mLodFaceList;
 std::vector<Vector3>extremityPoints;
 Mesh*parent;
 char unobserved[0xc4-0x5c];
 __declspec(dllimport) SubMesh();__declspec(dllimport) ~SubMesh();
};
struct RbxSubMesh:SubMesh {bool nativeFlag;unsigned nativeWord;AxisAlignedBox bounds;float radius;RbxSubMesh();};
struct StringConverter {__declspec(dllimport) static std::string toString(int,unsigned short=0,char=' ',std::ios::fmtflags=std::ios::fmtflags(0));};
enum LogMessageLevel {LML_TRIVIAL=1,LML_NORMAL=2,LML_CRITICAL=3};
struct LogManager {__declspec(dllimport) static LogManager&getSingleton();__declspec(dllimport) void logMessage(const std::string&,LogMessageLevel=LML_NORMAL,bool=false);};
struct GeometryBuilder {
 VertexData*createVertexData(const float*,unsigned,const float*,const float*,const float*);
 RbxSubMesh*createIndexed(const float*,unsigned,const float*,const float*,const float*,const unsigned short*,const unsigned*,unsigned,Vector3*,Vector3*);
};
}
struct MeshContext {std::map<Ogre::RbxSubMesh*,std::string>names;int counter;boost::recursive_mutex mutex;};
extern MeshContext*meshContext;extern boost::once_flag meshOnce;void __cdecl initializeMeshContext();
Ogre::RbxSubMesh*Ogre::GeometryBuilder::createIndexed(const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const unsigned short*indices16,const unsigned*indices32,unsigned triangleCount,Vector3*minimum,Vector3*maximum){
 boost::call_once(initializeMeshContext,meshOnce);
 MeshContext*context=meshContext;
 boost::recursive_mutex::scoped_lock lock(context->mutex);
 RbxSubMesh*result=new RbxSubMesh;
 result->parent=0;
 result->vertexData=createVertexData(vertices,vertexCount,normals,colours,texCoords);
 result->useSharedVertices=false;
 unsigned indexCount=3*triangleCount;
 HardwareIndexBufferSharedPtr buffer=HardwareBufferManager::getSingleton().createIndexBuffer(indices16?HardwareIndexBuffer::IT_16BIT:HardwareIndexBuffer::IT_32BIT,indexCount,HardwareBuffer::HBU_STATIC_WRITE_ONLY,false);
 buffer->writeData(0,buffer->getSizeInBytes(),indices16?static_cast<const void*>(indices16):indices32,true);
 result->indexData->indexBuffer=buffer;
 result->indexData->indexCount=indexCount;
 result->indexData->indexStart=0;
 {
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  *minimum=low;*maximum=high;
  AxisAlignedBox bounds(low.x,low.y,low.z,high.x,high.y,high.z);
  result->bounds=bounds;
  result->radius=bounds.getHalfSize().length();
 }
 std::string name="sms"+StringConverter::toString(context->counter++);
 context->names[result]=name;
 LogManager::getSingleton().logMessage("RBX cr "+name,LML_NORMAL,false);
 return result;
}
typedef char mesh_size[sizeof(Ogre::RbxSubMesh)==0xf0?1:-1];
typedef char parent_offset[offsetof(Ogre::SubMesh,parent)==0x58?1:-1];
typedef char bounds_offset[offsetof(Ogre::RbxSubMesh,bounds)==0xcc?1:-1];
typedef char radius_offset[offsetof(Ogre::RbxSubMesh,radius)==0xec?1:-1];
typedef char index_size[sizeof(Ogre::IndexData)==0x14?1:-1];
typedef char context_size[sizeof(MeshContext)==0x30?1:-1];
typedef char mutex_offset[offsetof(MeshContext,mutex)==0x24?1:-1];
