################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJ_SRCS += \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/acceleration.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/alarm.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/altitude.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/battery.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/bluerobin.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/clock.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/date.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/eggtimer.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/menu.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/rfbsl.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/rfsimpliciti.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/showmsg.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/stopwatch.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/temperature.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/test.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/user.obj \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/worldtime.obj 

OPT_SRCS += \
../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/ccsSrcs.opt 

OBJ_SRCS_QUOTED += \
"../915MHz - Limited CCS Core Edition/logic/acceleration.obj" \
"../915MHz - Limited CCS Core Edition/logic/alarm.obj" \
"../915MHz - Limited CCS Core Edition/logic/altitude.obj" \
"../915MHz - Limited CCS Core Edition/logic/battery.obj" \
"../915MHz - Limited CCS Core Edition/logic/bluerobin.obj" \
"../915MHz - Limited CCS Core Edition/logic/clock.obj" \
"../915MHz - Limited CCS Core Edition/logic/date.obj" \
"../915MHz - Limited CCS Core Edition/logic/eggtimer.obj" \
"../915MHz - Limited CCS Core Edition/logic/menu.obj" \
"../915MHz - Limited CCS Core Edition/logic/rfbsl.obj" \
"../915MHz - Limited CCS Core Edition/logic/rfsimpliciti.obj" \
"../915MHz - Limited CCS Core Edition/logic/showmsg.obj" \
"../915MHz - Limited CCS Core Edition/logic/stopwatch.obj" \
"../915MHz - Limited CCS Core Edition/logic/temperature.obj" \
"../915MHz - Limited CCS Core Edition/logic/test.obj" \
"../915MHz - Limited CCS Core Edition/logic/user.obj" \
"../915MHz - Limited CCS Core Edition/logic/worldtime.obj" 

OPT_SRCS_QUOTED += \
"../915MHz - Limited CCS Core Edition/logic/ccsSrcs.opt" 


# Each subdirectory must supply rules for building sources it contributes
915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/bluerobin.out: ../915MHz\ -\ Limited\ CCS\ Core\ Edition/logic/bluerobin.obj $(OBJS)
	@echo 'Building file: $<'
	@echo 'Invoking: Linker'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal -z -m"ez430_chronos.map" --stack_size=80 --heap_size=80 --use_hw_mpy=F5 --warn_sections -i"C:/Program Files/Texas Instruments/ccsv4/msp430/include" -i"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/lib" -i"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --reread_libs --rom_model -o "$@" "$<" "../lnk_cc430f6137.cmd" $(ORDERED_OBJS)
	@echo 'Finished building: $<'
	@echo ' '


