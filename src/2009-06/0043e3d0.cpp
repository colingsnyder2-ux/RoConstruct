// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Reflection {
class DescribedBase;
class Value { public: template<class T> Value& operator=(const T&); };
template<class V> struct GetSet {
	virtual void v0();
	virtual void v1();
	virtual V get(const DescribedBase*) const = 0;
};
template<class V> class BoundProp {
	char pad[0x18];
	GetSet<V>* getset;
public:
	void getValue(const DescribedBase* obj, Value& value) const;
};
template<class V> void BoundProp<V>::getValue(const DescribedBase* obj, Value& value) const
{
	value = getset->get(obj);
}
template class BoundProp<int>;
}}
