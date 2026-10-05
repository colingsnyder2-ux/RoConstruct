#!/usr/bin/env python3
"""RoConstruct desktop control panel. Tkinter stdlib; no GUI dependency."""
import json
import hashlib
import queue
import subprocess
import sys
import threading
import tkinter as tk
import os
import urllib.request
from pathlib import Path
from tkinter import filedialog, messagebox, scrolledtext, simpledialog, ttk

def find_root():
    start = Path(sys.executable).resolve().parent if getattr(sys, "frozen", False) else Path(__file__).resolve()
    for parent in (start, *start.parents):
        if (parent / "scripts" / "re" / "rebuild.py").exists():
            return parent
    return Path(__file__).resolve().parents[1]


ROOT = find_root()
SERVICE = ROOT / "scripts" / "roconstruct"
TOKEN = os.environ.get("ROCONSTRUCT_TOKEN", "")
PROJECT = os.environ.get("ROCONSTRUCT_PROJECT", "default")
DATA_ROOT = Path(os.environ.get("ROCONSTRUCT_DATA_ROOT", str(ROOT / "work" / "re"))).resolve()
SETTINGS = ROOT / "roconstruct-settings.json"
DIRECTORY_URL = os.environ.get("ROCONSTRUCT_DIRECTORY_URL", "")


