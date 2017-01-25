#include "MathManager.h"

MathManager::MathManager(int size) : m_size(size), m_numbers()
{
}

void readNumbers()
{
	m_numbers.clear();
	std::cout << "Enter " << m_size << " numbers: " 
		<<std::endl;
	for(int i(0); i < m_size; i++)
	{
		int num(0);
		(std::cin >> num).get();
		m_numbers.push_back(num);

	}

}	

int max() const
{
	int max(INT_MIN);
	std::vector<int>::const_iterator it = m_number.begin();
	for(it;	it!= m_numbers.end(); it++)
	{
		if(*it > max)
			max = *it;

	}

	if(max == INT_MIN)
		max = 0;

	return max;
}

int sum() const
{
	int total(0);
	std::vector<int>::const_iterator it = m_number.begin();	

	for(it;	it!= m_numbers.end(); it++)
		total = total + *it;
	return total;
}

double average() const
{
	double ave(0.0);
	if(m_numbers.size() > 0)
		ave = this.sum()/m_numbers.size();
	return ave;
}
