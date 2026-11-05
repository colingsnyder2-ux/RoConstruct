import pytest


@pytest.fixture(autouse=True)
def isolated_function_history(monkeypatch, tmp_path):
    from roc import telemetry
    monkeypatch.setattr(telemetry, "ACTIVITY_PATH", tmp_path / "function-history.sqlite")
