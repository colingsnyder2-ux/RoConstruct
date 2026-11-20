// draft: 00467ad0 getCenteredPosition - smallest function first (116 bytes)
// inherits real RBX::DxUserInput from native headers

#include "util/DxUserInput.h"

namespace RBX
{

G3D::Vector2 DxUserInput::getCenteredPosition()
{
    mutex.Lock();
    RECT rect;
    this->window->GetClientRect(&rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    G3D::Vector2 result(
        (float)(width * 0.5f) + lastPosition.x,
        (float)(height * 0.5f) + lastPosition.y
    );
    mutex.Unlock();
    return result;
}

} // namespace RBX