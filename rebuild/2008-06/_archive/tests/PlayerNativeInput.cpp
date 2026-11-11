#include "PlayerNativeInput.h"
#include "v8datamodel/UserController.h"
#include "RbxGraphics/Adorn.h"
#include <windows.h>
#include <cstring>

namespace RBX {
// 005ceaa0, 005ceb00 and 005cec50: cursor ID/cache lifecycle.
UserInputBase::UserInputBase():currentCursor(NULL){}
UserInputBase::~UserInputBase(){}
G3D::ReferenceCountedPointer<TextureProxyBase> UserInputBase::getGameCursor(Adorn* adorn){
    if(!currentCursor.notNull()){
        currentCursor=adorn->createTextureProxy(currentCursorId.toString());
        if(!currentCursor.notNull())currentCursor=adorn->createTextureProxy(ContentId::fromAssets("Textures\\ArrowCursor.png").toString());
    }
    return currentCursor;
}
void UserInputBase::setCursorId(Adorn*,const TextureId& id){
    if(currentCursorId!=id){currentCursorId=id;currentCursor=G3D::ReferenceCountedPointer<TextureProxyBase>();}
}
// Original view setup 0045f7b0 assigns this field when attaching its input device.
void ControllerService::setHardwareDevice(UserInputBase* input){hardwareDevice=input;}
}

PlayerNativeInput::PlayerNativeInput():wrap(WRAP_AUTO){std::memset(keys,0,sizeof(keys));}
void PlayerNativeInput::setWrapMode(WrapMode mode){wrap=mode;}
RBX::UserInputBase::WrapMode PlayerNativeInput::getWrapMode() const{return wrap;}
G3D::Vector2 PlayerNativeInput::getCursorPosition(){
    POINT point;GetCursorPos(&point);HWND window=GetForegroundWindow();if(window)ScreenToClient(window,&point);
    return G3D::Vector2(static_cast<float>(point.x),static_cast<float>(point.y));
}
void PlayerNativeInput::centerCursor(){
    HWND window=GetForegroundWindow();DWORD process=0;if(window)GetWindowThreadProcessId(window,&process);
    if(window && process==GetCurrentProcessId()){
        RECT rect;GetClientRect(window,&rect);POINT point={(rect.left+rect.right)/2,(rect.top+rect.bottom)/2};
        ClientToScreen(window,&point);SetCursorPos(point.x,point.y);
    }
}
bool PlayerNativeInput::keyDown(SDLKey key) const{
    if(key>=0 && key<SDLK_LAST && keys[key])return true;
    HWND window=GetForegroundWindow();DWORD process=0;if(window)GetWindowThreadProcessId(window,&process);
    if(!window || process!=GetCurrentProcessId())return false;
    int vk=0;
    if(key>=SDLK_a && key<=SDLK_z)vk='A'+(key-SDLK_a);
    else if(key==SDLK_UP)vk=VK_UP;else if(key==SDLK_DOWN)vk=VK_DOWN;
    else if(key==SDLK_LEFT)vk=VK_LEFT;else if(key==SDLK_RIGHT)vk=VK_RIGHT;
    else if(key==SDLK_SPACE)vk=VK_SPACE;else if(key==SDLK_LALT)vk=VK_LMENU;else if(key==SDLK_RALT)vk=VK_RMENU;
    return vk && (GetAsyncKeyState(vk)&0x8000)!=0;
}
void PlayerNativeInput::setKeyState(SDLKey key,bool down){if(key>=0 && key<SDLK_LAST)keys[key]=down;}
