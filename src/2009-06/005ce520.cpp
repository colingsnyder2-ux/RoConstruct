// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <string>
namespace boost { template<class T> class shared_ptr { T* px; void* pn; public: T* operator->() const { return px; } }; }
namespace RBX {
class Instance;
struct Children { std::vector<boost::shared_ptr<Instance> > v; };
class Instance {
	char pad[0x4c];
	Children* children;
public:
	Instance* findFirstChildByName(const std::string& findName) const;
	Instance* findFirstChildByNameRecursive(const std::string& findName) const;
};
Instance* Instance::findFirstChildByNameRecursive(const std::string& findName) const
{
	Instance* foundChild = findFirstChildByName(findName);
	if (foundChild)
		return foundChild;
	if (!children)
		return NULL;
	const std::vector<boost::shared_ptr<Instance> >& c = children->v;
	for (size_t i = 0; i < c.size(); i++)
	{
		Instance* child = c[i]->findFirstChildByNameRecursive(findName);
		if (child)
			return child;
	}
	return NULL;
}
}
