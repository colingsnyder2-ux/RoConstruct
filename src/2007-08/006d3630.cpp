// from server: 100% by colin
struct CXTPReportRow_Batch {
    int GetCount();
    int FindRow(int row);
    int Find(int row);
};

int CXTPReportRow_Batch::Find(int row)
{
    int count = GetCount();
    int i = 0;
    if (count > 0) {
        do {
            if (FindRow(i) == row)
                return i;
            ++i;
        } while (i < count);
    }
    return -1;
}
