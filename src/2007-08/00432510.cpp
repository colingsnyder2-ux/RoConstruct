// from server: 100% by colin
struct CDataModelPropGrid {
    char pad[0xe0];
    unsigned char m_flag;
    int helper(bool value);
    int wrapper();
};

int CDataModelPropGrid::wrapper() {
    return helper(m_flag == 0);
}
