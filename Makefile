TARGET = main

OBJECTS := \
	Point.o \
	Segment.o \
	Triangle.o \
	RectangularTriangle.o \
	FiguresTests.o

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

CXX := g++ -std=c++17
IFLAGS := -I$(INCLUDE_DIR)
OFLAGS := -Ofast -march=native -flto -fomit-frame-pointer -s -DNDEBUG
WFLAGS := -Wall -Wextra
DFLAGS := -ggdb -fsanitize=address
CXXFLAGS := $(IFLAGS) $(OFLAGS) $(WFLAGS)

OBJECTS := $(addprefix $(BUILD_DIR)/, $(OBJECTS))
DEPENDS := $(patsubst %.o, %.d, $(OBJECTS))
DEPENDS += $(BUILD_DIR)/$(TARGET).d

.PHONY: clean distclean

all: $(TARGET)

-include $(DEPENDS)

$(TARGET): $(OBJECTS) $(BUILD_DIR)/$(TARGET).o
	$(CXX) $(CXXFLAGS) -MMD -MP $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
distclean: clean
	rm -f $(TARGET) arena
