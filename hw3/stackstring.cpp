#include <cstdlib>
#include <stdexcept>
#include "stackstring.h"

StackString::StackString(){}

StackString::~StackString()
{
	list_.clear();
}

bool StackString::empty() const
{
	return list_.size() == 0;
}

size_t StackString::size() const
{
	return list_.size();
}

void StackString::push(const std::string& val)
{
	list_.push_front(val);
}

const std::string& StackString::top() const
{
	if(empty()) 
		throw std::logic_error ("stack is empty");
	return list_.get(0);
}

void StackString::pop()
{
	if(empty()) return;
	list_.pop_front();
}