"""Client-isolated Discord digests and explicit LLM submission credit."""
from unittest.mock import Mock

import pytest

from roc import reports, server, worker


@pytest.mark.parametrize("automatic", [False, True])
def test_mixed_clients_send_separate_messages(monkeypatch, automatic):
    store = Mock()
    store.display_progress.side_effect = lambda client: (8, 10, 80, 100) if client == "2008-06" else (2, 20, 20, 200)
    store.digest_progress.return_value = (20, 20, 40, 100)
    store.match_rate.return_value = 1 / 3600
    store.user_points.return_value = 100
    sent = []

    class ImmediateThread:
        def __init__(self, target, args, daemon):
            self.target, self.args = target, args

        def start(self):
            self.target(*self.args)

    monkeypatch.setattr(reports.threading, "Thread", ImmediateThread)
    monkeypatch.setattr(reports, "_post", lambda url, payload: sent.append(payload))
    log = reports.MineLog("unused", store, server=automatic)
    events = [dict(job=dict(client=client, addr=addr, unit="unit", size=10), user=user,
                   worker=user, model=model, score=score, points=10)
              for client, addr, user, model, score in [
                  ("2008-06", "00800001", "colin", "gpt-6.1-sol", 100),
                  ("2012-06", "01200001", "intel", "claude-opus", 80),
                  ("2008-06", "00800002", "intel", "claude-opus", 75)]]
    log._send(events)
    assert len(sent) == 2
    first, second = [payload["embeds"][0] for payload in sent]
    assert "2008-06 Client" in first["description"] and "8 / 10 matched" in first["description"]
    assert "2012-06 Client" in second["description"] and "2 / 20 matched" in second["description"]
    assert "00800001" in str(first) and "00800002" in str(first) and "01200001" not in str(first)
    assert "01200001" in str(second) and "008000" not in str(second) and "colin" not in str(second)
    assert first["fields"][-1]["name"] == ("🔧 Functions" if automatic else "🔧 Models")
    assert "gpt-6.1-sol" in str(first) and "gpt-6.1-sol" not in str(second)
    assert "negative_squared_cross_mark" not in str(sent) and "❎" not in str(sent)
    assert ":yellow_square:" in first["description"] and "🟨 partial" in first["description"]
    assert first["fields"][1]["name"] == "🟡 Partially Matched"
    assert "🟡" in first["fields"][1]["value"]
    assert store.match_rate.call_args_list[0].args == ("2008-06", 7200)
    assert store.match_rate.call_args_list[1].args == ("2012-06", 7200)
    with pytest.raises(ValueError, match="one client"):
        log.digest(events)


def test_rate_includes_one_hour_old_gain_but_not_three_hours(monkeypatch):
    store = server.Store(":memory:", 1)
    monkeypatch.setattr(server.time, "time", lambda: 20000)
    try:
        store.db.executemany("INSERT INTO events VALUES(?,?,?,?,?,?)", [
            (16400, "2008-06", "a", "user", 50, 100),
            (9200, "2008-06", "b", "user", 0, 100),
            (19000, "2008-06", "c", "user", 0, 70),
            (19000, "2012-06", "d", "user", 0, 100)])
        assert store.match_rate("2008-06", reports.RATE_WINDOW) * 3600 == 0.5
    finally:
        store.db.close()


@pytest.mark.parametrize("explicit,environment,expected", [
    ("gpt-6.1-sol", "claude-opus", "gpt-6.1-sol"),
    (None, "claude-opus", "claude-opus"), (None, "", "Unknown model")])
def test_manual_submit_credits_actual_model(tmp_path, monkeypatch, explicit, environment, expected):
    source = tmp_path / "00401000.cpp"
    source.write_text("void f() {}")
    submitted = []

    class Api:
        def __init__(self, *args):
            pass

        def call(self, path, payload=None, **kwargs):
            if path.startswith("/v1/sources?"):
                return []
            submitted.append(payload)
            return dict(stored=100, improved=True, verified=True)

    monkeypatch.setenv("ROC_AGENT_MODEL", environment)
    monkeypatch.delenv("ROC_AGENT", raising=False)
    monkeypatch.setattr(worker, "Api", Api)
    monkeypatch.setattr(worker.match, "check", lambda *args: (100, None, None, None))
    logs = []
    worker.submit_files("unused", "colin", "2008-06", [source.stem], file=source, model=explicit, log=logs.append)
    assert submitted[0]["model"] == expected
    assert submitted[0]["client"] == "2008-06"
    assert "Player Mining credit" in logs[0]
    assert not hasattr(reports, "publish_yesterday")
