// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_g3dorientationfixed_70aa98a5f9c4f4ae.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
#pragma float_control(precise,off)
extern const float tolerance;
using G3D::Vector3;using G3D::CoordinateFrame;
template<int Padding> struct Orienter{char pad[Padding];CoordinateFrame frame;void apply(const CoordinateFrame&);void back(const Vector3&);void up(const Vector3&);void right(const Vector3&);};
template<int P> void Orienter<P>::back(const Vector3& direction){CoordinateFrame result(frame);Vector3 oldRight=result.rotation.getColumn(0);Vector3 oldUp=result.rotation.getColumn(1);Vector3 back=-direction.unit();Vector3 right=oldUp.cross(back);right.unitize(tolerance);Vector3 up=back.cross(right);up.unitize(tolerance);result.rotation.setColumn(0,right);result.rotation.setColumn(1,up);result.rotation.setColumn(2,back);apply(result);}
template<int P> void Orienter<P>::up(const Vector3& direction){CoordinateFrame result(frame);Vector3 oldRight=result.rotation.getColumn(0);Vector3 oldBack=result.rotation.getColumn(2);Vector3 up=direction.unit();Vector3 back=oldRight.cross(up);back.unitize(tolerance);Vector3 right=up.cross(back);right.unitize(tolerance);result.rotation.setColumn(0,right);result.rotation.setColumn(1,up);result.rotation.setColumn(2,back);apply(result);}
template<int P> void Orienter<P>::right(const Vector3& direction){CoordinateFrame result(frame);Vector3 oldUp=result.rotation.getColumn(1);Vector3 oldBack=result.rotation.getColumn(2);Vector3 right=direction.unit();Vector3 back=right.cross(oldUp);back.unitize(tolerance);Vector3 up=back.cross(right);up.unitize(tolerance);result.rotation.setColumn(0,right);result.rotation.setColumn(1,up);result.rotation.setColumn(2,back);apply(result);}
template struct Orienter<0x158>;template struct Orienter<0x1cc>;
