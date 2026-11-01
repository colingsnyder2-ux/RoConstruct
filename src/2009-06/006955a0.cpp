// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
class mutex;
template<class T> class shared_ptr {
public:
	T* px;
	void* pn;
	T& operator*() const { return *px; }
};
}
struct ExeLock { boost::mutex* m; ExeLock(boost::mutex&); ~ExeLock(); };
namespace RBX { namespace Lua {
class ThreadRef {
public:
	class Node {
	public:
		ThreadRef* first;
		boost::shared_ptr<boost::mutex> sync;
		void eraseAllRefs();
	};
	virtual void removeRef();
	boost::shared_ptr<boost::mutex> sync;
	Node* node;
	ThreadRef* previous;
	ThreadRef* next;
};
void ThreadRef::Node::eraseAllRefs()
{
	ExeLock lock(*sync);
	for (ThreadRef* ref = first; ref; ref = ref->next)
	{
		ref->removeRef();
		ref->node = 0;
	}
	first = 0;
}
}}
