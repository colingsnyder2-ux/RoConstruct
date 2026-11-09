// from server: 100% by king_originala
struct Holder {
    virtual ~Holder();
    virtual const void* type() const;
    virtual Holder* clone() const;
};

struct Value {
    int key;
    Holder* content;
};

void __cdecl fill(Value* first, Value* last, const Value& value)
{
    for (; first != last; ++first) {
        first->key = value.key;
        Holder* source = value.content;
        Holder* temporary = source ? source->clone() : 0;
        if (&temporary != &first->content) {
            Holder* saved = temporary;
            temporary = first->content;
            first->content = saved;
        }
        if (temporary)
            delete temporary;
    }
}
