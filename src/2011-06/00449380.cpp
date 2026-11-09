// from server: 80% by atomic.potato
struct Vector3ComponentItem
{
    int data[74];
    int Compare(float *a, float *b);
};

int __thiscall Vector3ComponentItem::Compare(float *a, float *b)
{
    float *v = (float *)(data[74] * 4);
    return v[(int)a] != v[(int)b];
}
