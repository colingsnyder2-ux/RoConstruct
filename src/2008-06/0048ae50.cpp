// from server: 100% by king_originala
inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct Value
{
    float x, y, z, w;

    Value(const Value&);
    Value& operator=(const Value&);
};

inline Value::Value(const Value& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
}

inline Value& Value::operator=(const Value& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
    return *this;
}

struct S
{
    Value* data;
    int size;
    int capacity;

    void resize(int, bool);
    void func_0048ae50(const Value&);
};

void S::func_0048ae50(const Value& value)
{
    if (size < capacity)
    {
        new (data + size) Value(value);
        ++size;
    }
    else if (&value >= data && &value < data + size)
    {
        Value copy(value);
        func_0048ae50(copy);
    }
    else
    {
        resize(size + 1, false);
        data[size - 1] = value;
    }
}
