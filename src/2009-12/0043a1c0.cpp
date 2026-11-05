// from server: 55% by atomic.potato
struct Vector3ComponentItem
{
    int data;
    int equals(const float* a, const float* b);
};

int Vector3ComponentItem::equals(const float* a, const float* b)
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x130) == *a &&
           *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0x130) == *b;
}
