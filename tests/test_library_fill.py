import threading
import time
from types import SimpleNamespace

from benchmarks import claude_continuation as continuation
from benchmarks.library_fill import assert_lines


def test_assert_repair_requires_source_assert_and_only_line_push_difference():
    lines = ["int unrelated;", 'alwaysAssertM(ok, "reason");']
    assert assert_lines(b"\x68\x03\0\0\0\xc3", [], b"\x68\x02\0\0\0\xc3", [], lines) == {2: 3}
    assert assert_lines(b"\x68\x03\0\0\0\xc3", [], b"\x68\x01\0\0\0\xc3", [], lines) is None
    assert assert_lines(b"\x69\x03\0\0\0\xc3", [], b"\x68\x02\0\0\0\xc3", [], lines) is None
    assert assert_lines(b"\x68\x03\0\0\0\xc2", [], b"\x68\x02\0\0\0\xc3", [], lines) is None
    assert assert_lines(b"\x68\x03\0\0\0\xc3", [1], b"\x68\x02\0\0\0\xc3", [1], lines) is None


def test_compile_prefetch_preserves_serial_comparison_and_journaling(monkeypatch):
    main = threading.get_ident()
    lock = threading.Lock()
    active = peak = 0
    seen = []

    def compile_text(client, source):
        nonlocal active, peak
        with lock:
            active += 1
            peak = max(peak, active)
        time.sleep(.02)
        with lock:
            active -= 1
        return source.encode()

    class Target:
        def match_obj(self, obj, source):
            assert threading.get_ident() == main
            assert obj == source.encode()
            seen.append(source)
            return {}

    class Campaign:
        api = SimpleNamespace(call=lambda *args, **kwargs: [])

        def previous(self, stage):
            return []

        def record(self, stage, row):
            assert threading.get_ident() == main

    monkeypatch.setattr(continuation.match, "compile_text", compile_text)
    monkeypatch.setattr(continuation, "target_for", lambda scores: Target())
    continuation.run_sources(Campaign(), "test", [(str(i), i) for i in range(9)], jobs=3)
    assert seen == [str(i) for i in range(9)]
    assert 2 <= peak <= 3
