// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_axisrenderhighstorageebcf595a52b7fc8f.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include "G3D/GCamera.h"
struct Adorn;
struct Box {G3D::Vector3 low;float high[3];Box():low(G3D::Vector3::inf()){const G3D::Vector3& i=G3D::Vector3::inf();high[0]=-i.x;high[1]=-i.y;high[2]=-i.z;}G3D::Vector3 center()const{return(G3D::Vector3(high[0],high[1],high[2])+low)*0.5f;}G3D::Vector3 size()const{return G3D::Vector3(high[0],high[1],high[2])-low;}};
struct CameraInterface {virtual void slot0();virtual void slot1();virtual const G3D::GCamera& getGCamera() const;};
struct Workspace {char prefix[0x288];CameraInterface camera;};
struct Tool {bool bounds(Box&);};
void drawHandles(const G3D::Vector3&,const G3D::CoordinateFrame&,Adorn*,int,const G3D::Vector3&);
struct RenderInterface {char prefix[20];Workspace* workspace;void render(Adorn*);};
void RenderInterface::render(Adorn* adorn){Box box;if(reinterpret_cast<Tool*>(reinterpret_cast<char*>(this)-4)->bounds(box)){G3D::CoordinateFrame frame(box.center());G3D::Vector3 size=box.size();drawHandles(size,frame,adorn,1,workspace->camera.getGCamera().getCoordinateFrame().translation);}}
