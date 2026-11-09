// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_king_originala_physics_e24ee4e3b4be38d6.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <vector>
#include <G3D/Array.h>
struct Primitive;
// Borrowed PartInstance receiver; native LEA edi+228 and sibling construction
// establish the embedded Primitive address. No owner is constructed here.
struct Object {Primitive* getPrimitive(){return reinterpret_cast<Primitive*>(reinterpret_cast<char*>(this)+0x228);}};
typedef boost::shared_ptr<Object> Shared;
typedef std::vector<boost::weak_ptr<Object> > Collection;
typedef G3D::Array<Primitive*> Output;
bool __cdecl accepted(Shared);
void* __cdecl getResult(Object*);
void* __cdecl reconstruct(Collection* collection,Output* output) {
 void* result=0;
 for(unsigned int i=0;i<collection->size();++i) {
  Shared item=(*collection)[i].lock();
  Object* object=item.get();
  if(accepted(item)) {
   Primitive* value=object->getPrimitive();
   output->append(value);
   if(!result)result=getResult(object);
  }
 }
 return result;
}
typedef char weak_size[sizeof(boost::weak_ptr<Object>)==8?1:-1];
typedef char vector_size[sizeof(Collection)==24?1:-1];
