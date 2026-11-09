// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_sceneinsertassignment_fbd18b7782bbd42d.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Object;
struct Matrix {float elements[16];};
typedef std::map<const void*,Matrix*> Map;
struct RbxSceneNode {char padding[0x228];Map map;void method(Object*,const Matrix&);};
void RbxSceneNode::method(Object* key,const Matrix& matrix){
 Map::iterator it=map.find(key);
 if(it==map.end()){std::pair<Map::iterator,bool> result;result=map.insert(std::make_pair(key,new Matrix));it=result.first;}
 *it->second=matrix;
}
