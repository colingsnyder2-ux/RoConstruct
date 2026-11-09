// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_king_originala_physics_75c27201d70d3a0f.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <vector>
struct Object {void func_00598c90();};
typedef boost::shared_ptr<Object> Shared;
typedef std::vector<boost::weak_ptr<Object> > Container;
bool __cdecl testObject(Shared value);
void __cdecl process(Container* container) {
 for(unsigned int i=0;i<container->size();++i) {
  Shared value=(*container)[i].lock();
  Object* object=value.get();
  if(testObject(value))object->func_00598c90();
 }
}
typedef char weak_size[sizeof(boost::weak_ptr<Object>)==8?1:-1];
typedef char vector_size[sizeof(Container)==24?1:-1];
