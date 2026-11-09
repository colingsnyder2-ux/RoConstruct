// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Codegen analog of reflection GetImpl/GetSetImpl::getValue. The target converts
// DescribedBase* to Class* with "add eax,-0x1c": DescribedBase sits at +0x1c.
// Get member pointer is an 8-byte {fn, adj} pair at +8; result returned in eax.

class DescribedBase { public: virtual ~DescribedBase(); };
// Bytes preceding DescribedBase in Class, sized from the target's 0x1c adjust.
class Before { public: virtual ~Before(); int words[6]; };
class Class : public Before, public DescribedBase {
public:
	int getIt() const;
};

class GetSet {
public:
	virtual ~GetSet() {}
	virtual int getValue(const DescribedBase* object) const = 0;
	int reserved;
};

template<typename GetFunction>
class GetImpl : public GetSet {
	GetFunction get;
public:
	GetImpl(GetFunction get) : get(get) {}
	virtual int getValue(const DescribedBase* object) const
	{
		Class* o = (Class*)object;
		return (o->*get)();
	}
};

template class GetImpl<int (Class::*)() const>;