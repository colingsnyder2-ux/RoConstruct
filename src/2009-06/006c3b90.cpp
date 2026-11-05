// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.4 roc_espclaude_2c4c80f55a28b088.cpp

// Candidate translation unit (score above; library headers required).
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace rbx {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void release() {
		if (_InterlockedDecrement(&use_count_) == 0) {
			dispose();
			weak_release();
		}
	}
	void weak_release() {
		if (_InterlockedDecrement(&weak_count_) == 0)
			destroy();
	}
	long use_count_;
	long weak_count_;
};
struct ExtraSpace {
	int* counter;
	sp_counted_base* pi;
	int resume;
};
}
struct lua_State;
static inline void rbx_userstateclose(lua_State* L) {
	rbx::ExtraSpace* e = reinterpret_cast<rbx::ExtraSpace*>(reinterpret_cast<unsigned char*>(L) - 12);
	--*e->counter;
	if (e->pi) e->pi->release();
}
extern "C" {
#define lstate_c
#define LUA_CORE
#include "lua.h"
#undef LUAI_EXTRASPACE
#define LUAI_EXTRASPACE 12
#undef luai_userstateclose
#define luai_userstateclose(L) rbx_userstateclose(L)
#include "lstate.c"
}
