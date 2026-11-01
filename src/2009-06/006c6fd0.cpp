// from server: 100% by EspClaude
// roc 2009-06 006c6fd0  unit: seg_006c0000  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c6fd0
//
// 006c6fd0  83ec08               sub esp, 8
// 006c6fd3  56                   push esi
// 006c6fd4  8b742410             mov esi, dword ptr [esp + 0x10]
// 006c6fd8  57                   push edi
// 006c6fd9  68a4c08e00           push 0x8ec0a4
// 006c6fde  689cc08e00           push 0x8ec09c
// 006c6fe3  6a01                 push 1
// 006c6fe5  56                   push esi
// 006c6fe6  e8d53fffff           call 0x6bafc0
// 006c6feb  6a00                 push 0
// 006c6fed  6a02                 push 2
// 006c6fef  56                   push esi
// 006c6ff0  8bf8                 mov edi, eax
// 006c6ff2  e8793effff           call 0x6bae70
// 006c6ff7  50                   push eax
// 006c6ff8  8b04bd80c08e00       mov eax, dword ptr [edi*4 + 0x8ec080]
// 006c6fff  50                   push eax
// 006c7000  56                   push esi
// 006c7001  e8fa2bffff           call 0x6b9c00
// 006c7006  8b3cbd80c08e00       mov edi, dword ptr [edi*4 + 0x8ec080]
// 006c700d  83c428               add esp, 0x28
// 006c7010  83ef03               sub edi, 3
// 006c7013  89442408             mov dword ptr [esp + 8], eax
// 006c7017  7423                 je 0x6c703c
// 006c7019  83ef02               sub edi, 2
// 006c701c  7409                 je 0x6c7027
// 006c701e  db442408             fild dword ptr [esp + 8]
// 006c7022  83ec08               sub esp, 8
// 006c7025  eb34                 jmp 0x6c705b
// 006c7027  50                   push eax
// 006c7028  56                   push esi
// 006c7029  e80225ffff           call 0x6b9530
// 006c702e  83c408               add esp, 8
// 006c7031  5f                   pop edi
// 006c7032  b801000000           mov eax, 1
// 006c7037  5e                   pop esi
// 006c7038  83c408               add esp, 8
// 006c703b  c3                   ret 
// 006c703c  6a00                 push 0
// 006c703e  6a04                 push 4
// 006c7040  56                   push esi
// 006c7041  e8ba2bffff           call 0x6b9c00
// 006c7046  89442418             mov dword ptr [esp + 0x18], eax
// 006c704a  db442418             fild dword ptr [esp + 0x18]
// 006c704e  83c404               add esp, 4
// 006c7051  dc0d78c08e00         fmul qword ptr [0x8ec078]
// 006c7057  da442410             fiadd dword ptr [esp + 0x10]
// 006c705b  dd1c24               fstp qword ptr [esp]
// 006c705e  56                   push esi
// 006c705f  e8dc22ffff           call 0x6b9340
// 006c7064  83c40c               add esp, 0xc
// 006c7067  5f                   pop edi
// 006c7068  b801000000           mov eax, 1
// 006c706d  5e                   pop esi
// 006c706e  83c408               add esp, 8
// 006c7071  c3                   ret 
// copied from an identical function in another client (function __luaB_collectgarbage)

// from server: 100% by colin
// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD

typedef struct lua_State lua_State;

extern int _luaL_checkoption(lua_State *L, int n, const char *def,
                             const char *const lst[]);
extern int _luaL_optinteger(lua_State *L, int n, int d);
extern int _lua_gc(lua_State *L, int what, int data);
extern void _lua_pushboolean(lua_State *L, int b);
extern void _lua_pushnumber(lua_State *L, double n);

int _luaB_collectgarbage(lua_State *L) {
  static const char *const opts[] = {"stop", "restart", "collect",
    "count", "step", "setpause", "setstepmul", 0};
  static const int optsnum[] = {0, 1, 2, 3, 5, 6, 7};
  int o = _luaL_checkoption(L, 1, "collect", opts);
  int ex = _luaL_optinteger(L, 2, 0);
  int res = _lua_gc(L, optsnum[o], ex);
  switch (optsnum[o]) {
    case 3: {
      int b = _lua_gc(L, 4, 0);
      _lua_pushnumber(L, res + ((double)b/1024));
      return 1;
    }
    case 5: {
      _lua_pushboolean(L, res);
      return 1;
    }
    default: {
      _lua_pushnumber(L, res);
      return 1;
    }
  }
}