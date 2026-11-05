// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// RunDragger layout and APIs: native tool/RunDragger.h; complete target is 642 bytes.
// Native G3D Array/Ray/CoordinateFrame and measured Workspace/World access paths.
// faceOverlapTest is a descriptive ABI label; no original symbol identity is claimed.
// The target-backed fallOffPart body lets MSVC prove the bool reference does not escape.
#include <new>
#include <stddef.h>
namespace G3D {
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Matrix3 {float elt[3][3];Matrix3(const Matrix3&);};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;CoordinateFrame(const CoordinateFrame&f):rotation(f.rotation),translation(f.translation){}~CoordinateFrame(){}};
struct Ray {Vector3 origin,direction;virtual ~Ray(){}};
struct System {static void alignedFree(void*);static void*alignedMalloc(size_t,size_t);};
template<class T>class Array {
 T*data;int num,numAllocated;
 bool inArray(const T*address){return address>=data&&address<data+num;}
    void realloc(int oldNum) {
         T* oldData = data;
         
         // The allocation is separate from the constructor invocation because we don't want 
         // to pay for the cost of constructors until the newly allocated
         // elements are actually revealed to the application.  They 
         // will be constructed in the resize() method.

         data = (T*)System::alignedMalloc(sizeof(T) * numAllocated, 16);

         // Call the copy constructors
         {const int N = (oldNum < numAllocated ? oldNum : numAllocated);
          const T* end = data + N;
          T* oldPtr = oldData;
          for (T* ptr = data; ptr < end; ++ptr, ++oldPtr) {

             // Use placement new to invoke the constructor at the location
             // that we determined.  Use the copy constructor to make the assignment.
             const T* constructed = new (ptr) T(*oldPtr);

             (void)constructed;

         }}

         // Call destructors on the old array (if there is no destructor, this will compile away)
         {const T* end = oldData + oldNum;
          for (T* ptr = oldData; ptr < end; ++ptr) {
              ptr->~T();
         }}


         System::alignedFree(oldData);
    }

public:
 typedef const T*ConstIterator;
 Array(){num=0;numAllocated=0;data=0;}
 ~Array(){for(int i=0;i<num;++i)(data+i)->~T();System::alignedFree(data);data=0;num=0;numAllocated=0;}
 ConstIterator end()const{return data+num;}
 ConstIterator find(const T&value)const{for(int i=0;i<num;++i)if(data[i]==value)return data+i;return end();}
    void resize(int n, bool shrinkIfNecessary) {
      int oldNum = num;
      num = n;

      // Call the destructors on newly hidden elements if there are any
      for (int i = num; i < oldNum; ++i) {
          (data + i)->~T();
      }

      // Once allocated, always maintain 10 elements or 32 bytes, whichever is higher.
      static const int minSize = (10 > 32 / sizeof(T) ? 10 : 32 / sizeof(T));

      if (num > numAllocated) {
          // Grow the underlying array

          if (numAllocated == 0) {
              // First allocation; grow to exactly the size requested to avoid wasting space.
              numAllocated = n;

              realloc(oldNum);
          } else {
         
              if (num < minSize) {
                  // Grow to at least the minimum size
                  numAllocated = minSize;

              } else {

                  // Increase the underlying size of the array.  Grow aggressively
                  // up to 64k, less aggressively up to 400k, and then grow relatively
                  // slowly (1.5x per resize) to avoid excessive space consumption.
                  //
                  // These numbers are tweaked according to performance tests.

                  float growFactor = 3.0;

                  size_t oldSizeBytes = numAllocated * sizeof(T);
                  if (oldSizeBytes > 400000) {
                      // Avoid bloat
                      growFactor = 1.5;
                  } else if (oldSizeBytes > 64000) {
                      // This is what std:: uses at all times
                      growFactor = 2.0;
                  }

                  numAllocated = (num - numAllocated) + (int)(numAllocated * growFactor);

                  if (numAllocated < minSize) {
                      numAllocated = minSize;
                  }
              }

              realloc(oldNum);
          }

      } else if ((num <= numAllocated / 3) && shrinkIfNecessary && (num > minSize)) {
          // Shrink the underlying array

          // Only copy over old elements that still remain after resizing
          // (destructors were called for others if we're shrinking)
          realloc((num < oldNum ? num : oldNum));

      }

      // Call the constructors on newly revealed elements.
      // Do not use parens because we don't want the intializer
      // invoked for POD types.
      for (int i = oldNum; i < num; ++i) {
          new (data + i) T;
      }
   }

 void append(const T&value){if(num<numAllocated){new(data+num)T(value);++num;}else if(inArray(&value)){T tmp=value;append(tmp);}else{resize(num+1,false);data[num-1]=value;}}
 void push(const T&value){append(value);}void push_back(const T&value){push(value);}
};
}
namespace RBX {
enum NormalId{NORM_X,NORM_Y,NORM_Z,NORM_X_NEG,NORM_Y_NEG,NORM_Z_NEG,NORM_UNDEFINED};
struct Face {G3D::Vector3 corners[4];};
bool __cdecl faceOverlapTest(const Face&,const Face&,float);
struct Primitive {Face getFaceInWorld(NormalId);const G3D::CoordinateFrame&getCoordinateFrame()const;};
struct ContactManager {bool intersectingOthers(Primitive*,float);};
struct World {char unobserved[0x84];ContactManager*contactManager;ContactManager&getContactManager(){return *contactManager;}};
struct Workspace {char unobserved[0x2e4];World*world;World*getWorld(){return world;}};
struct WeakPart {char unobserved[8];};
class RunDragger {
public:
 struct SnapInfo {Primitive*snap;NormalId surface;G3D::Vector3 hitWorld,lastDragSnap;void updateHitFromSurface(const G3D::Ray&);};
private:
 WeakPart dragPart,snapPart;Workspace*workspace;Primitive*drag;G3D::Vector3 dragPointLocal;SnapInfo snapInfo;G3D::Ray mouseRay;NormalId dragSurface;G3D::Vector3 dragHitLocal;
 SnapInfo createSnapSurface(Primitive*,G3D::Array<NormalId>*);bool moveDragPart();bool fallOffPart(bool&);bool rayHitsCloserPart();bool tooCloseToCamera();SnapInfo findSnap(const G3D::Array<Primitive*>&);void findNoSnapPosition(const G3D::CoordinateFrame&);void smartPtrHackPre();void smartPtrHackPost();
 bool notTried(Primitive*check,const G3D::Array<Primitive*>&tried){return check&&tried.find(check)==tried.end();}
 bool colliding(){return workspace->getWorld()->getContactManager().intersectingOthers(drag,0.01f);}
public:bool snap(const G3D::Ray&);
};
bool RunDragger::fallOffPart(bool&changed){
 G3D::Array<NormalId>tried;
 while(snapInfo.snap){
  Face snapFace=snapInfo.snap->getFaceInWorld(snapInfo.surface);
  Face dragFace=drag->getFaceInWorld(dragSurface);
  if(faceOverlapTest(snapFace,dragFace,-0.01f))break;
  tried.push_back(snapInfo.surface);
  snapInfo=createSnapSurface(snapInfo.snap,&tried);
  if(!snapInfo.snap)break;
  changed=moveDragPart();
 }
 return snapInfo.snap==0;
}
bool RunDragger::snap(const G3D::Ray&ray){
 smartPtrHackPre();mouseRay=ray;
 G3D::CoordinateFrame original=drag->getCoordinateFrame();
 G3D::Array<Primitive*>tried;
 if(snapInfo.snap)snapInfo.updateHitFromSurface(mouseRay);else snapInfo=findSnap(tried);
 while(snapInfo.snap){
  if(!notTried(snapInfo.snap,tried))break;
  tried.push_back(snapInfo.snap);
  bool moved=moveDragPart();
  if(fallOffPart(moved)||colliding()||rayHitsCloserPart()||tooCloseToCamera())snapInfo=findSnap(tried);
  else{smartPtrHackPost();return moved;}
 }
 findNoSnapPosition(original);smartPtrHackPost();return false;
}
}
typedef char array_extent[sizeof(G3D::Array<RBX::Primitive*>)==12?1:-1];
typedef char frame_extent[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char ray_extent[sizeof(G3D::Ray)==28?1:-1];
typedef char snap_extent[sizeof(RBX::RunDragger::SnapInfo)==32?1:-1];

typedef char world_contact_offset[offsetof(RBX::World,contactManager)==0x84?1:-1];
typedef char workspace_world_offset[offsetof(RBX::Workspace,world)==0x2e4?1:-1];
typedef char dragger_extent[sizeof(RBX::RunDragger)==0x70?1:-1];
