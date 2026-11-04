import json
from pathlib import Path

import pytest

from roc import integration


@pytest.mark.parametrize("winerror", [5, 32, 33])
def test_atomic_json_retries_windows_reader_lock(tmp_path, monkeypatch, winerror):
    target = tmp_path / "journal.json"
    target.write_text('{"old": true}')
    replace = Path.replace
    attempts = []
    sleeps = []

    def locked(source, destination):
        attempts.append(source)
        if len(attempts) < 3:
            assert json.loads(target.read_text()) == {"old": True}
            error = PermissionError("reader lock")
            error.winerror = winerror
            raise error
        return replace(source, destination)

    monkeypatch.setattr(Path, "replace", locked)
    monkeypatch.setattr(integration.time, "sleep", sleeps.append)
    integration.atomic_json(target, {"new": True})
    assert json.loads(target.read_text()) == {"new": True}
    assert len(set(attempts)) == 1
    assert sleeps == [0.025, 0.05]
    assert not list(tmp_path.glob("*.tmp"))


@pytest.mark.parametrize("winerror,expected_attempts", [(5, 8), (None, 1)])
def test_atomic_json_preserves_journal_on_persistent_error(tmp_path, monkeypatch, winerror, expected_attempts):
    target = tmp_path / "journal.json"
    target.write_text('{"old": true}')
    attempts = []

    def denied(source, destination):
        attempts.append(source)
        error = PermissionError("denied")
        if winerror is not None:
            error.winerror = winerror
        raise error

    monkeypatch.setattr(Path, "replace", denied)
    monkeypatch.setattr(integration.time, "sleep", lambda _: None)
    with pytest.raises(PermissionError):
        integration.atomic_json(target, {"new": True})
    assert len(attempts) == expected_attempts
    assert json.loads(target.read_text()) == {"old": True}
    assert json.loads(attempts[0].read_text()) == {"new": True}
