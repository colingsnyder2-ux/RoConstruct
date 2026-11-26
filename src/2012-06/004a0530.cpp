// from server: 100% by Xemicl
// copied from an identical function in another client (function ?fn_ROCX000003_00463f10@CScriptEditor@ns_ROCX000003@@QAEXXZ)

namespace ns_ROCX000003 {
struct Control {
    int fn_ROCX000003_00460120(int direct);
    int fn_ROCX000003_00460c10(int position, int direct);
    void fn_ROCX000003_00460400(int position, int anchor, int direct);
};

struct CScriptEditor {
    int* fn_ROCX000003_004613d0();
    void fn_ROCX000003_00463f10();
};

void CScriptEditor::fn_ROCX000003_00463f10()
{
    Control* control = reinterpret_cast<Control*>(fn_ROCX000003_004613d0());
    int position = control->fn_ROCX000003_00460120(1);
    position = control->fn_ROCX000003_00460c10(position, 1);
    control->fn_ROCX000003_00460400(position, 0, 1);
}
}
