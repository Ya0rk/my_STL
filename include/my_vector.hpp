#pragma once
#include <cstddef>

namespace my {
template <typename T>
class vector {
  public:
    vector();                     // 默认构造函数
    explicit vector(size_t size); // 指定大小的构造函数
    ~vector();                    // 析构函数

    void push_back(const T &value);
    T &operator[](size_t index);
    size_t size() const;
    size_t capacity() const;

  private:
    T *m_data = nullptr;
    size_t m_size = 0;     // 数组大小
    size_t m_capacity = 0; // 数组容量

    void resize(size_t new_capacity);
};
} // namespace my
