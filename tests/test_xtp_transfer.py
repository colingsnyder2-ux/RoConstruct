import threading
import time
from types import SimpleNamespace

from benchmarks import xtp_coverage_run as coverage


def test_parallel_clients_have_isolated_connections_and_serial_journal(monkeypatch):
    created = []
    main_thread = threading.get_ident()
    recorded = []

    class Api:
        def __init__(self, server, token):
            self.active = False
            self.closed = False
            created.append(self)

        def call(self):
            assert not self.active
            self.active = True
            time.sleep(0.002)
            self.active = False

        def close(self):
            self.closed = True

    class Campaign:
        api = SimpleNamespace(server="local", token=None)

        def submit_exact(self, stage, client, addr, source):
            self.api.call()
            return dict(client=client, addr=addr, score=100)

        def record(self, stage, row):
            assert threading.get_ident() == main_thread
            recorded.append(row)

    class Target:
        def match_obj(self, obj, source):
            return {"00401000": (source, "symbol", [])}

    monkeypatch.setattr(coverage.worker, "Api", Api)
    monkeypatch.setattr(coverage.match, "compile_text", lambda client, source: b"object")
    monkeypatch.setattr(coverage, "check_many_text", lambda client, addrs, source: [])
    clients = ["a", "b", "c"]
    sources = ["// roc-cl: 21022\n", "// roc-cl: 30729\n"]
    plans = [(client, source) for source in sources for client in clients]
    coverage.transfer_sources(Campaign(), plans, {c: Target() for c in clients}, set())
    assert len(recorded) == len(created) == 6
    assert all(api.closed for api in created)
    assert len({id(api) for api in created}) == 6
    assert all(len(row["winners"]) == 1 and "error" not in row for row in recorded)
