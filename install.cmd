@echo off
setlocal
cd /d "%~dp0"
title RoConstruct setup

rem RoConstruct needs Python 3.12 (3.13 removed msilib, used to unpack the compilers).
py -3.12 -c "import sys" >nul 2>nul
if errorlevel 1 (
  echo Python 3.12 not found. Installing it with winget...
  where winget >nul 2>nul || (
    echo winget is missing. Install "App Installer" from the Microsoft Store, or Python 3.12 from python.org, then run this again.
    pause & exit /b 1
  )
  winget install --id Python.Python.3.12 -e --scope user --accept-package-agreements --accept-source-agreements
  py -3.12 -c "import sys" >nul 2>nul || (
    echo.
    echo Python was installed. Close this window and double-click install.cmd again.
    pause & exit /b 0
  )
)

echo Installing Python packages...
py -3.12 -m pip install --user -q --disable-pip-version-check pefile capstone || (
  echo pip failed. Check your internet connection and run this again.
  pause & exit /b 1
)

py -3.12 roc.py install
if errorlevel 1 (
  echo.
  echo Some downloads did not finish. Run install.cmd again: it picks up where it stopped.
  pause & exit /b 1
)
echo.
echo Done! Go to the RoConstruct website and click "Start helping" on any client to run the worker.
echo The client downloads automatically when you click - you don't need to add any exe yourself.
echo.
echo   https://colingsnyder2-ux.github.io/RoConstruct/index.html
echo.
choice /c YN /m "Start work now (opens the website)"
if errorlevel 2 goto done
start "" "https://colingsnyder2-ux.github.io/RoConstruct/index.html"
:done
