// from server: 100% by Espeon
extern "C" __declspec(dllimport) int __cdecl sprintf(char*, const char*, ...);
struct VVector3 {float x,y,z;};
struct CString {void* data;__declspec(dllimport) CString(const char*);__declspec(dllimport) CString(const CString&);__declspec(dllimport) ~CString();};
struct XItem {virtual void unused00();virtual void unused01();virtual void unused02();virtual void unused03();virtual void unused04();virtual void unused05();virtual void unused06();virtual void unused07();virtual void unused08();virtual void unused09();virtual void unused10();virtual void unused11();virtual void unused12();virtual void unused13();virtual void unused14();virtual void unused15();virtual void unused16();virtual void unused17();virtual void unused18();virtual void unused19();virtual void unused20();virtual void unused21();virtual void unused22();virtual void unused23();virtual void setValue(CString);void format(VVector3*);};
void XItem::format(VVector3* v) {char buf[256];sprintf(buf,"%.3g, %.3g, %.3g",v->x,v->y,v->z);setValue(CString(buf));}
