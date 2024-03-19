SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Program Files\Microsoft MPI\Bin\;C:\Program Files (x86)\IntelSWToolsMPI\compilers_and_libraries_2020.4.321\windows\mpi\intel64\bin;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\wapt;c:\Program Files\PuTTY\;C:\Program Files\Microsoft VS Code\bin;C:\Program Files\Git\cmd;C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Bin\;C:\Program Files\IVI Foundation\VISA\Win64\Bin\;C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Bin;C:\Program Files\MATLAB\MATLAB Runtime\v96\runtime\win64;%USERPROFILE%\AppData\Local\Microsoft\WindowsApps;;C:\intelFPGA_lite\20.1\modelsim_ase\win32aloem;C:\modeltech64_10.2a\win64
SET CPU_TYPE=LPC1768
SET CPU_VENDOR=NXP
SET UV2_TARGET=Open1786
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\output\startup_lpc17xx._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\system_lpc17xx.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\core_cm3.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_clkpwr.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_gpio.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_pinsel.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_timer.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_exti.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_nvic.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_ssp.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lpc17xx_i2c.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\ili_lcd_general.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\lcd_api.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\english_16x8.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\affichagelcd.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\touch_panel.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\gestion_i2c_1.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\gestion_timer.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\output\gestion_pinsel.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Output\Project.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Output\Project.axf" --i32combined --output ".\Output\Project.hex"
