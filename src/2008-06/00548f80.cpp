// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Analog for 00548f80: picks the detail level for a distance (0054aca0, double
// argument) and returns a handle built (004e6030) from that level's key
// (operator[] 0054ae90, key 00540e80).
class Entry {
public:
    int key() const;
};

class Entries {
public:
    Entry& operator[](int n);
};

class Handle {
public:
    Handle(int key);
    ~Handle();
    void* value;
};

class Levels {
public:
    int levelFor(double distance);
    Handle handleFor(float distance);
    char header[0x0c];
    Entries entries;
};

Handle Levels::handleFor(float distance)
{
    int level = levelFor(distance);
    return Handle(entries[level].key());
}
