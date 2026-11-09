// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_454d27b422690bab.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <list>
namespace Ogre {
struct Quad { Vector3 vertices[4]; };
class Listener : public RenderQueueListener {
public:
    SceneManager* manager;
    bool options[3];
    void* data;
    RenderOperation operation;
    HardwareVertexBufferSharedPtr vertices;
    HardwareIndexBufferSharedPtr indices;
    std::list<Quad> quads;
    Listener();
    ~Listener();
    void configure(SceneManager* scene, void* value, bool first, bool second, bool third);
};
Listener::Listener() {}
Listener::~Listener() {}
void Listener::configure(SceneManager* scene, void* value, bool first, bool second, bool third) {
    manager = scene;
    data = value;
    options[0] = first;
    options[1] = second;
    options[2] = third;
    vertices.setNull();
    scene->addRenderQueueListener(this);
}
}
