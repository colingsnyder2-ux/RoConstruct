// from server: 100% by colin
struct Vec2 { float x; float y; };

extern "C" Vec2* __cdecl get_zero_vec();

struct ArrowPanel {
    virtual bool can_use();
    virtual bool v04();
    virtual bool v08();
    virtual bool v0c();
    virtual bool v10();
    virtual bool v14();
    virtual bool v18();
    virtual bool v1c();
    virtual bool v20();
    virtual bool v24();
    virtual bool v28();
    virtual bool v2c();
    virtual bool v30();
    virtual bool v34();
    virtual bool v38();
    virtual bool v3c();
    virtual bool v40();
    virtual bool v44();
    virtual bool v48();
    virtual bool v4c();
    virtual bool v50();
    virtual bool can_use2();
    Vec2* set_pos(Vec2* out);
    void helper(Vec2* out);
};

Vec2* ArrowPanel::set_pos(Vec2* out) {
    if (can_use2()) {
        helper(out);
        return out;
    }
    Vec2* z = get_zero_vec();
    out->x = z->x;
    out->y = z->y;
    return out;
}