class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("RoConstruct // distributed lab")
        self.geometry("760x520")
        self.minsize(700, 460)
        self.configure(bg="#0b1020")
        style = ttk.Style(self)
        style.theme_use("clam")
        style.configure("TFrame", background="#0b1020")
        style.configure("TLabel", background="#0b1020", foreground="#c9d7ff")
        style.configure("Title.TLabel", foreground="#61f4ff", font=("Segoe UI", 18, "bold"))
        style.configure("Sub.TLabel", foreground="#8391b8", font=("Segoe UI", 9))
        style.configure("TButton", background="#182448", foreground="#d9e2ff", padding=(8, 5), borderwidth=0)
        style.map("TButton", background=[("active", "#25407a")], foreground=[("active", "#7dfff1")])
        style.configure("TLabelframe", background="#0b1020", foreground="#61f4ff")
        style.configure("TLabelframe.Label", background="#0b1020", foreground="#61f4ff")
        self.events = queue.Queue()
        self.proc = None
        self.worker_proc = None
        self.demo_proc = None
        self.settings = self.load_settings()
        self.data_root = Path(self.settings.get("data_root", str(DATA_ROOT))).resolve()
        self.db_path = Path(self.settings.get("db_path", str(self.data_root / "rbx2008m.db"))).resolve()
        self.client_path = Path(self.settings.get("client_path", str(self.data_root / "bin" / "RobloxApp_client.exe"))).resolve()
        self.server_name = self.settings.get("server_name", "RoConstruct 2008M")
        self.server_description = self.settings.get("server_description", "Shared reconstruction jobs")
        self.client_label = self.settings.get("client_label", "2008M")
        self.build()
        self.poll()
        self.after(2000, self.auto_refresh)

    def load_settings(self):
        try:
            return json.loads(SETTINGS.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return {}

    def save_settings(self):
        self.data_root = self.db_path.parent
        SETTINGS.write_text(json.dumps({"data_root": str(self.data_root), "db_path": str(self.db_path),
                                        "client_path": str(self.client_path), "server_name": self.server_name,
                                        "server_description": self.server_description, "client_label": self.client_label},
                                       indent=2), encoding="utf-8")

    def build(self):
        top = ttk.Frame(self, padding=(16, 12, 16, 4)); top.pack(fill="x")
        ttk.Label(top, text="ROCONSTRUCT", style="Title.TLabel").pack(anchor="w")
        ttk.Label(top, text="Distributed source reconstruction lab  //  keep client files local", style="Sub.TLabel").pack(anchor="w")
        actions = ttk.LabelFrame(self, text="CONTROL", padding=8); actions.pack(fill="x", padx=16, pady=8)
        for text, fn in (("1  Setup", self.setup), ("2  Check data", self.check_data), ("3  Start server", self.start),
                         ("4  Start worker", self.start_worker), ("5  Add jobs", self.seed), ("Demo", self.run_demo),
                         ("New client...", self.new_client), ("Public list", self.public_list), ("↻  Refresh", self.refresh), ("■  Stop", self.stop)):
            ttk.Button(actions, text=text, command=fn).pack(side="left", padx=(0, 5))
        self.status = tk.StringVar(value="OFFLINE  // click Check data")
        ttk.Label(actions, textvariable=self.status, style="Sub.TLabel").pack(side="right", padx=4)
        details = ttk.LabelFrame(self, text="SERVER CARD + LOCAL FILES", padding=7); details.pack(fill="x", padx=16, pady=(0, 8))
        self.server_name_var = tk.StringVar(value=self.server_name)
        self.server_desc_var = tk.StringVar(value=self.server_description)
        self.client_label_var = tk.StringVar(value=self.client_label)
        ttk.Label(details, text="Name").grid(row=0, column=0, sticky="w")
        ttk.Entry(details, textvariable=self.server_name_var, width=24).grid(row=0, column=1, padx=5, sticky="ew")
        ttk.Label(details, text="Description").grid(row=0, column=2, sticky="w")
        ttk.Entry(details, textvariable=self.server_desc_var, width=32).grid(row=0, column=3, padx=5, sticky="ew")
        ttk.Label(details, text="Client").grid(row=1, column=0, sticky="w", pady=(5, 0))
        ttk.Entry(details, textvariable=self.client_label_var, width=24).grid(row=1, column=1, padx=5, pady=(5, 0), sticky="ew")
        ttk.Button(details, text="Select DB...", command=self.select_db).grid(row=1, column=2, padx=5, pady=(5, 0), sticky="w")
        ttk.Button(details, text="Select client...", command=self.select_client).grid(row=1, column=3, padx=5, pady=(5, 0), sticky="w")
        self.paths = tk.StringVar()
        ttk.Label(details, textvariable=self.paths, style="Sub.TLabel").grid(row=2, column=0, columnspan=4, sticky="w", pady=(5, 0))
        details.columnconfigure(1, weight=1); details.columnconfigure(3, weight=2)
        self.update_paths()
        info = ttk.LabelFrame(self, text="QUICK GUIDE", padding=8); info.pack(fill="x", padx=16)
        ttk.Label(info, justify="left", text="Select DB + client → Check data → Start server → Add jobs → Start worker.\nNew client... guides 2008M/2010L setup. Files stay on this PC; server publishes name/description only.").pack(anchor="w")
        box = ttk.LabelFrame(self, text="LIVE FEED", padding=6); box.pack(fill="both", expand=True, padx=16, pady=8)
        self.log = scrolledtext.ScrolledText(box, state="disabled", bg="#070b16", fg="#7dfff1", insertbackground="#7dfff1", relief="flat", font=("Cascadia Mono", 8), height=12)
        self.log.pack(fill="both", expand=True)

    def write(self, text):
        self.log.configure(state="normal"); self.log.insert("end", text + "\n"); self.log.see("end"); self.log.configure(state="disabled")

    def start(self):
        if self.proc and self.proc.poll() is None: return
        try:
            self.server_name = self.server_name_var.get().strip() or "RoConstruct server"
            self.server_description = self.server_desc_var.get().strip()
            self.client_label = self.client_label_var.get().strip() or "2008M"
            self.save_settings()
            args = [*self.launcher(), str(SERVICE / "coordinator.py"), "--db", str(ROOT / "coordinator.db"), "--project", PROJECT,
                    "--name", self.server_name, "--description", self.server_description, "--client", self.client_label]
            if TOKEN: args += ["--token", TOKEN]
            self.proc = self.spawn(args)
            threading.Thread(target=self.read, daemon=True).start(); self.status.set("Coordinator running on http://127.0.0.1:8765")
        except Exception as error:
            messagebox.showerror("Coordinator", str(error))

    def setup(self):
        try:
            sys.path.insert(0, str(ROOT / "scripts" / "re"))
            import bootstrap
            bootstrap.install()
            self.write("setup complete; restart app if Python/MSVC was added")
        except Exception as error:
            messagebox.showerror("Setup", str(error))

    def check_data(self):
        db = self.db_path
        client = self.client_path
        self.write("DATA ROOT: %s" % self.data_root)
        self.write("2008 DB: %s" % ("READY" if db.exists() else "MISSING  (run summarize.py ingest)"))
        self.write("2008 client: %s" % ("READY" if client.exists() else "MISSING  (place authorized EXE in data\\bin)"))
        self.status.set("DATA READY" if db.exists() and client.exists() else "DATA INCOMPLETE")

    def update_paths(self):
        self.paths.set("DB: %s   |   client: %s" % (self.db_path.name, self.client_path.name))

    def select_db(self):
        path = filedialog.askopenfilename(title="Select 2008 SQLite database", filetypes=[("SQLite DB", "*.db"), ("All files", "*.*")])
        if path:
            self.db_path = Path(path).resolve(); self.data_root = self.db_path.parent; self.save_settings(); self.update_paths(); self.check_data()

    def select_client(self):
        path = filedialog.askopenfilename(title="Select authorized 2008 client", filetypes=[("Windows client", "*.exe"), ("All files", "*.*")])
        if path:
            self.client_path = Path(path).resolve(); self.save_settings(); self.update_paths(); self.check_data()

    def new_client(self):
        label = simpledialog.askstring("New client", "Client label (example: 2010L):", initialvalue=self.client_label_var.get())
        if not label:
            return
        self.client_label_var.set(label.strip())
        self.select_client()
        self.write("CLIENT PROFILE: %s" % label.strip())
        self.write("Next: create matching Ghidra export + SQLite DB, then select that DB. Existing worker can process it.")
        self.write("Use an authorized client only. RoConstruct never uploads the executable.")

    def spawn(self, args):
        env = os.environ.copy(); env["ROCONSTRUCT_DATA_ROOT"] = str(self.data_root)
        flags = getattr(subprocess, "CREATE_NO_WINDOW", 0)
        return subprocess.Popen(args, cwd=ROOT, env=env, creationflags=flags,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)

    def launcher(self):
        if not getattr(sys, "frozen", False): return [sys.executable]
        import shutil
        for name in ("py", "python"):
            if shutil.which(name): return [name]
        raise RuntimeError("Python missing; run first-run setup")

    def start_worker(self):
        if self.worker_proc and self.worker_proc.poll() is None: return
        try:
            if not self.db_path.exists():
                self.write("Worker blocked: select valid DB first")
                return
            self.worker_proc = self.spawn([*self.launcher(), str(SERVICE / "worker.py"), "--root", str(ROOT),
                                           "--db", str(self.db_path), "--client-label", self.client_label_var.get(),
                                           "--project", PROJECT, "--token", TOKEN])
            threading.Thread(target=self.read_worker, daemon=True).start()
            self.status.set("Worker running")
        except Exception as error: messagebox.showerror("Worker", str(error))

    def run_demo(self):
        if self.demo_proc and self.demo_proc.poll() is None:
            return
        try:
            self.demo_proc = self.spawn([*self.launcher(), str(SERVICE / "demo.py")])
            threading.Thread(target=self.read_demo, daemon=True).start()
            self.write("DEMO started: safe non-Roblox pipeline")
        except Exception as error:
            messagebox.showerror("Demo", str(error))

    def read_demo(self):
        for line in self.demo_proc.stdout:
            self.events.put("demo: " + line.rstrip())

    def read_worker(self):
        for line in self.worker_proc.stdout: self.events.put("worker: " + line.rstrip())

    def seed(self):
        db = self.db_path
        binary = self.client_path
        if not db.exists() or not binary.exists():
            self.write("Seed needs local Ghidra DB + client binary")
            return
        digest = hashlib.sha256()
        with binary.open("rb") as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b""): digest.update(chunk)
        import sqlite3
        with sqlite3.connect(db) as conn:
            rows = conn.execute("SELECT program,addr FROM scope WHERE in_scope=1 ORDER BY indeg DESC LIMIT 200").fetchall()
        payload = {"jobs": [{"binary_hash": digest.hexdigest(), "program": p, "address": a} for p, a in rows]}
        request = urllib.request.Request("http://127.0.0.1:8765/v1/jobs/seed", json.dumps(payload).encode(),
                                         {"Content-Type": "application/json", "X-Worker-Token": TOKEN,
                                          "X-RoConstruct-Project": PROJECT})
        try:
            with urllib.request.urlopen(request, timeout=5) as response:
                result = json.load(response)
                added = result.get("added", 0)
                self.write("JOBS: added %s new; existing jobs kept (0 means already seeded)." % added)
        except Exception as error: self.write("seed unavailable: %s" % error)

    def read(self):
        for line in self.proc.stdout: self.events.put(line.rstrip())

    def stop(self):
        if self.proc and self.proc.poll() is None: self.proc.terminate()
        if self.worker_proc and self.worker_proc.poll() is None: self.worker_proc.terminate()
        if self.demo_proc and self.demo_proc.poll() is None: self.demo_proc.terminate()
        self.status.set("Coordinator stopped")

    def refresh(self):
        self.refresh_status(True)

    def refresh_status(self, silent=False):
        try:
            request = urllib.request.Request("http://127.0.0.1:8765/v1/status", headers={
                "X-Worker-Token": TOKEN, "X-RoConstruct-Project": PROJECT})
            with urllib.request.urlopen(request, timeout=2) as response:
                data = json.load(response)
                jobs = data.get("jobs", {})
                workers = data.get("workers", [])
                active = sum(1 for item in workers if item.get("meta", {}).get("state") == "working")
                phase = "WORKING" if active else ("IDLE" if not jobs.get("queued", 0) else "WAITING")
                self.status.set("%s  // workers %s  // queue %s  // done %s" %
                                (phase, data.get("workers_online", 0), jobs.get("queued", 0), jobs.get("done", 0)))
                if not silent: self.write(json.dumps(data, indent=2))
        except Exception as error:
            if not silent: self.write("status unavailable: %s" % error)

    def auto_refresh(self):
        self.refresh_status(True)
        self.after(2000, self.auto_refresh)

    def public_list(self):
        if not DIRECTORY_URL:
            self.write("public list disabled; set ROCONSTRUCT_DIRECTORY_URL to metadata directory")
            return
        try:
            with urllib.request.urlopen(DIRECTORY_URL.rstrip("/") + "/v1/servers", timeout=5) as response:
                self.write(json.dumps(json.load(response), indent=2))
        except Exception as error:
            self.write("public list unavailable: %s" % error)

    def poll(self):
        try:
            while True: self.write(self.events.get_nowait())
        except queue.Empty: pass
        self.after(150, self.poll)


if __name__ == "__main__":
    App().mainloop()
