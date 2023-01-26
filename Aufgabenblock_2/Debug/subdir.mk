################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Fahrausnahme.cpp \
../Fahren.cpp \
../Fahrrad.cpp \
../Fahrzeug.cpp \
../Kreuzung.cpp \
../Losfahren.cpp \
../PKW.cpp \
../Parken.cpp \
../SimuClient.cpp \
../SimuClientSocket.cpp \
../Simulationsobjekt.cpp \
../Streckenende.cpp \
../Verhalten.cpp \
../Weg.cpp \
../main.cpp 

CPP_DEPS += \
./Fahrausnahme.d \
./Fahren.d \
./Fahrrad.d \
./Fahrzeug.d \
./Kreuzung.d \
./Losfahren.d \
./PKW.d \
./Parken.d \
./SimuClient.d \
./SimuClientSocket.d \
./Simulationsobjekt.d \
./Streckenende.d \
./Verhalten.d \
./Weg.d \
./main.d 

OBJS += \
./Fahrausnahme.o \
./Fahren.o \
./Fahrrad.o \
./Fahrzeug.o \
./Kreuzung.o \
./Losfahren.o \
./PKW.o \
./Parken.o \
./SimuClient.o \
./SimuClientSocket.o \
./Simulationsobjekt.o \
./Streckenende.o \
./Verhalten.o \
./Weg.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I/Users/aliihsangungoren/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Fahrausnahme.d ./Fahrausnahme.o ./Fahren.d ./Fahren.o ./Fahrrad.d ./Fahrrad.o ./Fahrzeug.d ./Fahrzeug.o ./Kreuzung.d ./Kreuzung.o ./Losfahren.d ./Losfahren.o ./PKW.d ./PKW.o ./Parken.d ./Parken.o ./SimuClient.d ./SimuClient.o ./SimuClientSocket.d ./SimuClientSocket.o ./Simulationsobjekt.d ./Simulationsobjekt.o ./Streckenende.d ./Streckenende.o ./Verhalten.d ./Verhalten.o ./Weg.d ./Weg.o ./main.d ./main.o

.PHONY: clean--2e-

