
RM := rm -rf

# All of the sources participating in the build are defined here
LIBS := -lglut -lGL -lGLU -lncurses -lpcan -lpthread


# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../_cube.cpp \
../display.cpp \
../main.cpp 

OBJS += \
./_cube.o \
./display.o \
./main.o 

CPP_DEPS += \
./_cube.d \
./display.d \
./main.d 


# All Target
all: RubikCubeTactileVisualization

# Tool invocations
RubikCubeTactileVisualization: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o"RubikCubeTactileVisualization" $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS) RubikCubeTactileVisualization
	-@echo ' '

