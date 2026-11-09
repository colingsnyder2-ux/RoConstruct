// from server: 100% by Intel
class VCXTPReportRow
{
public:
    void __thiscall setValue(int);
};

void __thiscall VCXTPReportRow::setValue(int value)
{
    *(int *)((char *)this + 0xee) = value;
}
