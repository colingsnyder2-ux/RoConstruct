// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_cursorinlinesetter_6ffde8b621b0322d.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
struct Name;
struct Value { std::string text; const Name* type; };
extern Value __cdecl make_value(const char*);
struct Camera;
typedef void (__thiscall* CameraMethod)(Camera*,int,const Value&);
struct Camera { CameraMethod* methods; void setCursor(int); __forceinline void set(int argument,const Value& value) { Value copy(value); methods[7](this,argument,copy); } };
void Camera::setCursor(int argument) { set(argument,make_value("Textures\\ArrowCursor.png")); }