#pragma once

class MyString
{
public:
	// стандартный конструктор
	MyString()
	{
		this->string = nullptr;
		this->length = -1;
	}

	// кастомный конструктор
	MyString(const char* input)
	{
		this->length = -1;

		// проходим по массиву до '\0', чтобы получить его длину
		int i = 0;
		char current = ' ';
		while (current != '\0')
		{
			current = input[i];
			this->length++;
			i++;
		}

		this->string = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->string[i] = input[i];
		}

		this->string[length] = '\0'; // '\0' - конец строки
	}

	// деструктор
	~MyString() 
	{
		delete[] this->string; // обезательная очистка динамически выделенной памяти
	}

	// конструктор копирования
	MyString(const MyString& other)
	{
		this->length = other.length;
		this->string = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->string[i] = other.string[i];
		}

		this->string[this->length] = '\0';
	}

	// перегрузка оператора "="
	MyString& operator=(const MyString &other)
	{
		// если строка не пустая, то почистим её
		if (this->string != nullptr)
		{
			delete[] this->string;
		}

		this->length = other.length;
		this->string = new char[this->length + 1];
		for (int i = 0; i < this->length; i++)
		{
			this->string[i] = other.string[i];
		}

		this->string[this->length] = '\0';

		return *this;
	}

	// перегрузка оператора "*"
	MyString& operator+(MyString& other)
	{
		MyString new_string;

		new_string.length = this->length + other.length;
		new_string.string = new char[new_string.length + 1];

		int i = 0;
		for (; i < this->length; i++)
		{
			new_string.string[i] = this->string[i];
		}
		for (int j = 0; j < other.length; j++, i++)
		{
			new_string.string[i] = other.string[j];
		}
		new_string.string[new_string.length] = '\0';
		other = new_string;

		return other; // непонятно почему на этом шаге запускался деструктор для new_string 0_0
	}

	// перегрузка для cout << 
	friend std::ostream& operator<<(std::ostream& os, const MyString& string)
	{
		return os << string.string;
	}

private:
	char *string; // массив char эл-ов, значение строки
	int length; // длина строки
};