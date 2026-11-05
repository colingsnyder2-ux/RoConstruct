from roc import draft

def test_prompt_for_includes_remill_evidence():
    addr = "004690f0"
    row = {"size": 503, "unit": "RBX::DxUserInput"}
    asm = ["004690f0  push -1"]
    marker = "REMILL-REGRESSION-MARKER"
    prompt = draft.prompt_for(
        "2008-06", addr, row, asm, None, None, facts={"calls": 1, "branch_count": 1},
        remill_evidence=marker)
    assert marker in prompt
    assert "Remill verified LLVM semantic packet" in prompt
