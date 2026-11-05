// from server: 60% by Intel




struct CXTPPropertyGridInplaceEdit {
    int* m_pArray;
    int m_nCount;
    void IterateAndCall();
    void FinalCall(int, int);
};

extern "C" void __cdecl sub_98268a(int);
extern "C" void __cdecl sub_9823c0();
extern "C" void __stdcall sub_998260(CXTPPropertyGridInplaceEdit*, int, int);

void CXTPPropertyGridInplaceEdit::IterateAndCall() {
    int count = m_nCount;
    int index = 0;
    if (count > 0) {
        do {
            if (index < 0 || index >= count) {
                sub_9823c0();
            }
            int element = m_pArray[index];
            sub_98268a(element);
            count = m_nCount;
            ++index;
        } while (index < count);
    }
    FinalCall(-1, 0);
}

void CXTPPropertyGridInplaceEdit::FinalCall(int a, int b) {
    sub_998260(this, a, b);
}
