
#include <iostream>

using namespace std;

class MyClass
{
private:
	static int s_counter;

	int* m_counter{&s_counter};

public:
	MyClass()
	{
		++(*m_counter);
		std::cout << "Constructing: " << GetCounter() << std::endl;
	}

	~MyClass()
	{
		--(*m_counter);
		m_counter = nullptr;

		std::cout << "Destructing: " << s_counter << std::endl;
	}

	MyClass(const MyClass& rhs)
		: m_counter(rhs.m_counter)
	{
		++(*m_counter);
		cout << "Copying: " << GetCounter() << std::endl;
	}

	int GetCounter()
	{
		return *m_counter;
	}
};

int MyClass::s_counter{0};


MyClass CopyMyClass(MyClass par)
{
	return par;
}

int main()
{
	MyClass c1;
	//std::cout << c1.GetCounter() << std::endl;
	{
		MyClass c2;
		//std::cout << c2.GetCounter() << std::endl;
	}

	auto c3 = MyClass{};
	//std::cout << c3.GetCounter() << std::endl;

	auto c4 = CopyMyClass(c3);
	//std::cout << c4.GetCounter() << std::endl;
	
	cin.get();
	return 0;
}
