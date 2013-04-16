################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
../driver/ez430_chronos_datalogger_drivers.lib 

C_SRCS += \
../driver/ports.c \
../driver/radio.c \
../driver/rf1a.c 

OBJS += \
./driver/ports.obj \
./driver/radio.obj \
./driver/rf1a.obj 

C_DEPS += \
./driver/ports.pp \
./driver/radio.pp \
./driver/rf1a.pp 

OBJS__QTD += \
".\driver\ports.obj" \
".\driver\radio.obj" \
".\driver\rf1a.obj" 

C_DEPS__QTD += \
".\driver\ports.pp" \
".\driver\radio.pp" \
".\driver\rf1a.pp" 

C_SRCS_QUOTED += \
"../driver/ports.c" \
"../driver/radio.c" \
"../driver/rf1a.c" 


# Each subdirectory must supply rules for building sources it contributes
driver/ports.obj: ../driver/ports.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_LF --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/driver" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/logic" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/bluerobin" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/simpliciti" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/ports.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

driver/radio.obj: ../driver/radio.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_LF --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/driver" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/logic" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/bluerobin" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/simpliciti" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/radio.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

driver/rf1a.obj: ../driver/rf1a.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_LF --include_path="C:/Program Files/Texas Instruments/ccsv4/msp430/include" --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/driver" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/include" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/logic" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/bluerobin" --include_path="C:/Users/thomas/Development/TI/ez430_chronos_datalogger/simpliciti" --diag_warning=225 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/rf1a.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


