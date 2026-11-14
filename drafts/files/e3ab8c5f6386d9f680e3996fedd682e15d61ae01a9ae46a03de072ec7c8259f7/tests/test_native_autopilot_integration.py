import importlib.util
from pathlib import Path


SCRIPT = Path(__file__).resolve().parents[1] / "rebuild/2008-06/tests/native_autopilot_integration.py"
SPEC = importlib.util.spec_from_file_location("native_autopilot_integration", SCRIPT)
MODULE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(MODULE)


def test_missing_result_stays_pending():
    result = MODULE.assess_gate_result(None)
    assert result["outcome"] == "pending_external_evidence"
    assert result["missing_gates"] == list(MODULE.REQUIRED_GATES)
    assert result["integration_started"] is False
    assert result["activation_allowed"] is False


def test_forged_pass_flags_do_not_clear_gate_blockers():
    evidence = {name: {"passed": True, "receipt": "made-up"} for name in MODULE.REQUIRED_GATES}
    result = MODULE.assess_gate_result({"accepted": True, "gates": MODULE._CURRENT_GATE_LABEL, **evidence})
    assert result["known_candidate_checks"] is True
    assert result["missing_gates"] == list(MODULE.REQUIRED_GATES)
    assert result["activation_allowed"] is False


def test_unrecognized_gate_summary_is_not_candidate_pass():
    result = MODULE.assess_gate_result({"accepted": True, "gates": "all passed"})
    assert result["known_candidate_checks"] is False
    assert result["outcome"] == "pending_external_evidence"
