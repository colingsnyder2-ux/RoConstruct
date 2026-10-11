"""Atomic local task files; Windows readers briefly block replacement."""
import time
import uuid
from pathlib import Path


def write_text(path, text):
    path = Path(path)
    temporary = path.with_name(path.name + "." + uuid.uuid4().hex + ".tmp")
    temporary.write_text(text, encoding="utf-8")
    try:
        for attempt in range(6):
            try:
                temporary.replace(path)
                return
            except PermissionError:
                if attempt == 5:
                    raise
                time.sleep(0.02)
    finally:
        temporary.unlink(missing_ok=True)
