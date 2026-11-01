// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct Data { int a, b; float value; };
struct Table { Data get(int id); void set(int id, const Data& d); };
struct Item { int f(); };
struct Owner { char pad[0x118]; Table* table; void changed(int id); Item* item(int id); void raise(int); };
struct S { Owner* owner; int id; void setValue(float v); };
void S::setValue(float v)
{
    Data d = owner->table->get(id);
    if (d.value != v) {
        d.value = v;
        owner->table->set(id, d);
        owner->changed(id);
        owner->raise(owner->item(id)->f());
    }
}
