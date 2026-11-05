// from server: 100% by colin
struct XTP_REPORTRECORDITEM_METRICS
{
    char pad[0x28];
    void* field_28;
    void* find(int index);
};

extern "C" int __fastcall sub_653870(void* p);
extern "C" void* __stdcall sub_699220(int index);

void* XTP_REPORTRECORDITEM_METRICS::find(int index)
{
    int count = sub_653870(field_28);
    int i = 0;
    if (count > 0)
    {
        do
        {
            void* item = sub_699220(i);
            if (*(int*)((char*)item + 0x24) == index)
                return item;
            i++;
        } while (i < sub_653870(field_28));
    }
    return 0;
}
