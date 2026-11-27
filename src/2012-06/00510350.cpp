// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Mgr
{
    virtual void v0(void *);
    virtual void v1(void *);
    virtual void v2(void *);
    virtual void v3(void *);
    virtual void v4(void *);
    virtual void v5(void *);
    virtual void v6(void *);
    virtual void v7(void *);
    virtual void v8(void *);
    virtual void v9(void *);
    virtual void v10(void *);
    virtual void v11(void *);
    virtual void v12(void *);
    virtual void v13(void *);
    virtual void v14(void *);
    virtual void v15(void *);
    virtual void v16(void *);
    virtual void v17(void *);
    virtual void v18(void *);
    virtual void v19(void *);
    virtual void v20(void *);
    virtual void v21(void *);
    virtual void v22(void *);
    virtual void v23(void *);
    virtual void v24(void *);
    virtual void v25(void *);
    virtual void v26(void *);
    virtual void v27(void *);
    virtual void v28(void *);
    virtual void v29(void *);
    virtual void v30(void *);
    virtual void v31(void *);
    virtual void v32(void *);
    virtual void v33(void *);
    virtual void v34(void *);
    virtual void v35(void *);
    virtual void v36(void *);
    virtual void v37(void *);
    virtual void v38(void *);
    virtual void v39(void *);
    virtual void v40(void *);
    virtual void v41(void *);
    virtual void v42(void *);
    virtual void v43(void *);
    virtual void v44(void *);
    virtual void v45(void *);
    virtual void v46(void *);
    virtual void v47(void *);
    virtual void v48(void *);
    virtual void v49(void *);
    virtual void v50(void *);
    virtual void v51(void *);
    virtual void v52(void *);
    virtual void v53(void *);
    virtual void v54(void *);
    virtual void v55(void *);
    virtual void v56(void *);
    virtual void v57(void *);
    virtual void v58(void *);
    virtual void v59(void *);
    virtual void v60(void *);
    virtual void v61(void *);
    virtual void v62(void *);
    virtual void v63(void *);
    virtual void v64(void *);
    virtual void v65(void *);
    virtual void v66(void *);
    virtual void v67(void *);
    virtual void v68(void *);
    virtual void v69(void *);
    virtual void v70(void *);
    virtual void v71(void *);
    virtual void v72(void *);
    virtual void v73(void *);
    virtual void v74(void *);
    virtual void v75(void *);
    virtual void v76(void *);
    virtual void v77(void *);
    virtual void v78(void *);
    virtual void v79(void *);
    virtual void v80(void *);
    virtual void v81(void *);
    virtual void v82(void *);
    virtual void v83(void *);
    virtual void v84(void *);
    virtual void v85(void *);
    virtual void v86(void *);
    virtual void v87(void *);
    virtual void v88(void *);
    virtual void v89(void *);
    virtual void v90(void *);
    virtual void v91(void *);
    virtual void v92(void *);
    virtual void v93(void *);
    virtual void v94(void *);
    virtual void v95(void *);
    virtual void v96(void *);
};
struct Rec { void *a, *b, *c; int d, e; };
struct Node
{
    char pad[0x60];
    Mgr *mgr;
    void f(Rec *r);
};
void Node::f(Rec *r)
{
    if (r->a)
    {
        if (mgr)
        {
            mgr->v96(r->b);
            mgr->v96(r->c);
            mgr->v84(r->a);
        }
        r->a = 0; r->b = 0; r->c = 0; r->d = 0; r->e = 0;
    }
}