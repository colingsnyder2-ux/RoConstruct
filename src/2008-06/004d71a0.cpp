// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { extern bool showFrameRate; extern bool showProfile;
namespace ViewNew { class ViewRbxGfx { public: static void setDebug(bool b); }; 
void ViewRbxGfx::setDebug(bool b) { showFrameRate = b; showProfile = b; } } }
