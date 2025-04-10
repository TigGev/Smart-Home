CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra - g
INCLUDE = -Include

GTEST_FLAGS =  -lgtest -lgtest_main -pthread

BUILD_DIR = BUILD_DIR

TARGET = smart_home_sim

TEST_TARGET = run_tests

SOURCES = $(wildcard src/*.cpp src/devices/*.cpp src/hub/*.cpp src/behavior/*.cpp src/logger/*.cpp)

OBJECTS = $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))


TEST_SOURCES = $(wildcard tests/*.cpp)

TEST_OBJECTS = $(patsubst test/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SOURCES)) $(filter -out $(BUILD_DIR)/main.o, $(OBJECTS))

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(BUILD_DIR)/devices $(BUILD_DIR)/hub $(BUILD_DIR)/behavior $(BUILD_DIR)/logger

$(TARGET): $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

test: $(BUILD_DIR) $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(TEST_OBJECTS) $(GTEST_FLAGS) -o $(TEST_TARGET)

$(BUILD_DIR)/%.o: tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)