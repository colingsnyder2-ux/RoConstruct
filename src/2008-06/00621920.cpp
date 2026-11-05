// from server: 100% by auto
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: lua-5.1.2 roc_unit_f1a645ffa1da17e2.cpp

// Candidate translation unit (score above; library headers required).
#define LUA_CORE
#include <stdexcept>
#include "lua.h"
#include "ldo.h"
#include "lstate.h"
#include "ldebug.h"
struct lua_longjmp { struct lua_longjmp* previous; luai_jmpbuf b; volatile int status; };
class lua_exception : public std::exception
{
	friend void luaD_throw (lua_State*, int);
	friend int luaD_rawrunprotected (lua_State*, Pfunc, void*);
	struct lua_State* const L;
	struct lua_longjmp *const errorJmp;
	mutable bool committed;
	lua_exception(lua_State *L, lua_longjmp *errorJmp)
		:L(L)
		,errorJmp(errorJmp)
		,committed(false)
	{
	}	
	void commit() const { committed = true; }
public:
	lua_exception(const lua_exception& that)
		:L(that.L)
		,errorJmp(that.errorJmp)
		,committed(that.committed)
	{
		that.commit();
	}
	virtual const char *what() const throw()
	{
		return lua_tostring(L, -1);
	}
	~lua_exception() throw()
	{
		if (!committed)
		{
			// The exception was caught before Lua got it.
			// Revert the error state
			errorJmp->status = 0;
			// Pop th error message
			lua_pop(L, 1);
		} 
	}
};



int luaD_rawrunprotected(lua_State* L,Pfunc f,void* ud) {
 struct lua_longjmp lj;
 lj.status=0;
 lj.previous=(*reinterpret_cast<lua_longjmp**>(reinterpret_cast<char*>(L)+0x70));
 (*reinterpret_cast<lua_longjmp**>(reinterpret_cast<char*>(L)+0x70))=&lj;
 try { (*f)(L,ud); }
 catch(lua_exception& e) { e.commit(); if(lj.status==0) lj.status=-1; }
 catch(const std::exception& e) {
  try { luaG_runerror(L,e.what()); }
  catch(lua_exception& e) { e.commit(); if(lj.status==0) lj.status=-1; }
 }
 (*reinterpret_cast<lua_longjmp**>(reinterpret_cast<char*>(L)+0x70))=lj.previous;
 return lj.status;
}
