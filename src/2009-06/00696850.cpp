// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector2 { public: float x, y;
  Vector2(float _x, float _y) : x(_x), y(_y) {}
  Vector2(const Vector2& o) : x(o.x), y(o.y) {} }; }
namespace RBX {
class VVirtualUser {
public:
    void sendMouse(int button, G3D::Vector2 pos);
    void onMouseUp(float x, float y);
};
void VVirtualUser::onMouseUp(float x, float y)
{
    sendMouse(2, G3D::Vector2(x, y));
}
}
