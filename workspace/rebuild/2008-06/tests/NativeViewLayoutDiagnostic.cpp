#include "../native-headers/CRobloxView.h"
#include <cstddef>

// Layout claims from RTTI base offsets and constructor 00459eb0.
typedef char WindowSize[sizeof(CRobloxWnd) == 0xc0 ? 1 : -1];
typedef char ReflectorSize[sizeof(CReflectorWnd) == 0x58 ? 1 : -1];
typedef char MenuSize[sizeof(CMenu) == 8 ? 1 : -1];
typedef char ViewSize[sizeof(CRobloxView) == 0x1f0 ? 1 : -1];
typedef char WindowOffset[offsetof(CRobloxView, window) == 0xb0 ? 1 : -1];
typedef char MenuOffset[offsetof(CRobloxView, popupMenu) == 0x178 ? 1 : -1];
typedef char ReflectorOffset[offsetof(CRobloxView, reflector) == 0x180 ? 1 : -1];
typedef char TailOffset[offsetof(CRobloxView, slots_1d8_1ec) == 0x1d8 ? 1 : -1];

// Diagnostic: forces the real size/offset into the error text of this line.
template<int N> struct Show { char bad[-N - 1]; };
Show<sizeof(CRobloxWnd)> showWindow;
Show<sizeof(CReflectorWnd)> showReflector;
Show<sizeof(CMenu)> showMenu;
Show<sizeof(CRobloxView)> showView;
Show<offsetof(CRobloxView, window)> showWindowOffset;
Show<offsetof(CRobloxView, popupMenu)> showMenuOffset;
Show<offsetof(CRobloxView, reflector)> showReflectorOffset;
Show<sizeof(CView)> showCView;
Show<sizeof(VerbBinder<CRobloxView, CView> )> showBinder;
Show<sizeof(RBX::VerbContainer)> showContainer;
Show<sizeof(RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>)> showListener;
Show<(int)static_cast<RBX::VerbContainer*>(reinterpret_cast<CRobloxView*>(0x10000)) - 0x10000 + 1000> showContainerAt;
Show<(int)static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>*>(reinterpret_cast<CRobloxView*>(0x10000)) - 0x10000 + 2000> showListenerAt;
Show<(int)&reinterpret_cast<CRobloxView*>(0x10000)->window - 0x10000 + 3000> showWindowAt;
