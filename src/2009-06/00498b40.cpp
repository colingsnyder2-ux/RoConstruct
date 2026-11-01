// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
class PathResolver {
public:
	explicit PathResolver(int flags);
	virtual ~PathResolver();
	static PathResolver* get();
private:
	int flags;
	std::string path;
	static PathResolver* singleton;
};
PathResolver* PathResolver::get()
{
	if (!singleton)
		singleton = new PathResolver(0);
	return singleton;
}
