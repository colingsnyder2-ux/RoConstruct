// from server: 100% by king_originala
// from server: 93% by Espeon
#include <intrin.h>
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace Ogre {
struct Vector3 {float x,y,z; Vector3(float a,float b,float c):x(a),y(b),z(c){}};
struct Matrix4 {float m[4][4];const float* operator[](int row)const{return m[row];} Vector3 getTrans()const{_ReadWriteBarrier();return Vector3(m[0][3],m[1][3],m[2][3]);}};
struct RbxSubEntity {
 char pad[0xf0];
 Matrix4 transform;
 const Vector3& position()const;
};
const Vector3& RbxSubEntity::position()const{
 static const Vector3 translation(transform.getTrans());
 return translation;
}
}
