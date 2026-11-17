@echo off
:: Scientific Calculator Local Server Launcher
:: Double-click this file to start the Python local server and open the browser
title Scientific Calculator Local Server
cd /d "%~dp0"

echo ========================================================
echo   Scientific Calculator - Local Web Server
echo ========================================================
echo.
echo Starting local server on http://localhost:8080 ...
echo Press Ctrl+C in this terminal when you want to stop the server.
echo.

set "PY_PATH=%LOCALAPPDATA%\Programs\Python\Python313\python.exe"

if exist "%PY_PATH%" (
    start http://localhost:8080
    "%PY_PATH%" -m http.server 8080
    goto end
)

where python >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    start http://localhost:8080
    python -m http.server 8080
    goto end
)

echo [WARNING] Python executable not found in PATH or standard location.
echo Opening index.html directly in your default browser...
start "" "index.html"

:end
pause
