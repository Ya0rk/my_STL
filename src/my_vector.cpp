#include "../include/my_vector.hpp"
#include <algorithm>

namespace my {
template <typename T>
vector<T>::vector() = default;

template <typename T>
vector<T>::vector(size_t size) : m_data(new T[size]), m_size(size), m_capacity(size) {}

template <typename T>
vector<T>::~vector() {
    delete[] m_data;
}

template <typename T>
void vector<T>::push_back(const T &value) {
    // 如果容量不高需要扩展容量
    // 扩展算法是 *2
    if(m_size >= m_capacity) {
        resize(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = value;
}

template <typename T>
T &vector<T>::operator[](size_t index) {
    return m_data[index];
}

// 获取数组大小
template <typename T>
size_t vector<T>::size() const {
    return m_size;
}

// 获取数组容量
template <typename T>
size_t vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
void vector<T>::resize(size_t new_capacity) {
    T *new_data = new T[new_capacity];
    // 将数据拷贝到新数组位置，释放原来数组
    std::copy(m_data, m_data + m_size, new_data);
    delete[] m_data;
    m_data = new_data;
    m_capacity = new_capacity;
}

// 显式实例化常用类型
template class vector<int>;
template class vector<float>;
} // namespace my
