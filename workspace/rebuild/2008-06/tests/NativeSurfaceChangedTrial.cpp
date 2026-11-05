// Diagnostic overlay; field and base offsets require full PartInstance lifetime proof.
namespace RBX {
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
class IRenderable { public: void shouldRenderSetDirty(); };
class PartInstance { public: void onSurfaceChanged(NormalId); };
void PartInstance::onSurfaceChanged(NormalId) {
    char* const object = reinterpret_cast<char*>(this);
    object[0x398] = 1;
    object[0x141] = 1;
    object[0x3b1] = 1;
    reinterpret_cast<IRenderable*>(object + 0x1cc)->shouldRenderSetDirty();
}
}
