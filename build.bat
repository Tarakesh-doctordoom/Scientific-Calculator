@echo off
echo ========================================================
echo Building Scientific Calculator Application in C++
echo ========================================================

where g++ >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Compiling with g++...
    g++ -std=c++17 main.cpp CalculatorApp.cpp ScientificCalculator.cpp InputValidator.cpp -o ScientificCalculator.exe
    if %ERRORLEVEL% EQU 0 (
        echo [SUCCESS] Build completed successfully: ScientificCalculator.exe
        goto done
    ) else (
        echo [ERROR] Compilation failed.
        goto done
    )
)

where clang++ >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Compiling with clang++...
    clang++ -std=c++17 main.cpp CalculatorApp.cpp ScientificCalculator.cpp InputValidator.cpp -o ScientificCalculator.exe
    if %ERRORLEVEL% EQU 0 (
        echo [SUCCESS] Build completed successfully: ScientificCalculator.exe
        goto done
    ) else (
        echo [ERROR] Compilation failed.
        goto done
    )
)

where cl >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Compiling with MSVC cl.exe...
    cl /EHsc /std:c++17 main.cpp CalculatorApp.cpp ScientificCalculator.cpp InputValidator.cpp /Fe:ScientificCalculator.exe
    if %ERRORLEVEL% EQU 0 (
        echo [SUCCESS] Build completed successfully: ScientificCalculator.exe
        goto done
    ) else (
        echo [ERROR] Compilation failed.
        goto done
    )
)

echo [WARNING] No standard C++ compiler found in PATH (g++, clang++, or cl.exe).
echo Please install MinGW-w64, Visual Studio, or Clang and add it to your PATH.

:done
pause
