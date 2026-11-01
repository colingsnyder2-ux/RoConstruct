// from server: 100% by colin
struct CXTPReportRow_Batch_Inner {
    int pad[0x33];
    int value;
};

struct CXTPReportRow_Batch {
    int pad[9];
    CXTPReportRow_Batch_Inner* ptr24;
    int val28;
    bool IsSame();
};

bool CXTPReportRow_Batch::IsSame() {
    return ptr24->value == val28;
}
