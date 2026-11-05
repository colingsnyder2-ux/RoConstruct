// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_pointframe_dc6af335429acbfb.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
struct Link {char padding[0x94];G3D::CoordinateFrame frame;};
struct Point {char padding[0xc];Link* link;G3D::Vector3 position;G3D::Vector3 world;G3D::Vector3 velocity;void update();};
void Point::update(){const G3D::CoordinateFrame& f=link->frame;
world=G3D::Vector3(f.rotation[0][2]*position.z+f.rotation[0][1]*position.y+f.rotation[0][0]*position.x+f.translation.x,
f.rotation[1][2]*position.z+f.rotation[1][0]*position.x+f.rotation[1][1]*position.y+f.translation.y,
f.rotation[2][2]*position.z+f.rotation[2][0]*position.x+f.rotation[2][1]*position.y+f.translation.z);velocity=G3D::Vector3::zero();}
