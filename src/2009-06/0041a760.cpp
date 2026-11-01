// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace std { class __declspec(dllimport) string { public: const char* c_str() const; char pad[0x1c]; }; }
class __declspec(dllimport) CStr {
public:
	CStr(const char*);
	~CStr();
	void* p;
};
struct Inner { char pad[0x54]; std::string s; };
struct Outer {
	char pad[0x7c];
	Inner* m;
	CStr GetText(int) const;
};
CStr Outer::GetText(int) const
{
	return CStr(m->s.c_str());
}
