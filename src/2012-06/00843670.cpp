// from server: 100% by tajop
struct lua_State;

struct Str
{
	void* alloc;
	union
	{
		char buf[16];
		char* ptr;
	} bx;
	unsigned int mysize;
	unsigned int myres;

	~Str();
	const char* c_str() const { return myres >= 16 ? bx.ptr : bx.buf; }
	unsigned int size() const { return mysize; }
};

extern void (Str::*Str_dtor)();

inline Str::~Str()
{
	(this->*Str_dtor)();
}

Str convertToString(const void* value);
void lua_pushlstring(lua_State* L, const char* s, unsigned int len);

int pushStringValue(const void* value, lua_State* L)
{
	Str s = convertToString(value);
	lua_pushlstring(L, s.c_str(), s.size());
	return 1;
}
