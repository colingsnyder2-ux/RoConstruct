#pragma once
#include "util/UserInputBase.h"

// Windows adapter for the recovered UserInputBase interface.
class PlayerNativeInput : public RBX::UserInputBase {
    bool keys[SDLK_LAST];
    WrapMode wrap;
protected:
    virtual G3D::Vector2 getCursorPosition();
public:
    PlayerNativeInput();
    virtual void setWrapMode(WrapMode mode);
    virtual WrapMode getWrapMode() const;
    virtual void centerCursor();
    virtual bool keyDown(SDLKey key) const;
    virtual void setKeyState(SDLKey key,bool down);
};
