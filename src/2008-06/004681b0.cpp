// from server: 100% by EspClaude
// from server: 82% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Complete keyboard handler: Win32 imports, native UIEvent/SDL declarations, and measured DxUserInput ABI.
// Opaque ranges represent unaccessed members; all accessed offsets and transport sizes are asserted.
#include <intrin.h>
#include <vector>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;shared_count():pi_(0){}shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {
 T*px;detail::shared_count pn;
 shared_ptr():px(0),pn(){}shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}
 template<class U>shared_ptr(const shared_ptr<U>&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}T*operator->()const{return px;}
};
}

#include <string>
#include <stddef.h>
typedef unsigned long DWORD;typedef unsigned int UINT;typedef long LPARAM;typedef unsigned int WPARAM;typedef void*HWND;typedef void*HKL;
struct CRITICAL_SECTION {void*DebugInfo;long LockCount;long RecursionCount;void*OwningThread;void*LockSemaphore;unsigned long SpinCount;};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) HKL __stdcall GetKeyboardLayout(DWORD);
extern "C" __declspec(dllimport) UINT __stdcall MapVirtualKeyExA(UINT,UINT,HKL);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(HWND,UINT,WPARAM,LPARAM);
struct WindowView {char unused[0x20];HWND handle;int PostMessage(UINT m,WPARAM w=0,LPARAM l=0){return ::PostMessageA(handle,m,w,l);}};
struct MainWindowView {char unused[0x104];bool acceleratorBypass;};
struct AppView {char unused[0x20];MainWindowView*mainWindow;MainWindowView*GetMainWnd(){return mainWindow;}};
struct ModuleStateView {char unused[4];AppView*application;};
ModuleStateView*__stdcall AfxGetModuleState();
inline AppView* AfxGetApp(){return AfxGetModuleState()->application;}
struct CriticalLock {
 CRITICAL_SECTION*mutex;bool active;
 explicit CriticalLock(CRITICAL_SECTION&m):mutex(&m),active(false){EnterCriticalSection(mutex);active=true;}
 ~CriticalLock(){if(active)LeaveCriticalSection(mutex);}
};
typedef enum {
	/* The keyboard syms have been cleverly chosen to map to ASCII */
	SDLK_UNKNOWN		= 0,
	SDLK_FIRST		= 0,
	SDLK_BACKSPACE		= 8,
	SDLK_TAB		= 9,
	SDLK_CLEAR		= 12,
	SDLK_RETURN		= 13,
	SDLK_PAUSE		= 19,
	SDLK_ESCAPE		= 27,
	SDLK_SPACE		= 32,
	SDLK_EXCLAIM		= 33,
	SDLK_QUOTEDBL		= 34,
	SDLK_HASH		= 35,
	SDLK_DOLLAR		= 36,
	SDLK_AMPERSAND		= 38,
	SDLK_QUOTE		= 39,
	SDLK_LEFTPAREN		= 40,
	SDLK_RIGHTPAREN		= 41,
	SDLK_ASTERISK		= 42,
	SDLK_PLUS		= 43,
	SDLK_COMMA		= 44,
	SDLK_MINUS		= 45,
	SDLK_PERIOD		= 46,
	SDLK_SLASH		= 47,
	SDLK_0			= 48,
	SDLK_1			= 49,
	SDLK_2			= 50,
	SDLK_3			= 51,
	SDLK_4			= 52,
	SDLK_5			= 53,
	SDLK_6			= 54,
	SDLK_7			= 55,
	SDLK_8			= 56,
	SDLK_9			= 57,
	SDLK_COLON		= 58,
	SDLK_SEMICOLON		= 59,
	SDLK_LESS		= 60,
	SDLK_EQUALS		= 61,
	SDLK_GREATER		= 62,
	SDLK_QUESTION		= 63,
	SDLK_AT			= 64,
	/* 
	   Skip uppercase letters
	 */
	SDLK_LEFTBRACKET	= 91,
	SDLK_BACKSLASH		= 92,
	SDLK_RIGHTBRACKET	= 93,
	SDLK_CARET		= 94,
	SDLK_UNDERSCORE		= 95,
	SDLK_BACKQUOTE		= 96,
	SDLK_a			= 97,
	SDLK_b			= 98,
	SDLK_c			= 99,
	SDLK_d			= 100,
	SDLK_e			= 101,
	SDLK_f			= 102,
	SDLK_g			= 103,
	SDLK_h			= 104,
	SDLK_i			= 105,
	SDLK_j			= 106,
	SDLK_k			= 107,
	SDLK_l			= 108,
	SDLK_m			= 109,
	SDLK_n			= 110,
	SDLK_o			= 111,
	SDLK_p			= 112,
	SDLK_q			= 113,
	SDLK_r			= 114,
	SDLK_s			= 115,
	SDLK_t			= 116,
	SDLK_u			= 117,
	SDLK_v			= 118,
	SDLK_w			= 119,
	SDLK_x			= 120,
	SDLK_y			= 121,
	SDLK_z			= 122,
	SDLK_DELETE		= 127,
	/* End of ASCII mapped keysyms */

	/* International keyboard syms */
	SDLK_WORLD_0		= 160,		/* 0xA0 */
	SDLK_WORLD_1		= 161,
	SDLK_WORLD_2		= 162,
	SDLK_WORLD_3		= 163,
	SDLK_WORLD_4		= 164,
	SDLK_WORLD_5		= 165,
	SDLK_WORLD_6		= 166,
	SDLK_WORLD_7		= 167,
	SDLK_WORLD_8		= 168,
	SDLK_WORLD_9		= 169,
	SDLK_WORLD_10		= 170,
	SDLK_WORLD_11		= 171,
	SDLK_WORLD_12		= 172,
	SDLK_WORLD_13		= 173,
	SDLK_WORLD_14		= 174,
	SDLK_WORLD_15		= 175,
	SDLK_WORLD_16		= 176,
	SDLK_WORLD_17		= 177,
	SDLK_WORLD_18		= 178,
	SDLK_WORLD_19		= 179,
	SDLK_WORLD_20		= 180,
	SDLK_WORLD_21		= 181,
	SDLK_WORLD_22		= 182,
	SDLK_WORLD_23		= 183,
	SDLK_WORLD_24		= 184,
	SDLK_WORLD_25		= 185,
	SDLK_WORLD_26		= 186,
	SDLK_WORLD_27		= 187,
	SDLK_WORLD_28		= 188,
	SDLK_WORLD_29		= 189,
	SDLK_WORLD_30		= 190,
	SDLK_WORLD_31		= 191,
	SDLK_WORLD_32		= 192,
	SDLK_WORLD_33		= 193,
	SDLK_WORLD_34		= 194,
	SDLK_WORLD_35		= 195,
	SDLK_WORLD_36		= 196,
	SDLK_WORLD_37		= 197,
	SDLK_WORLD_38		= 198,
	SDLK_WORLD_39		= 199,
	SDLK_WORLD_40		= 200,
	SDLK_WORLD_41		= 201,
	SDLK_WORLD_42		= 202,
	SDLK_WORLD_43		= 203,
	SDLK_WORLD_44		= 204,
	SDLK_WORLD_45		= 205,
	SDLK_WORLD_46		= 206,
	SDLK_WORLD_47		= 207,
	SDLK_WORLD_48		= 208,
	SDLK_WORLD_49		= 209,
	SDLK_WORLD_50		= 210,
	SDLK_WORLD_51		= 211,
	SDLK_WORLD_52		= 212,
	SDLK_WORLD_53		= 213,
	SDLK_WORLD_54		= 214,
	SDLK_WORLD_55		= 215,
	SDLK_WORLD_56		= 216,
	SDLK_WORLD_57		= 217,
	SDLK_WORLD_58		= 218,
	SDLK_WORLD_59		= 219,
	SDLK_WORLD_60		= 220,
	SDLK_WORLD_61		= 221,
	SDLK_WORLD_62		= 222,
	SDLK_WORLD_63		= 223,
	SDLK_WORLD_64		= 224,
	SDLK_WORLD_65		= 225,
	SDLK_WORLD_66		= 226,
	SDLK_WORLD_67		= 227,
	SDLK_WORLD_68		= 228,
	SDLK_WORLD_69		= 229,
	SDLK_WORLD_70		= 230,
	SDLK_WORLD_71		= 231,
	SDLK_WORLD_72		= 232,
	SDLK_WORLD_73		= 233,
	SDLK_WORLD_74		= 234,
	SDLK_WORLD_75		= 235,
	SDLK_WORLD_76		= 236,
	SDLK_WORLD_77		= 237,
	SDLK_WORLD_78		= 238,
	SDLK_WORLD_79		= 239,
	SDLK_WORLD_80		= 240,
	SDLK_WORLD_81		= 241,
	SDLK_WORLD_82		= 242,
	SDLK_WORLD_83		= 243,
	SDLK_WORLD_84		= 244,
	SDLK_WORLD_85		= 245,
	SDLK_WORLD_86		= 246,
	SDLK_WORLD_87		= 247,
	SDLK_WORLD_88		= 248,
	SDLK_WORLD_89		= 249,
	SDLK_WORLD_90		= 250,
	SDLK_WORLD_91		= 251,
	SDLK_WORLD_92		= 252,
	SDLK_WORLD_93		= 253,
	SDLK_WORLD_94		= 254,
	SDLK_WORLD_95		= 255,		/* 0xFF */

	/* Numeric keypad */
	SDLK_KP0		= 256,
	SDLK_KP1		= 257,
	SDLK_KP2		= 258,
	SDLK_KP3		= 259,
	SDLK_KP4		= 260,
	SDLK_KP5		= 261,
	SDLK_KP6		= 262,
	SDLK_KP7		= 263,
	SDLK_KP8		= 264,
	SDLK_KP9		= 265,
	SDLK_KP_PERIOD		= 266,
	SDLK_KP_DIVIDE		= 267,
	SDLK_KP_MULTIPLY	= 268,
	SDLK_KP_MINUS		= 269,
	SDLK_KP_PLUS		= 270,
	SDLK_KP_ENTER		= 271,
	SDLK_KP_EQUALS		= 272,

	/* Arrows + Home/End pad */
	SDLK_UP			= 273,
	SDLK_DOWN		= 274,
	SDLK_RIGHT		= 275,
	SDLK_LEFT		= 276,
	SDLK_INSERT		= 277,
	SDLK_HOME		= 278,
	SDLK_END		= 279,
	SDLK_PAGEUP		= 280,
	SDLK_PAGEDOWN		= 281,

	/* Function keys */
	SDLK_F1			= 282,
	SDLK_F2			= 283,
	SDLK_F3			= 284,
	SDLK_F4			= 285,
	SDLK_F5			= 286,
	SDLK_F6			= 287,
	SDLK_F7			= 288,
	SDLK_F8			= 289,
	SDLK_F9			= 290,
	SDLK_F10		= 291,
	SDLK_F11		= 292,
	SDLK_F12		= 293,
	SDLK_F13		= 294,
	SDLK_F14		= 295,
	SDLK_F15		= 296,

	/* Key state modifier keys */
	SDLK_NUMLOCK		= 300,
	SDLK_CAPSLOCK		= 301,
	SDLK_SCROLLOCK		= 302,
	SDLK_RSHIFT		= 303,
	SDLK_LSHIFT		= 304,
	SDLK_RCTRL		= 305,
	SDLK_LCTRL		= 306,
	SDLK_RALT		= 307,
	SDLK_LALT		= 308,
	SDLK_RMETA		= 309,
	SDLK_LMETA		= 310,
	SDLK_LSUPER		= 311,		/* Left "Windows" key */
	SDLK_RSUPER		= 312,		/* Right "Windows" key */
	SDLK_MODE		= 313,		/* "Alt Gr" key */
	SDLK_COMPOSE		= 314,		/* Multi-key compose key */

	/* Miscellaneous function keys */
	SDLK_HELP		= 315,
	SDLK_PRINT		= 316,
	SDLK_SYSREQ		= 317,
	SDLK_BREAK		= 318,
	SDLK_MENU		= 319,
	SDLK_POWER		= 320,		/* Power Macintosh power key */
	SDLK_EURO		= 321,		/* Some european keyboards */
	SDLK_UNDO		= 322,		/* Atari keyboard has Undo */

	/* Add any other keys here */

	SDLK_LAST
} SDLKey;
typedef enum {
	KMOD_NONE  = 0x0000,
	KMOD_LSHIFT= 0x0001,
	KMOD_RSHIFT= 0x0002,
	KMOD_LCTRL = 0x0040,
	KMOD_RCTRL = 0x0080,
	KMOD_LALT  = 0x0100,
	KMOD_RALT  = 0x0200,
	KMOD_LMETA = 0x0400,
	KMOD_RMETA = 0x0800,
	KMOD_NUM   = 0x1000,
	KMOD_CAPS  = 0x2000,
	KMOD_MODE  = 0x4000,
	KMOD_RESERVED = 0x8000
} SDLMod;
namespace G3D {struct Vector2int16 {short x,y;Vector2int16():x(0),y(0){}};struct Vector2;}
namespace RBX {
struct DataModel {struct Lock {char unused[12];Lock(boost::shared_ptr<const DataModel>);~Lock();};};
struct Adorn;struct Name;struct TextureId;struct TextureProxyBase;
struct ContentId {std::string id;const Name*type;};
template<class T>struct ReferenceCountedPointer {T*pointer;};
struct UserInputBase {
 enum WrapMode {WRAP_AUTO,WRAP_CENTER};
 virtual G3D::Vector2 getCursorPosition()=0;virtual ReferenceCountedPointer<TextureProxyBase>getGameCursor(Adorn*);
 virtual void setWrapMode(WrapMode)=0;virtual WrapMode getWrapMode()const=0;virtual void centerCursor()=0;virtual bool keyDown(SDLKey)const=0;virtual void setKeyState(SDLKey,bool)=0;virtual void setCursorId(Adorn*,const TextureId&);
 ContentId cursorId;ReferenceCountedPointer<TextureProxyBase>cursor;
};
struct UIEvent {
 enum EventType {NO_EVENT,MOUSE_RIGHT_BUTTON_DOWN,MOUSE_RIGHT_BUTTON_UP,MOUSE_LEFT_BUTTON_DOWN,MOUSE_LEFT_BUTTON_UP,MOUSE_MOVE,MOUSE_DELTA,MOUSE_IDLE,MOUSE_WHEEL_FORWARD,MOUSE_WHEEL_BACKWARD,KEY_DOWN,KEY_UP};
 EventType eventType;UserInputBase*userInput;
 union {struct{G3D::Vector2int16 mousePosition,mouseDelta;};struct{SDLKey key;SDLMod mod;};};
 G3D::Vector2int16 windowSize;
 UIEvent(UserInputBase*u,EventType t,SDLKey k,SDLMod m):eventType(t),userInput(u){key=k;mod=m;}
};
}
struct Device;
struct DIDEVICEOBJECTDATA {DWORD dwOfs,dwData,dwTimeStamp,dwSequence;unsigned long uAppData;};
struct ACCEL {unsigned char fVirt;unsigned short key;unsigned short cmd;};
SDLMod __cdecl getModifierState(const unsigned char*);
SDLKey __cdecl scanCodeToKey(DWORD);
int __cdecl keyToVirtualKey(SDLKey);
struct DxUserInput:RBX::UserInputBase {
 char unused28[12];CRITICAL_SECTION inputSync;
 WindowView*window;ACCEL*accelerators;unsigned acceleratorCount;
 char unused58[16];unsigned char keyboardState[256];char unused168[20];Device*keyboardDevice;
 boost::shared_ptr<RBX::DataModel>dataModel;
 char unused188[11];bool keyboardActive;
 bool readInput(void*,DWORD*,Device*);
 void processEvent(const RBX::UIEvent&);
 void processKeyboard();
};
void DxUserInput::processKeyboard(){
 DIDEVICEOBJECTDATA events[2048];DWORD count=2048;
 {
  CriticalLock lock(inputSync);
  Device* device=keyboardDevice;
  if(!readInput(events,&count,device)){keyboardActive=false;return;}
 }
 RBX::DataModel::Lock dataLock(dataModel);
 for(unsigned i=0;i<count;++i){
  DWORD scan=events[i].dwOfs;
  bool down=(events[i].dwData&0x80)!=0;
  SDLMod mods=getModifierState(keyboardState);
  SDLKey key=scanCodeToKey(scan);
  if(down&&window){
   static HKL keyboardLayout=GetKeyboardLayout(0);
   UINT virtualKey=MapVirtualKeyExA(scan,1,keyboardLayout);
   if(!virtualKey)virtualKey=keyToVirtualKey(key);
   if(virtualKey!=0x2c&&virtualKey!=0x70&&virtualKey!=0x73&&AfxGetApp()->GetMainWnd()->acceleratorBypass){_ReadWriteBarrier();}
   else if(virtualKey==0x2c){window->PostMessage(0x111,0x180fc,0);}
   else{
    UINT ascii=MapVirtualKeyExA(virtualKey,2,keyboardLayout);
    int flags=((mods&0x300)?0x10:0)|((mods&0xc0)?8:0)|((mods&3)?4:0);
    unsigned index;
    for(index=0;index<acceleratorCount;++index){
     if(accelerators[index].fVirt&1) {
      if(accelerators[index].key!=virtualKey)continue;
     } else {
      if(accelerators[index].key!=(char)ascii)continue;
     }
     if(flags!=(accelerators[index].fVirt&0x1c))continue;
     window->PostMessage(0x111,accelerators[index].cmd|0x10000,0);
     goto nextInputEvent;
    }
    
   }
  }
  processEvent(RBX::UIEvent(this,down?RBX::UIEvent::KEY_DOWN:RBX::UIEvent::KEY_UP,key,mods));
nextInputEvent:;
 }
}

typedef char assert_input_base[sizeof(RBX::UserInputBase)==0x28?1:-1];
typedef char assert_sync[offsetof(DxUserInput,inputSync)==0x34?1:-1];
typedef char assert_accel[offsetof(DxUserInput,accelerators)==0x50?1:-1];
typedef char assert_keyboard[offsetof(DxUserInput,keyboardState)==0x68?1:-1];
typedef char assert_device[offsetof(DxUserInput,keyboardDevice)==0x17c?1:-1];
typedef char assert_model[offsetof(DxUserInput,dataModel)==0x180?1:-1];
typedef char assert_active[offsetof(DxUserInput,keyboardActive)==0x193?1:-1];
typedef char assert_event[sizeof(RBX::UIEvent)==20?1:-1];
typedef char assert_accelerator[sizeof(ACCEL)==6?1:-1];
