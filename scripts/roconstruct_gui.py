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
        self.package_proc = None
        self.settings = self.load_settings()
        self.data_root = Path(self.settings.get("data_root", str(DATA_ROOT))).resolve()
        self.db_path = Path(self.settings.get("db_path", str(self.data_root / "rbx2008m.db"))).resolve()
        self.client_path = Path(self.settings.get("client_path", str(self.data_root / "bin" / "RobloxApp_client.exe"))).resolve()
        self.server_name = self.settings.get("server_name", "RoConstruct 2008M")
        self.server_description = self.settings.get("server_description", "Shared reconstruction jobs")
        self.client_label = self.settings.get("client_label", "2008M")
        self.demo_done = 0
        self.demo_total = 0
        self.server_name_var = tk.StringVar(value=self.server_name)
        self.server_desc_var = tk.StringVar(value=self.server_description)
        self.client_label_var = tk.StringVar(value=self.client_label)
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
        top = ttk.Frame(self, padding=(24, 20, 24, 8)); top.pack(fill="x")
        ttk.Label(top, text="ROCONSTRUCT", style="Title.TLabel").pack(anchor="w")
        ttk.Label(top, text="Simple launcher for client setup, server, worker, and demo.", style="Sub.TLabel").pack(anchor="w")
        actions = ttk.LabelFrame(self, text="START HERE", padding=12); actions.pack(fill="x", padx=24, pady=10)
        for text, fn in (("Client setup", self.open_client_panel), ("Server", self.open_server_panel),
                         ("Worker", self.open_worker_panel), ("Run demo", self.run_demo)):
            ttk.Button(actions, text=text, command=fn, width=18).pack(side="left", padx=(0, 8), ipady=8)
        self.status = tk.StringVar(value="Ready  // choose Client setup or Run demo")
        ttk.Label(self, textvariable=self.status, style="Sub.TLabel").pack(anchor="w", padx=26)
        self.progress = ttk.Progressbar(self, mode="determinate", maximum=1, value=0)
        self.progress.pack(fill="x", padx=24, pady=(0, 12))
        info = ttk.LabelFrame(self, text="HOW IT WORKS", padding=12); info.pack(fill="x", padx=24)
        ttk.Label(info, justify="left", text="Client setup = choose local DB + client.\nServer = queue jobs. Worker = process jobs. Run demo = safe test with no client files.\nPrivate files stay on this PC.").pack(anchor="w")
        box = ttk.LabelFrame(self, text="ACTIVITY", padding=8); box.pack(fill="both", expand=True, padx=24, pady=12)
        self.log = scrolledtext.ScrolledText(box, state="disabled", bg="#070b16", fg="#7dfff1", insertbackground="#7dfff1", relief="flat", font=("Cascadia Mono", 8), height=12)
        self.log.pack(fill="both", expand=True)

    def panel(self, title, size="520x300"):
        window = tk.Toplevel(self)
        window.title("RoConstruct // " + title)
        window.geometry(size)
        window.configure(bg="#0b1020")
        ttk.Label(window, text=title.upper(), style="Title.TLabel").pack(anchor="w", padx=18, pady=(16, 8))
        return window

    def open_client_panel(self):
        window = self.panel("Client setup", "620x300")
        box = ttk.LabelFrame(window, text="LOCAL FILES", padding=12); box.pack(fill="x", padx=18, pady=8)
        ttk.Label(box, text="Client label").grid(row=0, column=0, sticky="w")
        ttk.Entry(box, textvariable=self.client_label_var, width=28).grid(row=0, column=1, padx=8, sticky="w")
        ttk.Button(box, text="Select SQLite DB...", command=self.select_db).grid(row=1, column=0, pady=8, sticky="w")
        ttk.Button(box, text="Select client EXE...", command=self.select_client).grid(row=1, column=1, pady=8, sticky="w")
        self.paths = tk.StringVar(); ttk.Label(box, textvariable=self.paths, style="Sub.TLabel").grid(row=2, column=0, columnspan=2, sticky="w")
        self.update_paths()
        ttk.Button(window, text="Check files", command=self.check_data).pack(anchor="w", padx=18, pady=8)
        ttk.Label(window, text="For new client: enter label (example 2010L), select its DB + EXE.", style="Sub.TLabel").pack(anchor="w", padx=18)

    def open_server_panel(self):
        window = self.panel("Server", "620x360")
        box = ttk.LabelFrame(window, text="SERVER CARD", padding=12); box.pack(fill="x", padx=18, pady=8)
        for row, label, variable in ((0, "Name", self.server_name_var), (1, "Description", self.server_desc_var)):
            ttk.Label(box, text=label).grid(row=row, column=0, sticky="w", pady=4)
            ttk.Entry(box, textvariable=variable, width=52).grid(row=row, column=1, padx=8, sticky="ew")
        box.columnconfigure(1, weight=1)
        controls = ttk.Frame(window); controls.pack(fill="x", padx=18, pady=8)
        for text, fn in (("Start server", self.start), ("Add jobs", self.seed), ("Refresh", self.refresh), ("Stop", self.stop)):
            ttk.Button(controls, text=text, command=fn).pack(side="left", padx=(0, 8), ipady=5)
        ttk.Label(window, text="Server stores job metadata/results only. Client files stay local.", style="Sub.TLabel").pack(anchor="w", padx=18)

    def open_worker_panel(self):
        window = self.panel("Worker", "520x240")
        ttk.Label(window, text="Worker processes selected DB functions on this PC.").pack(anchor="w", padx=18, pady=8)
        ttk.Label(window, text="DB: %s" % self.db_path.name, style="Sub.TLabel").pack(anchor="w", padx=18)
        controls = ttk.Frame(window); controls.pack(fill="x", padx=18, pady=12)
        ttk.Button(controls, text="Start worker", command=self.start_worker).pack(side="left", padx=(0, 8), ipady=5)
        ttk.Button(controls, text="Stop", command=self.stop).pack(side="left", ipady=5)
        ttk.Label(window, text="Progress appears in main Activity window.", style="Sub.TLabel").pack(anchor="w", padx=18)

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
            self.demo_done = 0; self.demo_total = 3; self.progress.configure(maximum=3, value=0)
            self.status.set("DEMO  //  0/3")
            self.demo_proc = self.spawn([*self.launcher(), str(SERVICE / "demo.py")])
            threading.Thread(target=self.read_demo, daemon=True).start()
            self.write("DEMO started: safe non-Roblox pipeline")
        except Exception as error:
            messagebox.showerror("Demo", str(error))

    def read_demo(self):
        for line in self.demo_proc.stdout:
            self.events.put("demo: " + line.rstrip())

    def build_sandbox(self):
        if self.package_proc and self.package_proc.poll() is None:
            return
        try:
            self.package_proc = self.spawn([*self.launcher(), str(SERVICE / "package.py")])
            threading.Thread(target=self.read_package, daemon=True).start()
            self.write("SANDBOX started: checking source + open-source dependencies")
        except Exception as error:
            messagebox.showerror("Sandbox", str(error))

    def read_package(self):
        for line in self.package_proc.stdout:
            self.events.put("sandbox: " + line.rstrip())

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
        if self.package_proc and self.package_proc.poll() is None: self.package_proc.terminate()
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
                total = sum(jobs.values())
                self.progress.configure(maximum=max(total, 1), value=jobs.get("done", 0))
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
            while True:
                line = self.events.get_nowait()
                self.write(line)
                if "demo: DEMO //" in line and "// OK" in line:
                    self.demo_done += 1
                    self.progress.configure(value=self.demo_done)
                    self.status.set("DEMO  //  %s/%s" % (self.demo_done, self.demo_total))
                elif "demo: demo // complete" in line.lower():
                    self.progress.configure(value=self.demo_total)
                    self.status.set("DEMO COMPLETE")
        except queue.Empty: pass
        self.after(150, self.poll)


if __name__ == "__main__":
    App().mainloop()
