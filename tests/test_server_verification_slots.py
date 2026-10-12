import json
import threading
import time
import urllib.error
import urllib.request
from concurrent.futures import ThreadPoolExecutor
from http.server import ThreadingHTTPServer

import pytest
from unittest.mock import Mock, patch

from roc import server, worker


class Store:
    def best(self, *_):
        return {"score": 99}

    def submit(self, *_args, **_kwargs):
        return 99, False


@pytest.fixture
def server_url():
    httpd = ThreadingHTTPServer(("127.0.0.1", 0), server.make_handler(Store(), None, {"2008-06"}))
    httpd.daemon_threads = True
    threading.Thread(target=httpd.serve_forever, daemon=True).start()
    try:
        yield "http://127.0.0.1:%d" % httpd.server_port
    finally:
        httpd.shutdown()
        httpd.server_close()


def request(url, path, body=None, timeout=3):
    data = None if body is None else json.dumps(body).encode()
    req = urllib.request.Request(url + path, data=data)
    try:
        with urllib.request.urlopen(req, timeout=timeout) as response:
            return response.status, json.loads(response.read())
    except urllib.error.HTTPError as error:
        return error.code, json.loads(error.read())


def submit_body(addr="00401000"):
    return {"client": "2008-06", "addr": addr, "source": "int f(){return 0;}", "user": "pilot", "score": 100}


def test_verification_slots_bound_submit_and_batch_and_keep_info_live(server_url):
    started, finish = threading.Event(), threading.Event()
    lock = threading.Lock()
    active = maximum = 0

    def slow_compile(*_):
        nonlocal active, maximum
        with lock:
            active += 1
            maximum = max(maximum, active)
            if active == 3:
                started.set()
        assert finish.wait(5)
        with lock:
            active -= 1
        return 100, None, None, []

    with patch("roc.server.match.check_text", side_effect=slow_compile), \
         patch("roc.server.check_many_text") as batch:
        with ThreadPoolExecutor(max_workers=3) as pool:
            futures = [pool.submit(request, server_url, "/v1/submit", submit_body()) for _ in range(3)]
            assert started.wait(3)
            status, info = request(server_url, "/v1/info")
            assert status == 200 and "2008-06" in info["verify"]

            started_at = time.monotonic()
            status, result = request(server_url, "/v1/submit", submit_body(), timeout=2)
            assert status == 503 and "verification queue busy" in result["error"]
            assert time.monotonic() - started_at < 1
            status, result = request(server_url, "/v1/submit-batch", {
                "client": "2008-06", "addrs": ["00401000"], "source": "int f(){return 0;}", "user": "pilot"
            })
            assert status == 503 and "verification queue busy" in result["error"]
            batch.assert_not_called()
            assert maximum == 3
            finish.set()
            assert all(f.result(timeout=3)[0] == 200 for f in futures)


def test_verification_permit_released_after_compile_failure(server_url):
    with patch("roc.server.match.check_text", side_effect=[
        server.match.CompileError("bad source"), (100, None, None, [])
    ]) as compile_text:
        status, result = request(server_url, "/v1/submit", submit_body())
        assert status == 400 and "does not compile" in result["error"]
        status, result = request(server_url, "/v1/submit", submit_body("00401001"))
        assert status == 200 and result["verified"]
    assert compile_text.call_count == 2


def test_submit_retries_admission_rejection_without_cluster_probe():
    api = worker.Api("http://127.0.0.1:8765")
    connection = Mock()
    busy = Mock(status=503)
    busy.read.return_value = b'{"error":"verification queue busy; retry shortly"}'
    success = Mock(status=200)
    success.read.return_value = b'{"stored":100,"verified":true}'
    connection.getresponse.side_effect = [busy, success]
    with patch.object(api, "_get_conn", return_value=connection), patch.object(worker.time, "sleep") as sleep:
        assert api.call("/v1/submit", submit_body())["stored"] == 100
    assert [call.args[1] for call in connection.request.call_args_list] == ["/v1/submit", "/v1/submit"]
    sleep.assert_called_once_with(1)


def test_network_failure_after_admission_retry_is_not_replayed():
    api = worker.Api("http://127.0.0.1:8765")
    connection = Mock()
    busy = Mock(status=503)
    busy.read.return_value = b'{"error":"verification queue busy; retry shortly"}'
    connection.getresponse.return_value = busy
    connection.request.side_effect = [None, OSError("connection lost")]
    with patch.object(api, "_get_conn", return_value=connection), patch.object(worker.time, "sleep"):
        with pytest.raises(worker.ApiFailure, match="offline"):
            api.call("/v1/submit", submit_body())
    assert connection.request.call_count == 2
