// from server: 73% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CountedBase
{
	virtual ~CountedBase();
	virtual void dispose();
	virtual void destroy();
	long use_count;
	long weak_count;

	void weak_release()
	{
		if (_InterlockedExchangeAdd(&weak_count, -1) == 1)
			destroy();
	}
	void release()
	{
		if (_InterlockedExchangeAdd(&use_count, -1) == 1)
		{
			dispose();
			weak_release();
		}
	}
};

struct SharedCount
{
	CountedBase* pi;
	SharedCount() : pi(0) {}
	~SharedCount()
	{
		if (pi != 0)
			pi->release();
	}
};

struct Elem
{
	int a;
	int b;
};

struct Vec
{
	int alval;
	Elem* first;
	Elem* last;
	Elem* end;

	unsigned int size() const
	{
		return first == 0 ? 0 : (unsigned int)(last - first);
	}
};

struct Holder
{
	char pad[0x104];
	Vec* vec;
};

struct Getter
{
	void* dm;
	void* px;
	SharedCount pn;

	Getter(void* d) : dm(d), px(0) {}
	Holder* get(bool create);
};

struct GroupSelectionVerb
{
	char pad[0x14];
	mutable Getter getter;
	void* dataModel;

	bool isEnabled() const;
};

bool GroupSelectionVerb::isEnabled() const
{
	if (getter.get(true)->vec->size() == 0)
		return false;

	Getter local(dataModel);
	return local.get(true)->vec->size() > 1;
}
