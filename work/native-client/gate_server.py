"""Gate server: resident native-bulk workers so each gate skips process start, imports and the target index load
(measured 7.6 s fresh vs 2.4 s warm per bulk run).  Same roc.native_bulk.run() code, same output folder and manifest,
so results are identical to `roc.cmd native-bulk`; clients fall back to the subprocess when the server is down.
Workers restart when any roc/*.py or the check runner changes (the bulk tool hash would differ anyway).
  python work/native-client/gate_server.py [--jobs 8] [--port 8799]
Client: native_creator_gate.bulk_run(config_path, out_dir)."""
import argparse
import json
import os
import sys
import threading
from concurrent.futures import ProcessPoolExecutor
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
WATCH = [*ROOT.glob('roc/*.py'), ROOT / 'rebuild/2008-06/tests/native_check_runner.py']


def stamp():
    return tuple(p.stat().st_mtime_ns for p in WATCH if p.is_file())


def _init():
    os.chdir(ROOT)
    sys.path.insert(0, str(ROOT))
    os.environ['ROC_JOBS'] = '1'            # one probe source per gate: no nested pools inside a worker
    os.environ['ROC_HARVEST_JOBS'] = '1'


def _job(config_path, out):
    from roc import native_bulk
    config = json.loads(Path(config_path).read_text(encoding='utf-8'))
    try:
        native_bulk.run(config, out)
        return {'ok': True}
    except Exception as error:              # noqa: BLE001 - reported to the client, which falls back
        return {'ok': False, 'error': repr(error)[-400:]}


class Pool:
    def __init__(self, jobs):
        self.jobs, self.lock, self.pool, self.stamp = jobs, threading.Lock(), None, None

    def submit(self, config_path, out):
        with self.lock:
            now = stamp()
            if self.pool is None or now != self.stamp:
                if self.pool:
                    self.pool.shutdown(wait=True)
                    print('tools changed: workers restarted', flush=True)
                self.pool, self.stamp = ProcessPoolExecutor(self.jobs, initializer=_init), now
            future = self.pool.submit(_job, config_path, out)
        return future.result()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--jobs', type=int, default=8)
    ap.add_argument('--port', type=int, default=int(os.environ.get('ROC_GATE_PORT', 8799)))
    args = ap.parse_args()
    pool = Pool(args.jobs)

    class Handler(BaseHTTPRequestHandler):
        def log_message(self, *a):
            pass

        def do_GET(self):
            self.send_response(200)
            self.end_headers()
            self.wfile.write(b'{"ok": true}')

        def do_POST(self):
            body = json.loads(self.rfile.read(int(self.headers['Content-Length'])))
            result = pool.submit(body['config'], body['out'])
            data = json.dumps(result).encode()
            self.send_response(200)
            self.send_header('Content-Length', str(len(data)))
            self.end_headers()
            self.wfile.write(data)

    server = ThreadingHTTPServer(('127.0.0.1', args.port), Handler)
    print('gate server on 127.0.0.1:%d with %d workers' % (args.port, args.jobs), flush=True)
    server.serve_forever()


if __name__ == '__main__':
    main()
