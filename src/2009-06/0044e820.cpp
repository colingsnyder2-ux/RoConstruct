// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct I1 { virtual long __stdcall QueryInterface(const void*, void**) = 0; virtual unsigned long __stdcall AddRef() = 0; virtual unsigned long __stdcall Release() = 0; int a, b, c; };
class Base { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual ~Base(); int x; long m_ref; };
class Obj : public I1, public Base {
public:
	unsigned long __stdcall Release();
};
unsigned long __stdcall Obj::Release()
{
	long* r = &m_ref; unsigned long l = --*r; if (l == 0) delete this; return l;
}
