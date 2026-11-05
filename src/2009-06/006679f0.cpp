// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost {
template<class T> class shared_ptr {
public:
	T* px; void* pn;
	T* get() const { return px; }
	T* operator->() const { return px; }
	operator bool() const { return px != 0; }
};
}
namespace RBX {
class Instance;
typedef std::vector<boost::shared_ptr<Instance> > Instances;
template<class T> class copy_on_write_ptr {
public:
	T* px; void* pn;
	const T* operator->() const { return px; }
	operator bool() const { return px != 0; }
};
class Instance {
public:
	virtual ~Instance();
	char pad[0x48];
	copy_on_write_ptr<Instances> children;
	template<class T> T* findFirstChildOfType() const
	{
		if (children)
		{
			Instances::const_iterator end = children->end();
			for (Instances::const_iterator iter = children->begin(); iter != end; ++iter)
			{
				if (T* c = dynamic_cast<T*>(iter->get()))
					return c;
			}
		}
		return 0;
	}
};
class DataModelMesh : public Instance {};
class Decal : public Instance {};
template DataModelMesh* Instance::findFirstChildOfType<DataModelMesh>() const;
}
