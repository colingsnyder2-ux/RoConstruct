// from server: 100% by tester
class VCXTPReportRow
{
public:
    void __thiscall setValue(int);
};

void __thiscall VCXTPReportRow::setValue(int value)
{
    *(int *)((char *)this + 0xf6) = value;
}