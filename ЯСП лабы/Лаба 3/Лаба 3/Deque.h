#pragma once
#include <fstream>
#include <iostream>
//#include "Time.h"


template <typename T>
class Deque
{
private:

	const static size_t MAX_SIZE = 8;

	T* data;
	size_t head, tail;
	size_t capacity; // ������ ���������� ������
	size_t size; // ����������� ������

	// ���������� ���������� ������ � 2 ����
	void extend();

public:
	Deque(size_t allocate_size = MAX_SIZE);
	~Deque();

	void init_by_push_back(std::ifstream& file);
	void init_by_push_front(std::ifstream& file);

	// ���������� � �����
	void push_back(const T& value);
	// ���������� � ������
	void push_front(const T& value);

	// �������� �� �����
	T pop_back();
	// �������� �� ������
	T pop_front();

	// ��������� �������� �� ������
	T front();
	//��������� �������� �� �����
	T back();

	size_t get_size();

	// ������ ���� � �����
	void print(std::ostream& stream, char separator);

	// �������� ���� �� �������
	bool empty();

	void clear();

};

template<typename T>
inline Deque<T>::Deque(size_t allocate_size)
{
	capacity = allocate_size + 2;
	data = new T[capacity];
	tail = capacity / 2;
	head = tail - 1;
}

template<typename T>
inline Deque<T>::~Deque()
{
	size = 0;
	delete[] data;
	data = nullptr;
}

template<typename T>
inline void Deque<T>::extend()
{
	capacity *= 2;
	T* tmp = new T[capacity];
	int prev_head = head;
	head = capacity / 2 - size / 2;
	tail = head;
	for (int i = prev_head; i <= prev_head + size; ++i)
	{
		tmp[tail++] = data[i];
	}
	delete[] data;
	data = tmp;
}

template<typename T>
inline void Deque<T>::init_by_push_back(std::ifstream& file)
{
	clear();
	T value;
	while (file >> value)
		push_back(value);
}

template<typename T>
inline void Deque<T>::init_by_push_front(std::ifstream& file)
{
	clear();
	T value;
	while (file >> value)
		push_front(value);
}

template<typename T>
inline void Deque<T>::push_back(const T& value)
{
	if (tail >= capacity)
		extend();
	data[tail++] = value;
	++size;
}

template<typename T>
inline void Deque<T>::push_front(const T& value)
{
	if (head + 1 <= 1) // 0-� ������ ���������������
		extend();
	data[head--] = value;
	++size;
}

template<typename T>
inline bool Deque<T>::empty()
{
	return !size;
}

template<typename T>
inline void Deque<T>::clear()
{
	size = 0;
	capacity = MAX_SIZE + 2;
	data = new T[capacity];
	tail = capacity / 2;
	head = tail - 1;
}

template<typename T>
inline T Deque<T>::front()
{
	if (!size)
		throw std::out_of_range("������� ���������� �������� �� ������� ����!\n");
	return data[head + 1];
}

template<typename T>
inline T Deque<T>::back()
{
	if (!size)
		throw std::out_of_range("������� ���������� �������� �� ������� ����!\n");
	return data[tail - 1];
}

template<typename T>
inline size_t Deque<T>::get_size()
{
	return size;
}

template<typename T>
inline void Deque<T>::print(std::ostream& stream, char separator)
{
	if (size > 0)
		for (size_t i = head + 1; i < tail; ++i)
			stream << data[i] << separator;
	else
		stream << "��� ������!\n";
	if (separator == ' ')
		stream << '\n';
}

template<typename T>
inline T Deque<T>::pop_back()
{
	T result = back();
	--tail;
	--size;
	return result;
}

template<typename T>
inline T Deque<T>::pop_front()
{
	T result = front();
	++head;
	--size;
	return result;
}
