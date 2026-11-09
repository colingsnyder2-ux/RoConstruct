// from server: 100% by king_originala
#pragma optimize("", off)

struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3& operator=(const Vector3&);
    Vector3& operator+=(const Vector3&);
    Vector3 operator/(float) const;
};

struct Frame {
    char padding[36];
    Vector3 position;
};

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual const Frame& getFrame();
};

struct Iterator {
    unsigned int state[2];
    bool operator!=(const Iterator&) const;
    Iterator& operator++();
    Object*& operator*() const;
};

struct Collection {
    Iterator begin();
    Iterator end();
    unsigned int size() const;
};

struct AggregateChunk {
    Vector3 position;
    Collection objects;
    void update();
};

void AggregateChunk::update()
{
    Vector3 sum;
    Iterator last = objects.begin();
    Iterator i = objects.end();

    for (; last != i; ++last)
        sum += (*last)->getFrame().position;

    position = sum / static_cast<float>(objects.size());
}
