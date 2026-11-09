// from server: 100% by king_originala
extern "C" const char* __cdecl lua_tolstring(void*, int, unsigned int*);

struct lua_exception {
    char padding[12];
    void* state;
    const char* what() const;
};

const char* lua_exception::what() const {
    return lua_tolstring(state, -1, 0);
}
