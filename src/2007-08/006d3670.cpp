// from server: 100% by colin
// roc 2007-08 006d3670  unit: CXTPReportRow_Batch  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d3670

struct CXTPReportRow_Batch {
    int sub_6D3600(int index);
    void sub_6D26B0(int index, int flag);
    int sub_47B540();
    void FindRow(int row);
};

void CXTPReportRow_Batch::FindRow(int row) {
    int count = sub_47B540();
    int i = 0;
    if (count > 0) {
        do {
            if (sub_6D3600(i) == row) {
                ((CXTPReportRow_Batch *)((char *)this + 0x24))->sub_6D26B0(i, 1);
                break;
            }
            ++i;
        } while (i < count);
    }
}
