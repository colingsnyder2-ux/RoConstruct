// from server: 86% by atomic.potato
struct Vector3ComponentItem
{
    int padding[74];
    int offset;
    int equals(const float *, const float *);
};

int Vector3ComponentItem::equals(const float *a, const float *b)
{
    return a[offset] == b[offset];
}
