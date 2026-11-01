// from server: 100% by king_originala
#pragma optimize("", off)

struct Iterator {
    int context;
    int* position;
    Iterator();
    bool operator!=(const Iterator& other) const;
};

struct Bucket {
    Iterator begin();
    Iterator end();
    Iterator erase(Iterator position);
};

extern Iterator __cdecl find(Iterator first, Iterator last, int* value);

struct S {
    char padding[12];
    Bucket bucket;
    bool f(int* value);
};

bool S::f(int* value)
{
    Iterator position = find(bucket.begin(), bucket.end(), value);
    if (position != bucket.end()) {
        bucket.erase(Iterator(position));
        return true;
    } else {
        return false;
    }
}
