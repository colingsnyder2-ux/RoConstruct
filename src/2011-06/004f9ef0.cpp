// from server: 56% by atomic.potato
struct ChangePropertyItem
{
    float GetValue();
};

float ChangePropertyItem::GetValue()
{
    return *(float*)this;
}

extern "C" float __cdecl Function004f9ef0(ChangePropertyItem* item)
{
    return item->GetValue();
}
