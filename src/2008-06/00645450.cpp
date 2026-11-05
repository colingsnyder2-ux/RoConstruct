// from server: 100% by king_originala
struct Object {
    virtual void slot0();
    virtual void slot1(float value, int argument);
    void update(float value);
};

struct Holder {
    Object* object;
};

void __cdecl updateHolder(Holder* holder, float value);

void __cdecl process(Holder* holder, float value, int argument)
{
    holder->object->update(value);
    updateHolder(holder, value);
    holder->object->slot1(value, argument);
}
