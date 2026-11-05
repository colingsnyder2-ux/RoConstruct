// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_contactvectorcompare_7e2ed5d92f30622a.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector3.h>
#pragma float_control(precise,off)
using G3D::Vector3;
struct BlockBlockContact {char pad[4];int count;};
void __cdecl move(BlockBlockContact*,Vector3&);
bool __cdecl test(BlockBlockContact*,Vector3&);
void __cdecl adjust(BlockBlockContact*,Vector3&,Vector3&);
Vector3 __cdecl calculate(BlockBlockContact* self,Vector3& value,Vector3& context){
 Vector3 result;
 if(self->count==0)return Vector3::zero();
 if(value!=Vector3::zero()){move(self,value);result+=value;}
 if(test(self,context))adjust(self,result,context);
 return result;
}
