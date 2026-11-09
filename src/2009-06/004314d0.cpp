// from server: 100% by EspClaude
// roc 2009-06 004314d0  unit: RBX::VBrickColor::?$XItem  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004314d0
//
// 004314d0  56                   push esi
// 004314d1  57                   push edi
// 004314d2  8d44240c             lea eax, [esp + 0xc]
// 004314d6  8bf1                 mov esi, ecx
// 004314d8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004314dc  50                   push eax
// 004314dd  e8de152100           call 0x642ac0
// 004314e2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004314e6  0fb64c240e           movzx ecx, byte ptr [esp + 0xe]
// 004314eb  8b16                 mov edx, dword ptr [esi]
// 004314ed  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 004314f3  c1e108               shl ecx, 8
// 004314f6  0fb6fc               movzx edi, ah
// 004314f9  0bcf                 or ecx, edi
// 004314fb  0fb6c0               movzx eax, al
// 004314fe  c1e108               shl ecx, 8
// 00431501  0bc8                 or ecx, eax
// 00431503  51                   push ecx
// 00431504  8bce                 mov ecx, esi
// 00431506  ffd2                 call edx
// 00431508  5f                   pop edi
// 00431509  5e                   pop esi
// 0043150a  c20400               ret 4
// copied from an identical function in another client (function ?apply@Item@ns_ROCX000000@@QAEXPAUColor@2@@Z)

namespace ns_ROCX000000 {
struct Color {
    void convert(unsigned long* output);
};

struct Item {
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7();
    virtual void v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15();
    virtual void v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23();
    virtual void v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31();
    virtual void v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47();
    virtual void v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55();
    virtual void v56();
    virtual void setColor(unsigned long value);
    void apply(Color* color);
};

void Item::apply(Color* color)
{
    color->convert(reinterpret_cast<unsigned long*>(&color));
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&color);
    setColor((((unsigned long)bytes[2] << 8) | bytes[1]) << 8 | bytes[0]);
}
}
