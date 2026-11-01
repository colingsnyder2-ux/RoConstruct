// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class BrickColor { public: int number; };
namespace Reflection {
class DescribedBase { public: virtual ~DescribedBase(); };
template<class C, class V>
class PropDescriptor {
public:
	virtual ~PropDescriptor();
	virtual void setValue(DescribedBase* instance, const V& value) const = 0;
	char pad[0x14];
	template<class G, class S>
	class GetSetImpl;
};
}
class ExeHead { public: virtual ~ExeHead(); char pad[0x14]; };
class ExeVBase { public: virtual ~ExeVBase(); };
class ExeDescribed : public Reflection::DescribedBase { public: char pad[0x90-0x1c]; };
class Flag : public ExeHead, public ExeDescribed, public virtual ExeVBase {
public:
	BrickColor getTeamColor() const;
	void setTeamColor(BrickColor c);
};
namespace Reflection {
template<class C, class V>
template<class G, class S>
class PropDescriptor<C,V>::GetSetImpl : public PropDescriptor<C,V> {
public:
	S set;
	G get;
	virtual void setValue(DescribedBase* instance, const V& value) const
	{
		(static_cast<C*>(instance)->*set)(value);
	}
};
template class PropDescriptor<Flag, BrickColor>::GetSetImpl<BrickColor (Flag::*)() const, void (Flag::*)(BrickColor)>;
}
}
