@echo off
setlocal
cd /d "%~dp0"
title RoConstruct - ChatGPT plan
py -3.12 -c "import sys" >nul 2>nul
if errorlevel 1 (
  echo Installing Python 3.12 for RoConstruct...
  winget install --id Python.Python.3.12 -e --scope user --accept-package-agreements --accept-source-agreements
  py -3.12 -c "import sys" >nul 2>nul
  if errorlevel 1 (
    echo Close this window and run setup-chatgpt.cmd again after Python finishes installing.
    pause
    exit /b 1
  )
)
echo Installing ChatGPT sign-in support...
py -3.12 -m pip install --user --disable-pip-version-check -r requirements-chatgpt.txt pefile capstone tzdata
if errorlevel 1 exit /b 1
py -3.12 roc.py chatgpt login
if errorlevel 1 (
  pause
  exit /b 1
)
echo.
echo ChatGPT plan connected. Installing RoConstruct's compiler tools next.
call install.cmd
