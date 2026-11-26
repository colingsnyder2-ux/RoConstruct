// from server: 100% by Xemicl
// roc 2012-06 00426950  unit: CRBXHTMLControlSite::XDocHostUIHandler  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00426950
//
// 00426950  8b442404             mov eax, dword ptr [esp + 4]
// 00426954  8b8834ffffff         mov ecx, dword ptr [eax - 0xcc]
// 0042695a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042695e  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00426961  8b11                 mov edx, dword ptr [ecx]
// 00426963  8b92d0010000         mov edx, dword ptr [edx + 0x1d0]
// 00426969  50                   push eax
// 0042696a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042696e  50                   push eax
// 0042696f  ffd2                 call edx
// 00426971  c20c00               ret 0xc
// copied from an identical function in another client (function ?FilterDataObject@XDocHostUIHandler@CRBXHTMLControlSite@@UAGJPAUIDataObject@@PAPAU3@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef long HRESULT;
struct IDataObject;
class CHtmlView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual HRESULT OnFilterDataObject(IDataObject* pDataObject, IDataObject** ppDataObject);
};
class CWnd;
class COleControlContainer { public: char pad[0x20]; CWnd* m_pWnd; };
class CRBXHTMLControlSite {
public:
    void* vptr_;
    COleControlContainer* m_pCtrlCont;
    char pad[0xd0 - 8];
    CHtmlView* GetView() const { return (CHtmlView*)m_pCtrlCont->m_pWnd; }
    struct XDocHostUIHandler {
        void* vtbl;
        virtual HRESULT __stdcall FilterDataObject(IDataObject* pDO, IDataObject** ppDORet);
    } m_xDocHostUIHandler;
};
HRESULT __stdcall CRBXHTMLControlSite::XDocHostUIHandler::FilterDataObject(IDataObject* pDO, IDataObject** ppDORet)
{
    CRBXHTMLControlSite* pThis = (CRBXHTMLControlSite*)((char*)this - (int)&((CRBXHTMLControlSite*)0)->m_xDocHostUIHandler);
    CHtmlView* pView = pThis->GetView();
    return pView->OnFilterDataObject(pDO, ppDORet);
}