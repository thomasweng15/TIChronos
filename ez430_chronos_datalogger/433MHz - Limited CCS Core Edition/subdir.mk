################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

CMD_SRCS += \
../lnk_cc430f6137.cmd 

OBJS += \
./main.obj 

C_DEPS += \
./main.pp 

OBJS__QTD += \
".\main.obj" 

C_DEPS__QTD += \
".\main.pp" 

C_SRCS_QUOTED += \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_LF --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/driver" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/logic" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/bluerobin" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/simpliciti" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


