// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_bf96e0da3f42017e.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include <vector>
#include <boost/weak_ptr.hpp>
#include <G3D/GCamera.h>
struct Part;struct Model;
struct CameraSlot{virtual void slot0();virtual void slot1();virtual const G3D::GCamera& getGCamera() const;};
struct Root{char prefix[0x288];CameraSlot camera;G3D::Vector3 fallback() const;G3D::Vector3 compute(const RBX::Extents&) const;};
Model* getCharacter(const Root*);
void collect(Model*,std::vector<boost::weak_ptr<Part> >&);
RBX::Extents bounds(const std::vector<boost::weak_ptr<Part> >&);
G3D::Vector3 toGrid(const G3D::Vector3&);
G3D::Vector3 Root::compute(const RBX::Extents&region)const{Model*character=getCharacter(this);if(character){G3D::Vector3 look=camera.getGCamera().getCoordinateFrame().lookVector();float unusedLookY=look.y;look.y=0;look.unitize();G3D::Vector3 half=region.size()*.5f;float unusedHalfY=half.y;half.y=0;std::vector<boost::weak_ptr<Part> >parts;collect(character,parts);RBX::Extents box=bounds(parts);G3D::Vector3 position=box.bottomCenter()+look*7.f+G3D::Vector3(half.x*look.x,half.y*look.y,look.z*half.z);position=toGrid(position);return position;}return fallback();}
