"""First-run state works without pre-existing local folders."""
import json

from roc import match, worker


def test_first_score_write_creates_client_directory(tmp_path, monkeypatch):
    monkeypatch.setattr(match, "ROOT", tmp_path)
    assert match.save_score("2008-06", "00401000", 90) == 90
    assert match.save_score("2008-06", "00401000", 80) == 90
    assert json.loads((tmp_path / "work/2008-06/scores.json").read_text()) == {"00401000": 90}


def test_settings_create_missing_parent_on_save_and_clear(tmp_path, monkeypatch):
    path = tmp_path / "local/config/settings.json"
    monkeypatch.setattr(worker, "SETTINGS", path)
    worker.clear_setting("worker_family_id")
    assert json.loads(path.read_text()) == {}
    worker.save_settings(user="tester", worker_family_id="family")
    worker.clear_setting("worker_family_id")
    assert json.loads(path.read_text()) == {"user": "tester"}
