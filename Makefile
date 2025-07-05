CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
TARGET := stl_test # 最终的可执行文件

# 自动获取所有源文件
TEST_SRCS := $(wildcard tests/*.cpp)
STL_SRCS := $(wildcard src/*.cpp)

# 生成对应的目标文件
TEST_OBJS := $(patsubst tests/%.cpp, build/tests/%.o, $(TEST_SRCS))
STL_OBJS := $(patsubst src/%.cpp, build/src/%.o, $(STL_SRCS))

# 获取所有测试目标名称（不带路径和扩展名）
TEST_TARGETS := $(basename $(notdir $(TEST_SRCS)))

.PHONY: all clean test $(TEST_TARGETS)

all: $(TARGET)

# 主可执行文件
$(TARGET): main.cpp $(STL_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# 编译STL实现
build/src/%.o: src/%.cpp include/%.hpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 通用测试编译规则
build/tests/%.o: tests/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 单个测试目标的构建规则
define TEST_RULE
$(1): build/tests/$(1).o $$(STL_OBJS)
	$$(CXX) $$(CXXFLAGS) $$^ -o build/tests/$(1).out
	@echo "Running $$@..."
	@./build/tests/$(1).out
endef

# 为每个测试生成独立目标
$(foreach test,$(TEST_TARGETS),$(eval $(call TEST_RULE,$(test))))

# 运行所有单元测试
test: $(TEST_TARGETS)

# 清理
clean:
	rm -rf build $(TARGET)

# 帮助信息
help:
	@echo "Available targets:"
	@echo "  all       - Build main executable (default)"
	@echo "  test      - Build and run ALL tests"
	@echo "  clean     - Remove build artifacts"
	@echo "  [testname] - Build and run specific test (available: $(TEST_TARGETS))"
