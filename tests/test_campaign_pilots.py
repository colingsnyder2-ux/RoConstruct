import json

import pytest

from benchmarks.ai_representatives import PersistentBudget
from benchmarks.data_recovery import string_candidate
from benchmarks.real_neighborhoods import adapt
from roc.providers import ProviderError
from roc.template_recovery import instantiation


def test_budget_survives_restart_and_failed_requests(tmp_path):
    path = tmp_path / "budget.json"
    budget = PersistentBudget(path)
    ticket = budget.reserve(100, 1.0)
    restarted = PersistentBudget(path)
    with pytest.raises(ProviderError):
        restarted.reserve(100, 0.81)
    budget.settle(ticket, 80, 0.5)
    assert PersistentBudget(path).cost == 0.5
    ticket = budget.reserve(100, 0.5)
    budget.settle(ticket, 0, None)
    assert json.loads(path.read_text())["cost"] == 1.0
    budget.settle(ticket, 0, 0.0)
    assert json.loads(path.read_text())["cost"] == 1.0


def test_string_repair_preserves_external_names():
    assert string_candidate('return "old";', b"old\0", b"new\0") == 'return "new";'
    assert string_candidate('return "old";', b"old\0", b"\xff\0") is None
    assert string_candidate('extern char old[];', b"old\0", b"new\0") is None


def test_template_unknown_layout_still_rejected():
    assert "class Instance;" in instantiation("class boost::shared_ptr<class RBX::Instance>")
    with pytest.raises(ValueError):
        instantiation("class std::vector<class RBX::Instance>")


def test_named_callee_adapter_uses_actual_method():
    caller = "struct C { int sub_123(int value); int f(); };\nint C::f() { return sub_123(4); }"
    callee = "struct D { int actual(int value); };\nint D::actual(int value) { return value; }"
    source = adapt(caller, callee, "sub_123", "123")
    assert "->actual(a0)" in source
    assert "C::sub_123(int a0)" in source
